/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ncurshit.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmehay <cmehay@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/27 22:11:16 by cmehay            #+#    #+#             */
/*   Updated: 2015/02/28 00:48:53 by cmehay           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "game_2048.h"

static void get_square_size(t_size *size)
{
    size->heigth = (LINES - 1) / GRID_SIZE;
    size->width = (COLS) / GRID_SIZE;
}

static void square_del(WINDOW *square)
{
    wborder(square, ' ', ' ', ' ',' ',' ',' ',' ',' ');
    wrefresh(square);
    delwin(square);
}

static void square_draw(t_game *game, t_size *size, int y, int x)
{
    int pos_y;
    int pos_x;

    pos_y = size->heigth * y;
    pos_x = size->width * x;
    square_del(game->game[y][x].win);
    game->game[y][x].win = newwin(size->heigth, size->width, pos_y, pos_x);
    box(game->game[y][x].win, 0 , 0);
    if (game->game[y][x].val)
    {
        if (game->game[y][x].merged)
            wattron(game->game[y][x].win, A_BOLD);
        wprintw(game->game[y][x].win, "%d", game->game[y][x].val);
    }
    wrefresh(game->game[y][x].win);
}

void win_draw(t_game *game)
{
    t_size  size;
    int     y;
    int     x;

    get_square_size(&size);
    y = GRID_SIZE;
    while (y--)
    {
        x = GRID_SIZE;
        while (x--)
            square_draw(game, &size, y, x);
    }

}
