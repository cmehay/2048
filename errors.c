/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbethoua <sbethoua@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/28 18:32:41 by sbethoua          #+#    #+#             */
/*   Updated: 2015/02/28 19:13:13 by sbethoua         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "game_2048.h"

static void	_game_error_handle(void)
{
	ft_putstr_fd("Game_2048: Error: ", STDERR_FILENO);
}

void		game_error_handle(int argc, char **argv, char **envp)
{
	t_bool	error;

	(void) argc;
	(void) argv;
	error = FALSE;
	if (envp[0] == NULL)
	{
		error = TRUE;
		_game_error_handle();
		ft_putendl_fd("The environment is empty", STDERR_FILENO);
	}
	if (!isatty(STDOUT_FILENO))
	{
		error = TRUE;
		_game_error_handle();
		ft_putendl_fd("The output must be a terminal", STDERR_FILENO);
	}
	if (!ft_ispoweroftwo(WIN_VALUE) || WIN_VALUE > 1048576)
	{
		error = TRUE;
		ft_putendl_fd("Game_2048: Error: WIN_VALUE is not a power of 2 "
				"(or exceeds the maximum of 1048576)", STDERR_FILENO);
	}
	if (error)
		exit(2);
}
