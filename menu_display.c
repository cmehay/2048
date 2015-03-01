/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   menu_display.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbethoua <sbethoua@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/01 20:43:16 by sbethoua          #+#    #+#             */
/*   Updated: 2015/03/01 20:43:57 by sbethoua         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "game_2048.h"

void		game_menu_mode_display(void)
{
	WINDOW	*w_mode;

	refresh();
	if (LINES < G_MIN_HEIGHT || COLS < G_MIN_WIDTH)
		return (game_size_too_small_display());
	w_mode = newwin(LINES, COLS, (LINES / 2 - 2), (COLS / 2 - 8));
	init_pair(124, COLOR_BLUE, 0);
	wbkgd(w_mode, COLOR_PAIR(124));
	mvwprintw(w_mode, 0, 0, "%s%s%s%s", "   GAME_2048!   \n\n",
			"[1] Easy (6x6) \n", "[2] Medium (5x5)\n", "[3] Hard (4x4) ");
	wrefresh(w_mode);
	delwin(w_mode);
}
