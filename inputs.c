/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   inputs.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmehay <cmehay@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/28 10:25:28 by cmehay            #+#    #+#             */
/*   Updated: 2015/03/01 19:49:35 by sbethoua         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "game_2048.h"

static int	play_up(t_game *game, int y, int x)
{
	if (y)
	{
		if (game->game[y][x].val)
		{
			if (!game->game[y - 1][x].val)
			{
				game->game[y - 1][x].val = game->game[y][x].val;
				game->game[y][x].val = 0;
				game->has_move = TRUE;
				return (TRUE);
			}
			if (game->game[y - 1][x].val == game->game[y][x].val &&
				!game->game[y][x].merged && !game->game[y - 1][x].merged)
			{
				game->game[y - 1][x].val <<= 1;
				game->game[y - 1][x].merged = TRUE;
				game->game[y][x].val = 0;
				game->has_move = TRUE;
				game->score += game->game[y - 1][x].val + game->game[y][x].val;
				return (TRUE);
			}
		}
	}
	return (FALSE);
}

static int	play_down(t_game *game, int y, int x)
{
	if (y < game->game_mode - 1)
	{
		if (game->game[y][x].val)
		{
			if (!game->game[y + 1][x].val)
			{
				game->game[y + 1][x].val = game->game[y][x].val;
				game->game[y][x].val = 0;
				game->has_move = TRUE;
				return (TRUE);
			}
			if (game->game[y + 1][x].val == game->game[y][x].val &&
				!game->game[y][x].merged && !game->game[y + 1][x].merged)
			{
				game->game[y + 1][x].val <<= 1;
				game->game[y + 1][x].merged = TRUE;
				game->game[y][x].val = 0;
				game->has_move = TRUE;
				game->score += game->game[y + 1][x].val + game->game[y][x].val;
				return (TRUE);
			}
		}
	}
	return (FALSE);
}

static int	play_left(t_game *game, int y, int x)
{
	if (x)
	{
		if (game->game[y][x].val)
		{
			if (!game->game[y][x - 1].val)
			{
				game->game[y][x - 1].val = game->game[y][x].val;
				game->game[y][x].val = 0;
				game->has_move = TRUE;
				return (TRUE);
			}
			if (game->game[y][x - 1].val == game->game[y][x].val &&
				!game->game[y][x].merged && !game->game[y][x - 1].merged)
			{
				game->game[y][x - 1].val <<= 1;
				game->game[y][x - 1].merged = TRUE;
				game->game[y][x].val = 0;
				game->has_move = TRUE;
				game->score += game->game[y][x - 1].val + game->game[y][x].val;
				return (TRUE);
			}
		}
	}
	return (FALSE);
}

static int	play_right(t_game *game, int y, int x)
{
	if (x < game->game_mode - 1)
	{
		if (game->game[y][x].val)
		{
			if (!game->game[y][x + 1].val)
			{
				game->game[y][x + 1].val = game->game[y][x].val;
				game->game[y][x].val = 0;
				game->has_move = TRUE;
				return (TRUE);
			}
			if (game->game[y][x + 1].val == game->game[y][x].val &&
				!game->game[y][x].merged && !game->game[y][x + 1].merged)
			{
				game->game[y][x + 1].val <<= 1;
				game->game[y][x + 1].merged = TRUE;
				game->game[y][x].val = 0;
				game->has_move = TRUE;
				game->score += game->game[y][x + 1].val + game->game[y][x].val;
				return (TRUE);
			}
		}
	}
	return (FALSE);
}

void		key_input(t_game *game)
{
	int	inp;

	boucle(game, add_square, FORWARD);
	boucle(game, add_square, FORWARD);
	win_draw(game);
	while ((inp = getch()) != G_KEY_ESC)
	{
		boucle(game, reset_merged, FORWARD);
		if (inp == KEY_UP)
			boucle(game, play_up, FORWARD);
		if (inp == KEY_DOWN)
			boucle(game, play_down, BACKWARD);
		if (inp == KEY_LEFT)
			boucle(game, play_left, FORWARD);
		if (inp == KEY_RIGHT)
			boucle(game, play_right, BACKWARD);
		boucle(game, check_game, BACKWARD);
		if (game->flag)
			return ;
		if (game->has_move)
			boucle(game, add_square, FORWARD);
		win_draw(game);
	}
	game->flag = 0;
}
