/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmehay <cmehay@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/27 21:18:18 by cmehay            #+#    #+#             */
/*   Updated: 2015/02/28 18:54:01 by cmehay           ###   ########.fr       */
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
    boucle(game, add_square, FORWARD);
    boucle(game, add_square, FORWARD);
    win_draw(game);
    while((inp = getch()) != 27)
    {
        game->has_move = 0;
        boucle(game, reset_merged, FORWARD);
        if (inp == KEY_UP)
            boucle(game, play_up, FORWARD);
        if (inp == KEY_DOWN)
            boucle(game, play_down, BACKWARD);
        if (inp == KEY_LEFT)
            boucle(game, play_left, FORWARD);
        if (inp == KEY_RIGHT)
            boucle(game, play_right, BACKWARD);
        boucle(game, check_game, BACKWARD);
        if (game->flag)
            return ;
        if (game->has_move)
            boucle(game, add_square, FORWARD);
        win_draw(game);
    }
    game->flag = 0;
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
	game_powers_colors_init(&game);
    refresh();
    signal_handle();
    win_draw(&game);
    key_input(&game);
    if (game.flag)
        you_loose();
    endwin();
    return 0;
}
