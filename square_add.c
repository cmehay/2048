/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   square_add.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbethoua <sbethoua@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/01 20:47:39 by sbethoua          #+#    #+#             */
/*   Updated: 2015/03/01 20:47:53 by sbethoua         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "game_2048.h"

int	add_square(t_game *game, int y, int x)
{
	int	random;

	if (game->flag || game->game[y][x].val)
		return (FALSE);
	random = rand() % (game->game_mode * game->game_mode);
	if (!random)
	{
		game->game[y][x].val = (rand() % 2) ? 2 : 4;
		game->flag = TRUE;
		return (FALSE);
	}
	return (TRUE);
}
