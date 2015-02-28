/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_2048.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmehay <cmehay@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/27 21:18:11 by cmehay            #+#    #+#             */
/*   Updated: 2015/02/28 19:25:20 by sbethoua         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GAME_2048
# define GAME_2048

# include "libft/libft.h"
# include <ncurses.h>
# include <signal.h>
# include <time.h>
# include <limits.h>
# include <unistd.h>

# define GRID_SIZE 4
# define NB_POWERS 20

enum e_const
{
    WIN_VALUE = 8
};

typedef enum    e_way
{
    FORWARD,
    BACKWARD
}               t_way;

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
    t_square    game[GRID_SIZE][GRID_SIZE];
    int         score;
    int         flag;
    int         win;
    int         win_state;
	int			powers[NB_POWERS];
	int			colors[NB_POWERS];
    int         has_move;
}               t_game;

void	win_draw(t_game *game);
void	game_powers_colors_init(t_game *game);

int		play_up(t_game *game, int y, int x);
int		play_down(t_game *game, int y, int x);
int		play_left(t_game *game, int y, int x);
int		play_right(t_game *game, int y, int x);

void	boucle(t_game *game, int (*f)(t_game*, int y, int x), t_way way);

int		add_square(t_game *game, int y, int x);
int		check_game(t_game *game, int y, int x);

int		reset_merged(t_game *game, int y, int x);
void	game_error_handle(int argc, char **argv, char **envp);

//debug
int		output(void);
void	win_draw(t_game *game);
void	square_display(t_game *game, t_size *size, int y, int x);

void    you_win(t_game *game);
void    you_loose(void);

#endif
