/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   info_display.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmehay <cmehay@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/28 21:03:47 by sbethoua          #+#    #+#             */
/*   Updated: 2015/03/01 00:26:52 by cmehay           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "game_2048.h"

void	game_score_display(t_game *game)
{
	WINDOW	*w_info;

	w_info = newwin(5, 20, (LINES - 1), 0);
	mvwprintw(w_info, 0, 0, "%s%d", "Score: ", game->score);
	wrefresh(w_info);
	delwin(w_info);
}

void	game_score_end_display(t_game *game)
{
	WINDOW	*win;
	char	msg[] = "You won. Your score is: ";

	win_draw(game);
	win = newwin(5, COLS / 2, LINES / 2 - (LINES / 4),
		COLS / 2 - (COLS / 4));
	box(win, 0 , 0);
	init_color(122, 0, 0, 420);
	init_pair(122, COLOR_WHITE, 122);
	wbkgd(win, COLOR_PAIR(122));
	mvwprintw(win, 2, 2, "%s%d", msg, game->score);
	wrefresh(win);
	delwin(win);
	while(getch() != 27)
		;
}
