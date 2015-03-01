/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_2048.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmehay <cmehay@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/27 21:18:11 by cmehay            #+#    #+#             */
/*   Updated: 2015/03/01 20:57:48 by sbethoua         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GAME_2048_H
# define GAME_2048_H

# include <signal.h>
# include <time.h>
# include <limits.h>
# include <unistd.h>
# include "libft/libft.h"
# include "game_2048_struct.h"

# define G_MIN_HEIGHT 25
# define G_MIN_WIDTH 30

# define G_MODE_EASY 6
# define G_MODE_MEDIUM 5
# define G_MODE_HARD 4

# define G_KEY_EASY '1'
# define G_KEY_MEDIUM '2'
# define G_KEY_HARD '3'
# define G_KEY_ESC 27

/*
** boucle.c
*/
void	boucle(t_game *game, int (*f)(t_game*, int y, int x), t_way way);

/*
** colors.c
*/
void	game_powers_colors_init(t_game *game);

/*
** display_loose.c
*/
void	you_loose(void);

/*
** display_win.c
*/
void	you_win(t_game *game);

/*
** errors.c
*/
int		game_error_handle(int argc, char **argv, char **envp);

/*
** game_check.c
*/
int		check_game(t_game *game, int y, int x);

/*
** game_event.c
*/
int		reset_merged(t_game *game, int y, int x);

/*
** info_display.c
*/
void	game_score_display(t_game *game);
void	game_score_end_display(t_game *game);

/*
** inputs.c
*/
void	key_input(t_game *game);

/*
** menu.c
*/
int		game_menu_mode(void);

/*
** menu_display.c
*/
void	game_menu_mode_display(void);

/*
** square_add.c
*/
int		add_square(t_game *game, int y, int x);

/*
** square_draw.c
*/
void	win_draw(t_game *game);

/*
** square_display.c
*/
void	square_display(t_game *game, t_size *size, int y, int x);

/*
** term_too_small.c
*/
void	game_size_too_small_display(void);

#endif
