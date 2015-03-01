/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   term_too_small.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbethoua <sbethoua@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/01 20:36:24 by sbethoua          #+#    #+#             */
/*   Updated: 2015/03/01 20:36:58 by sbethoua         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "game_2048.h"

void	game_size_too_small_display(void)
{
	WINDOW	*w_error;

	w_error = newwin(LINES, COLS, (LINES / 2 - 1), (COLS / 2 - 10));
	init_pair(123, COLOR_RED, 0);
	wbkgd(w_error, COLOR_PAIR(123));
	mvwprintw(w_error, 0, 0, "%s%s",
			"Window is too small!", "\nPlease, resize it. :)");
	wrefresh(w_error);
	delwin(w_error);
}
