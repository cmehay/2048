/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display_end.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbethoua <sbethoua@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/01 20:45:41 by sbethoua          #+#    #+#             */
/*   Updated: 2015/03/01 20:45:56 by sbethoua         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "game_2048.h"

void	game_score_end_display(t_game *game)
{
	WINDOW	*win;

	win_draw(game);
	win = newwin(5, COLS / 2, LINES / 2 - (LINES / 4),
		COLS / 2 - (COLS / 4));
	box(win, 0, 0);
	init_color(122, 0, 0, 420);
	init_pair(122, COLOR_WHITE, 122);
	wbkgd(win, COLOR_PAIR(122));
	mvwprintw(win, 2, 2, "%s%d", "You won. Your score is: ", game->score);
	wrefresh(win);
	delwin(win);
	while (getch() != 27)
		;
}
