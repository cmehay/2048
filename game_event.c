/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_event.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmehay <cmehay@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/28 12:09:03 by cmehay            #+#    #+#             */
/*   Updated: 2015/03/01 20:48:38 by sbethoua         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "game_2048.h"

int	reset_merged(t_game *game, int y, int x)
{
	game->has_move = 0;
	game->game[y][x].merged = FALSE;
	return (FALSE);
}
