/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   inputs.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmehay <cmehay@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/28 10:25:28 by cmehay            #+#    #+#             */
/*   Updated: 2015/02/28 14:28:56 by cmehay           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "game_2048.h"

int play_up(t_game *game, int y, int x)
{
    game->game[y][x].merged = FALSE;
    if (y)
    {
        if (game->game[y][x].val)
        {
            if (!game->game[y - 1][x].val)
            {
                game->game[y - 1][x].val = game->game[y][x].val;
                game->game[y][x].val = 0;
                return (TRUE);
            }
            if (game->game[y - 1][x].val == game->game[y][x].val &&
                !game->game[y][x].merged && !game->game[y - 1][x].merged)
            {
                game->game[y - 1][x].val <<= 1;
                game->game[y][x].val = 0;
                game->game[y][x].merged = TRUE;
                return (TRUE);
            }
        }
    }
    return (FALSE);
}

int play_down(t_game *game, int y, int x)
{
    game->game[y][x].merged = FALSE;
    if (y < 3)
    {
        if (game->game[y][x].val)
        {
            if (!game->game[y + 1][x].val)
            {
                game->game[y + 1][x].val = game->game[y][x].val;
                game->game[y][x].val = 0;
                return (TRUE);
            }
            if (game->game[y + 1][x].val == game->game[y][x].val &&
                !game->game[y][x].merged && !game->game[y + 1][x].merged)
            {
                game->game[y + 1][x].val <<= 1;
                game->game[y][x].val = 0;
                game->game[y][x].merged = TRUE;
                return (TRUE);
            }
        }
    }
    return (FALSE);
}

int play_left(t_game *game, int y, int x)
{
    game->game[y][x].merged = FALSE;
    if (x)
    {
        if (game->game[y][x].val)
        {
            if (!game->game[y][x - 1].val)
            {
                game->game[y][x - 1].val = game->game[y][x].val;
                game->game[y][x].val = 0;
                return (TRUE);
            }
            if (game->game[y][x - 1].val == game->game[y][x].val &&
                !game->game[y][x].merged && !game->game[y][x - 1].merged)
            {
                game->game[y][x - 1].val <<= 1;
                game->game[y][x].val = 0;
                game->game[y][x].merged = TRUE;
                return (TRUE);
            }
        }
    }
    return (FALSE);
}

int play_right(t_game *game, int y, int x)
{
    game->game[y][x].merged = FALSE;
    if (x < 3)
    {
        if (game->game[y][x].val)
        {
            if (!game->game[y][x + 1].val)
            {
                game->game[y][x + 1].val = game->game[y][x].val;
                game->game[y][x].val = 0;
                return (TRUE);
            }
            if (game->game[y][x + 1].val == game->game[y][x].val &&
                !game->game[y][x].merged && !game->game[y][x + 1].merged)
            {
                game->game[y][x + 1].val <<= 1;
                game->game[y][x].val = 0;
                game->game[y][x].merged = TRUE;
                return (TRUE);
            }
        }
    }
    return (FALSE);
}
