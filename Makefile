# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: vharkush <vharkush@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/06/09 12:59:18 by vharkush          #+#    #+#              #
#    Updated: 2023/06/10 11:05:12 by vharkush         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = ./philo

SRCS =	src/philosophers.c	\
		src/input.c			\
		src/utils.c

CC = cc

CFLAGS = -g -pthread -Wextra -Werror -Wall

INCL = -I ./incl

OBJS = $(SRCS:.c=.o)

$(NAME): $(OBJS)
		$(CC) -o $(NAME) $(CFLAGS) $(OBJS)

all:    $(NAME)

clean:
		rm -rf $(OBJS)

fclean: clean
		rm -rf $(NAME)

re: fclean all

.PHONY: all clean fclean re
