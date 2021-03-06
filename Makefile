# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: cmehay <cmehay@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2014/01/17 16:46:09 by cmehay            #+#    #+#              #
#*   Updated: 2015/03/01 00:36:42 by sbethoua         ###   ########.fr       *#
#                                                                              #
# **************************************************************************** #

NAME = game_2048
CC = clang
LIBFT_DIR = libft/
CFLAGS = -Wall -Wextra -Werror
LDFLAGS = -L $(LIBFT_DIR) -lft -lncurses
HEADERFILES = game_2048.h game_2048_struct.h
SRCSDIR = ./
SRCS = $(addprefix $(SRCSDIR), $(SRCSFILES))
SRCSFILES = main.c square_draw.c boucle.c game_event.c inputs.c \
			square_display.c colors.c errors.c info_display.c menu.c \
			term_too_small.c display_win.c display_loose.c menu_display.c \
			display_end.c square_add.c game_check.c
OBJS = $(SRCS:.c=.o)
LIBFT = $(LIBFT_DIR)libft.a

all: $(NAME)

$(NAME): $(OBJS) $(LIBFT)
	$(CC) -o $(NAME) $(OBJS) $(LDFLAGS)

$(LIBFT):
	$(MAKE) -C $(LIBFT_DIR)

%.o: %.c $(HEADERFILES)
	$(CC) $(CFLAGS) -c -o $@ $<

clean:
	$(MAKE) -C $(LIBFT_DIR) $@
	/bin/rm -f $(OBJS)

fclean: clean
	$(MAKE) -C $(LIBFT_DIR) $@
	/bin/rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
