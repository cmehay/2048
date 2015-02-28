/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   win_loose.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmehay <cmehay@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/28 17:45:03 by cmehay            #+#    #+#             */
/*   Updated: 2015/02/28 19:02:33 by cmehay           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "game_2048.h"

void	you_win(t_game *game)
{
	WINDOW *win;
	char msg[] = "You WIN! - Press esc to continue...";

	win_draw(game);
	win = newwin(5, COLS / 2, LINES / 2 - (LINES / 4),
		COLS / 2 - (COLS / 4));
	box(win, 0 , 0);
	mvwprintw(win, 2, 2, "%s", msg);
	wrefresh(win);
	while(getch() != 27)
		;
}

void	you_loose(void)
{
	WINDOW *win;
	char msg[] = "You LOOSE!";

	win = newwin(5, COLS / 2, LINES / 2 - (LINES / 4),
		COLS / 2 - (COLS / 4));
	box(win, 0 , 0);
	mvwprintw(win, ((LINES / 4) / 2) - (ft_strlen(msg) / 2) , 2, "%s", msg);
	wrefresh(win);
	while(getch() != 27)
		;
}
