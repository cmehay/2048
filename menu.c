/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   menu.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbethoua <sbethoua@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/01 16:22:20 by sbethoua          #+#    #+#             */
/*   Updated: 2015/03/01 20:43:46 by sbethoua         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "game_2048.h"

static int	game_menu_mode_choose(void)
{
	int	inp;

	while ((inp = getch()) != G_KEY_ESC)
	{
		if (inp == G_KEY_EASY)
			return (G_MODE_EASY);
		if (inp == G_KEY_MEDIUM)
			return (G_MODE_MEDIUM);
		if (inp == G_KEY_HARD)
			return (G_MODE_HARD);
	}
	return (0);
}

int			game_menu_mode(void)
{
	game_menu_mode_display();
	return (game_menu_mode_choose());
}
