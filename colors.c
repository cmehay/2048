/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   colors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbethoua <sbethoua@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/28 16:04:54 by sbethoua          #+#    #+#             */
/*   Updated: 2015/02/28 16:44:29 by sbethoua         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "game_2048.h"

static void	_game_powers_colors_init(void)
{
	init_color(10, 100, 0, 0);
	init_color(10, 0, 100, 0);
	init_color(10, 0, 0, 100);
	init_color(10, 300, 0, 0);
	init_color(10, 0, 300, 0);
	init_color(10, 0, 0, 300);
	init_color(10, 500, 0, 0);
	init_color(10, 0, 500, 0);
	init_color(10, 0, 0, 500);
	init_color(10, 700, 0, 0);
	init_color(10, 0, 700, 0);
	init_color(10, 0, 0, 700);
	init_color(10, 1000, 0, 0);
	init_color(10, 0, 1000, 0);
	init_color(10, 0, 0, 1000);
	init_color(10, 100, 100, 0);
	init_color(10, 100, 0, 100);
	init_color(10, 0, 100, 100);
	init_color(10, 500, 500, 0);
	init_color(10, 500, 0, 500);
}

void		game_powers_colors_init(t_game *game)
{
	int	i;
	int	clr_idx;

	game->powers[0] = 2;
	i = 1;
	while (i < NB_POWERS)
	{
		game->powers[i] = game->powers[i] * 2;
		i++;
	}
	clr_idx = 10;
	i = 0;
	while (i < NB_POWERS)
	{
		game->colors[i] = game->colors[i] + 1;
		clr_idx++;
		i++;
	}
	_game_powers_colors_init();
}
