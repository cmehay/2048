/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_2048.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmehay <cmehay@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/27 21:18:11 by cmehay            #+#    #+#             */
/*   Updated: 2015/03/01 18:18:26 by sbethoua         ###   ########.fr       */
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

# define G_MIN_HEIGHT 25
# define G_MIN_WIDTH 30

# define G_MODE_EASY 6
# define G_MODE_MEDIUM 5
# define G_MODE_HARD 4

# define G_KEY_EASY '1'
# define G_KEY_MEDIUM '2'
# define G_KEY_HARD '3'
# define G_KEY_ESC 27

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

int		game_menu_mode(void);
void	game_menu_mode_display(void);

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
int		game_error_handle(int argc, char **argv, char **envp);
void	game_size_too_small_display(void);

void	win_draw(t_game *game);
void	square_display(t_game *game, t_size *size, int y, int x);

void	you_win(t_game *game);
void	you_loose(void);
void	game_score_display(t_game *game);
void	game_score_end_display(t_game *game);

#endif
