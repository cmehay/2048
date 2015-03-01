/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display_loose.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbethoua <sbethoua@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/01 20:40:26 by sbethoua          #+#    #+#             */
/*   Updated: 2015/03/01 20:40:54 by sbethoua         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "game_2048.h"

void	you_loose(void)
{
	WINDOW *win;

	win = newwin(5, COLS / 2, LINES / 2 - (LINES / 4),
		COLS / 2 - (COLS / 4));
	box(win, 0, 0);
	init_color(121, 420, 0, 0);
	init_pair(121, COLOR_WHITE, 121);
	wbkgd(win, COLOR_PAIR(121));
	mvwprintw(win, 2, 2, "%s", "You LOOSE! Try again...");
	wrefresh(win);
	delwin(win);
	while (getch() != 27)
		;
}
