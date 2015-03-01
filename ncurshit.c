/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ncurshit.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmehay <cmehay@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/27 22:11:16 by cmehay            #+#    #+#             */
/*   Updated: 2015/03/01 15:39:19 by sbethoua         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "game_2048.h"

static void	get_square_size(t_size *size, t_game *game)
{
	size->heigth = (LINES - 1) / game->game_mode;
	size->width = (COLS) / game->game_mode;
}

static void	square_del(WINDOW *square)
{
	wborder(square, ' ', ' ', ' ',' ',' ',' ',' ',' ');
	wrefresh(square);
	delwin(square);
}

static void	square_draw(t_game *game, t_size *size, int y, int x)
{
	int	pos_y;
	int	pos_x;

	pos_y = size->heigth * y;
	pos_x = size->width * x;
	square_del(game->game[y][x].win);
	game->game[y][x].win = newwin(size->heigth, size->width, pos_y, pos_x);
	box(game->game[y][x].win, 0 , 0);
	if (game->game[y][x].val)
	{
		if (game->game[y][x].merged)
			wattron(game->game[y][x].win, A_BOLD);
		square_display(game, size, y, x);
	}
	wrefresh(game->game[y][x].win);
}

void		win_draw(t_game *game)
{
	t_size	size;
	int		y;
	int		x;

	if (LINES < G_MIN_HEIGHT || COLS < G_MIN_WIDTH)
		return (game_size_too_small_display());
	get_square_size(&size, game);
	y = game->game_mode;
	while (y--)
	{
		x = game->game_mode;
		while (x--)
			square_draw(game, &size, y, x);
	}
	game_score_display(game);
}
