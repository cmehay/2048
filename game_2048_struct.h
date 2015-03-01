/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_2048_struct.h                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbethoua <sbethoua@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/01 19:18:53 by sbethoua          #+#    #+#             */
/*   Updated: 2015/03/01 19:30:50 by sbethoua         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GAME_2048_STRUCT_H
# define GAME_2048_STRUCT_H

# include <ncurses.h>

enum			e_const
{
	WIN_VALUE = 2048,
	MAX_GRID = 6
};

typedef enum	e_way
{
	FORWARD,
	BACKWARD
}				t_way;

typedef struct	s_size
{
	int	heigth;
	int	width;
}				t_size;

typedef struct	s_square
{
	WINDOW	*win;
	int		val;
	t_bool	merged;
}				t_square;

typedef struct	s_game
{
	t_square		game[MAX_GRID][MAX_GRID];
	unsigned int	score;
	int				game_mode;
	int				flag;
	int				win;
	int				win_state;
	int				nb_powers;
	int				powers[20];
	int				colors[20];
	int				has_move;
	t_bool			in_menu;
}				t_game;

#endif
