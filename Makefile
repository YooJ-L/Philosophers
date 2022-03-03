# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: yoojlee <yoojlee@student.42seoul.kr>       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/02/28 18:06:29 by yoojlee           #+#    #+#              #
#    Updated: 2022/03/03 14:59:00 by yoojlee          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = gcc
CFLAGS = -Wextra -Werror -Wall
CFLAGS += -g -fsanitize=address

NAME = philo

DIR_H = ./includes/
DIR_S = ./srcs/
DIR_O = ./

SRC =	main.c \
		philo.c	\
		init.c	\
		routine.c	\
		utils.c	\
		free.c \
		libft.c \

SRCS = $(addprefix $(DIR_S), $(SRC))

OBJS = $(SRCS:.c=.o)

all: $(NAME)

%.o: %.c
	$(CC) $(CFLAGS) -o $@ -c $<

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -o $(NAME) -lpthread

clean:
	rm -rf $(OBJS)

fclean: clean
	rm -rf $(NAME)

re: fclean all

.PHONY: clean fclean all re
