# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: cmehay <cmehay@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2014/01/17 16:46:09 by cmehay            #+#    #+#              #
#    Updated: 2015/02/28 21:13:25 by sbethoua         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = game_2048
CC = clang
LIBFT_DIR = libft/
CFLAGS = -Wall -Wextra -Werror
LDFLAGS = -L $(LIBFT_DIR) -lft -lncurses
HEADERFILES = ft_2048.h
SRCSDIR = ./
SRCS = $(addprefix $(SRCSDIR), $(SRCSFILES))
SRCSFILES = main.c ncurshit.c boucle.c game_event.c inputs.c square_display.c \
			debug.c colors.c errors.c win_loose.c info_display.c
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
