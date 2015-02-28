/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   boucle.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmehay <cmehay@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/28 11:12:46 by cmehay            #+#    #+#             */
/*   Updated: 2015/02/28 12:27:56 by cmehay           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "game_2048.h"

void boucle(t_game *game, int (*f)(t_game*, int y, int x))
{
    int y;
    int x;
    int flag;

    game->flag = FALSE;
    flag = TRUE;
    while (flag)
    {
        flag = FALSE;
        y = GRID_SIZE;
        while (y--)
        {
            x = GRID_SIZE;
            while (x--)
                flag += f(game, y, x);
        }
        if (game->flag)
            break ;
    }
}
