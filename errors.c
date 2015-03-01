/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbethoua <sbethoua@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/28 18:32:41 by sbethoua          #+#    #+#             */
/*   Updated: 2015/03/01 20:36:40 by sbethoua         ###   ########.fr       */
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

	(void)argc;
	(void)argv;
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
