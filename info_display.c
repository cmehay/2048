/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   info_display.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmehay <cmehay@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/28 21:03:47 by sbethoua          #+#    #+#             */
/*   Updated: 2015/03/01 20:45:58 by sbethoua         ###   ########.fr       */
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
