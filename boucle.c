/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   boucle.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmehay <cmehay@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/28 11:12:46 by cmehay            #+#    #+#             */
/*   Updated: 2015/02/28 23:51:13 by cmehay           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "game_2048.h"

void boucle(t_game *game, int (*f)(t_game*, int y, int x), t_way way)
{
    int y;
    int x;
    int flag;

    game->flag = FALSE;
    flag = TRUE;
    while (flag)
    {
        flag = FALSE;
        y = (way == FORWARD) ? -1 : game->game_mode;
        while (((way == FORWARD) && ++y < game->game_mode) || ((way == BACKWARD) && y--))
        {
            x = (way == FORWARD) ? -1 : game->game_mode;
            while (((way == FORWARD) && ++x < game->game_mode) || ((way == BACKWARD) && x--))
                flag += f(game, y, x);
        }
        if (game->flag)
            break ;
    }
}
