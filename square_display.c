/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   square_display.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbethoua <sbethoua@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/28 11:14:05 by sbethoua          #+#    #+#             */
/*   Updated: 2015/03/01 19:44:45 by sbethoua         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "game_2048.h"

static int	square_get_color(t_game *game, int value)
{
	int	i;

	i = 0;
	while (i < game->nb_powers)
	{
		if (value == game->powers[i])
			return (game->colors[i]);
		i++;
	}
	return (1);
}

static void	square_color(t_game *game, WINDOW *win, int value)
{
	int	color_idx;

	color_idx = square_get_color(game, value);
	init_pair(color_idx, COLOR_WHITE, color_idx);
	wbkgd(win, COLOR_PAIR(color_idx));
}

void		square_display(t_game *game, t_size *size, int y, int x)
{
	int	valign;
	int	halign;

	valign = (size->heigth / 2) - 1;
	halign = ((size->width - (ft_intlen(game->game[y][x].val) / 2)) / 2) - 1;
	square_color(game, game->game[y][x].win, game->game[y][x].val);
	mvwprintw(game->game[y][x].win, valign, halign, "%d", game->game[y][x].val);
}
