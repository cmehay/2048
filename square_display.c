/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   square_display.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbethoua <sbethoua@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/28 11:14:05 by sbethoua          #+#    #+#             */
/*   Updated: 2015/02/28 16:51:33 by sbethoua         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "game_2048.h"

static int	square_get_color(t_game *game, int value)
{
	int	i;

	i = 0;
	while (i < NB_POWERS)
	{
		if (value == game->powers[i])
			exit(1);
		i++;
	}
	return (0);
}

static void	square_color(t_game *game, WINDOW *win, int value)
{
	init_pair((value % COLORS), COLOR_WHITE, square_get_color(game, value));
	wbkgd(win, COLOR_PAIR(value % COLORS));
}

void		square_display(t_game *game, t_size *size, int y, int x)
{
	int	v_align;
	int	h_align;

	v_align = (size->heigth / 2) - 1;
	h_align = ((size->width - (ft_intlen(game->game[y][x].val) / 2)) / 2) - 1;
	square_color(game, game->game[y][x].win, game->game[y][x].val);
	mvwprintw(game->game[y][x].win, v_align, h_align, "%d", game->game[y][x].val);
}
