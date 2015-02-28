/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   win_loose.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmehay <cmehay@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/28 17:45:03 by cmehay            #+#    #+#             */
/*   Updated: 2015/02/28 18:43:35 by cmehay           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "game_2048.h"

void	you_win(void)
{
	WINDOW *win;
	char msg[] = "You WIN! - Press any key to continue...";

	win = newwin(LINES / 2, COLS / 2, LINES / 2 - (LINES / 4),
		COLS / 2 - (COLS / 4));
	box(win, 0 , 0);
	mvwprintw(win, 2, 2, "%s", msg);
	wrefresh(win);
	getch();
}

void	you_loose(void)
{
	WINDOW *win;
	char msg[] = "You LOOSE!";

	win = newwin(LINES / 2, COLS / 2, LINES / 2 - (LINES / 4),
		COLS / 2 - (COLS / 4));
	box(win, 0 , 0);
	mvwprintw(win, ((LINES / 4) / 2) - (ft_strlen(msg) / 2) , 2, "%s", msg);
	wrefresh(win);
	while(getch() != 27)
		;
}
