/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbethoua <sbethoua@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/28 18:32:41 by sbethoua          #+#    #+#             */
/*   Updated: 2015/03/01 18:09:37 by sbethoua         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "game_2048.h"

static void	game_error_display(char *msg)
{
	ft_putstr_fd("Game_2048: Error: ", STDERR_FILENO);
	ft_putendl_fd(msg, STDERR_FILENO);
}

int			game_error_handle(int argc, char **argv, char **envp)
{
	t_bool	error;

	(void) argc;
	(void) argv;
	error = FALSE;
	if (envp[0] == NULL)
	{
		error = TRUE;
		game_error_display("The environment is empty");
	}
	if (!isatty(STDOUT_FILENO))
	{
		error = TRUE;
		game_error_display("The output must be a terminal");
	}
	if (!ft_ispoweroftwo(WIN_VALUE) || WIN_VALUE > 1048576)
	{
		error = TRUE;
		game_error_display("Game_2048: Error: WIN_VALUE is not a power of 2 "
				"(or exceeds the maximum of 1048576)");
	}
	if (error)
		return (-1);
	return (0);
}

void		game_size_too_small_display(void)
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
