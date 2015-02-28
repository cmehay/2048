/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   colors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbethoua <sbethoua@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/28 16:04:54 by sbethoua          #+#    #+#             */
/*   Updated: 2015/02/28 17:21:41 by sbethoua         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "game_2048.h"

static void	_game_powers_colors_init(void)
{
	init_color(100, 150, 0, 0);
	init_color(101, 0, 150, 0);
	init_color(102, 0, 0, 150);
	init_color(103, 300, 100, 0);
	init_color(104, 0, 300, 100);
	init_color(105, 0, 0, 300);
	init_color(106, 500, 0, 200);
	init_color(107, 100, 500, 0);
	init_color(108, 0, 200, 500);
	init_color(109, 700, 200, 0);
	init_color(200, 100, 700, 0);
	init_color(201, 0, 500, 700);
	init_color(202, 1000, 0, 0);
	init_color(203, 0, 1000, 0);
	init_color(204, 0, 0, 1000);
	init_color(205, 100, 100, 0);
	init_color(206, 100, 0, 100);
	init_color(207, 0, 100, 100);
	init_color(208, 500, 500, 0);
	init_color(209, 500, 0, 500);
}

void		game_powers_colors_init(t_game *game)
{
	int	i;
	int	clr_idx;

	game->powers[0] = 2;
	i = 1;
	while (i < NB_POWERS)
	{
		game->powers[i] = 1 << i;
		i++;
	}
	clr_idx = 100;
	i = 0;
	while (i < NB_POWERS)
	{
		game->colors[i] = clr_idx;;
		clr_idx++;
		i++;
	}
	_game_powers_colors_init();
}
