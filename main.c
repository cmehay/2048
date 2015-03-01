/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmehay <cmehay@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/27 21:18:18 by cmehay            #+#    #+#             */
/*   Updated: 2015/03/01 20:06:41 by sbethoua         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "game_2048.h"

t_game *g_game;

static void	resize_handle(int sig)
{
	(void)sig;
	endwin();
	refresh();
	clear();
	if (g_game->in_menu)
		game_menu_mode_display();
	else
		win_draw(g_game);
}

static void	signal_handle(void)
{
	signal(SIGWINCH, resize_handle);
}

static void	init_term(void)
{
	srand(time(NULL));
	initscr();
	cbreak();
	noecho();
	curs_set(0);
	start_color();
	signal_handle();
	keypad(stdscr, TRUE);
	refresh();
}

static int	init_game(t_game *game)
{
	int	y;
	int	x;

	game->in_menu = TRUE;
	if (!(game->game_mode = game_menu_mode()))
		return (-1);
	game->in_menu = FALSE;
	y = game->game_mode;
	while (y--)
	{
		x = game->game_mode;
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
	game->nb_powers = 20;
	return (0);
}

int			main(int argc, char **argv, char **envp)
{
	t_game	game;

	if (!game_error_handle(argc, argv, envp))
	{
		g_game = &game;
		init_term();
		if (init_game(&game) != -1)
		{
			game_powers_colors_init(&game);
			signal_handle();
			win_draw(&game);
			key_input(&game);
			if (game.flag)
			{
				if (game.win)
					game_score_end_display(&game);
				else
					you_loose();
			}
		}
		use_default_colors();
		endwin();
	}
	return (0);
}
