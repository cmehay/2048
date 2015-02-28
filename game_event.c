/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_event.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmehay <cmehay@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/28 12:09:03 by cmehay            #+#    #+#             */
/*   Updated: 2015/02/28 16:45:10 by cmehay           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "game_2048.h"

int add_square(t_game *game, int y, int x)
{
    int random;

    if (game->flag || game->game[y][x].val)
        return (FALSE);
    random = rand() % 16;
    if (!random)
    {
        game->game[y][x].val = (rand() % 2) ? 2 : 4;
        game->flag = TRUE;
        return (FALSE);
    }
    return (TRUE);
}

int check_game(t_game *game, int y, int x)
{
    if (y == 3 && x == 3)
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
        game->win = TRUE;
        game->win_state = TRUE;
    }
    return (FALSE);
}

int reset_merged(t_game *game, int y, int x)
{
    game->game[y][x].merged = FALSE;
    return (FALSE);
}
