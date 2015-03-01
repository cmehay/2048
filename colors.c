/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   colors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmehay <cmehay@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/28 16:04:54 by sbethoua          #+#    #+#             */
/*   Updated: 2015/03/01 19:37:51 by sbethoua         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "game_2048.h"

static void	game_powers_colors_define(void)
{
	init_color(100, 150, 0, 0);
	init_color(101, 0, 150, 0);
	init_color(102, 0, 0, 150);
	init_color(103, 300, 100, 0);
	init_color(104, 0, 300, 100);
	init_color(105, 0, 0, 300);
	init_color(106, 500, 0, 200);
	init_color(107, 400, 400, 0);
	init_color(108, 0, 200, 500);
	init_color(109, 700, 200, 0);
	init_color(110, 100, 700, 0);
	init_color(111, 0, 500, 700);
	init_color(112, 1000, 0, 0);
	init_color(113, 0, 1000, 0);
	init_color(114, 0, 0, 1000);
	init_color(115, 100, 100, 0);
	init_color(116, 100, 0, 100);
	init_color(117, 0, 100, 100);
	init_color(118, 500, 500, 0);
	init_color(119, 500, 0, 500);
}

void		game_powers_colors_init(t_game *game)
{
	int	i;
	int	clr_idx;

	game->powers[0] = 2;
	i = 1;
	while (i < game->nb_powers)
	{
		game->powers[i] = game->powers[i - 1] * 2;
		i++;
	}
	clr_idx = 100;
	i = 0;
	while (i < game->nb_powers)
	{
		game->colors[i] = clr_idx;
		clr_idx++;
		i++;
	}
	game_powers_colors_define();
}
