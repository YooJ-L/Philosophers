# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: yoojlee <yoojlee@student.42seoul.kr>       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/02/28 18:06:29 by yoojlee           #+#    #+#              #
#    Updated: 2022/03/06 20:08:08 by yoojlee          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = philo
BONUS_NAME = philo_bonus

CC = gcc
CFLAGS = -Wall -Wextra -Werror
CFLAGS += -g -fsanitize=address

SRCS = $(addprefix ./srcs/, \
		main.c \
		philo.c	\
		init.c	\
		routine.c	\
		utils.c	\
		free.c \
		libft.c \
		)

BONUS_SRCS = $(addprefix ./srcs_bonus/, \
		main_bonus.c \
		philo_bonus.c	\
		init_bonus.c	\
		routine_bonus.c	\
		utils_bonus.c	\
		free_bonus.c \
		libft_bonus.c \
		)

OBJS = $(SRCS:.c=.o)

BONUS_OBJS = $(BONUS_SRCS:.c=.o)

$(NAME) : $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) $(LIBFLAGS) -o $(NAME)

$(BONUS_NAME) : $(BONUS_OBJS)
	$(CC) $(CFLAGS) $(BONUS_OBJS) $(LIBFLAGS) -o $(BONUS_NAME)

all : $(NAME)

clean :
	rm -rf $(OBJS) $(BONUS_OBJS)

fclean : clean
	rm -rf $(NAME) $(BONUS_NAME)

bonus : all $(BONUS_NAME)

re : fclean all