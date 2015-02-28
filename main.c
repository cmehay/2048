/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmehay <cmehay@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/27 21:18:18 by cmehay            #+#    #+#             */
/*   Updated: 2015/02/28 14:38:40 by cmehay           ###   ########.fr       */
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
            game->game[y][x].val = 0;
            game->game[y][x].merged = (t_bool)FALSE;
        }
    }
    game->win_state = 0;
    game->win = 0;
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

static void key_input(t_game *game)
{
    int inp;
    keypad(stdscr, TRUE);
    boucle(game, add_square);
    boucle(game, add_square);
    win_draw(game);
    while((inp = getch()) != 27)
    {
        if (inp == KEY_UP)
            boucle(game, play_up);
        if (inp == KEY_DOWN)
            boucle(game, play_down);
        if (inp == KEY_LEFT)
            boucle(game, play_left);
        if (inp == KEY_RIGHT)
            boucle(game, play_right);
        boucle(game, check_game);
        if (game->flag)
            break ;
        boucle(game, add_square);
        win_draw(game);
    }
}

int main(void)
{
    t_game game;

    g_game = &game;
    srand(time(NULL));
    initscr();
    cbreak();
    noecho();
    init_game(&game);
	start_color();
    refresh();
    signal_handle();
    win_draw(&game);
    key_input(&game);
    endwin();
    return 0;
}
