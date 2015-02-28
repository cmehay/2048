/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmehay <cmehay@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/27 21:18:18 by cmehay            #+#    #+#             */
/*   Updated: 2015/02/28 07:51:33 by cmehay           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "game_2048.h"

t_game *g_game;

static void init_game(t_game *game)
{
    int y;
    int x;

    y = GRID_SIZE;
    while (y--)
    {
        x = GRID_SIZE;
        while (x--)
        {
            game->game[y][x].win = NULL;
            game->game[y][x].val = x + y;
            game->game[y][x].merged = (t_bool)FALSE;
        }
    }
    game->score = 0;
}

static void resize_handle(int sig)
{
    (void)sig;
    endwin();
    refresh();
    clear();
    win_draw(g_game);
}

static void signal_handle(void)
{
    signal(SIGWINCH, resize_handle);
}

int main(void)
{
    t_game game;

    g_game = &game;
    initscr();
    cbreak();
    noecho();
    init_game(&game);
    refresh();
    signal_handle();
    win_draw(&game);
    keypad(stdscr, TRUE);
    while(getch() != 27)
        ;
    endwin();
    return 0;
}
