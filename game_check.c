/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_check.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbethoua <sbethoua@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/01 20:48:23 by sbethoua          #+#    #+#             */
/*   Updated: 2015/03/01 20:48:43 by sbethoua         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "game_2048.h"

int	check_game(t_game *game, int y, int x)
{
	if (y == game->game_mode - 1 && x == game->game_mode - 1)
		game->flag = TRUE;
	if (!game->game[y][x].val)
		game->flag = FALSE;
	if (x)
	{
		if (game->game[y][x].val == game->game[y][x - 1].val)
			game->flag = FALSE;
	}
	if (y)
	{
		if (game->game[y][x].val == game->game[y - 1][x].val)
			game->flag = FALSE;
	}
	if (game->game[y][x].val == WIN_VALUE && !game->win_state)
	{
		you_win(game);
		game->win = TRUE;
		game->win_state = TRUE;
	}
	return (FALSE);
}
