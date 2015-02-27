/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_2048.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmehay <cmehay@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/27 21:18:11 by cmehay            #+#    #+#             */
/*   Updated: 2015/02/28 00:38:33 by cmehay           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GAME_2048
# define GAME_2048

# include "libft/libft.h"
# include <ncurses.h>
# include <signal.h>

# define GRID_SIZE 4

enum e_const
{
    WIN_VALUE = 2048
};

typedef struct  s_size
{
    int heigth;
    int width;
}               t_size;

typedef struct  s_square
{
    WINDOW *win;
    int     val;
    t_bool  merged;
}               t_square;

typedef struct s_game
{
    WINDOW      *win;
    t_square    game[4][4];
    int         score;
}               t_game;

void win_draw(t_game *game);


#endif
