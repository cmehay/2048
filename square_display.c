/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   square_display.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbethoua <sbethoua@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/28 11:14:05 by sbethoua          #+#    #+#             */
/*   Updated: 2015/02/28 20:26:56 by sbethoua         ###   ########.fr       */
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
			return (game->colors[i]);
		// DEBUG BEGIN
		ft_putnbr_fd(game->colors[i], output());
		ft_putchar_fd('-', output());
		ft_putnbr_fd(game->powers[i], output());
		ft_putchar_fd('\n', output());
		// DEBUG END
		i++;
	}
	return (1);
}

static void	square_color(t_game *game, WINDOW *win, int value)
{
	int	color_idx;

	if ((color_idx = square_get_color(game, value)))
		init_pair(color_idx, COLOR_WHITE, color_idx);
		wbkgd(win, COLOR_PAIR(color_idx));
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
