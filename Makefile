# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: yoojlee <yoojlee@student.42seoul.kr>       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/02/28 18:06:29 by yoojlee           #+#    #+#              #
#    Updated: 2022/02/28 18:08:08 by yoojlee          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		= philo

CC			= gcc
CFLAGS		= -Wall -Wextra -Werror $(INCFLAGS) #$(GFLAGS)
THRDFLAGS	= -lpthread
GFLAGS		= -g -fsanitize=address

INCDIR		= include
INCFLAGS	= -I$(INCDIR)

SRCDIR		= src
SRCS		= $(patsubst %.c, $(SRCDIR)/%.c, philo.c\
			  init.c\
			  routine.c\
			  utils.c)

OBJDIR		= build
OBJS		= $(patsubst $(SRCDIR)/%.c, $(OBJDIR)/%.o, $(SRCS))

all			: $(NAME)

$(NAME)		: $(OBJDIR) $(OBJS)
	$(CC) -o $@ $(OBJS) $(CFLAGS) $(THRDFLAGS)

$(OBJDIR)	:
	mkdir build

$(OBJDIR)/%.o	: $(SRCDIR)/%.c
	$(CC) $(CFLAGS) -o $@ -c $^

$(BONUS_DIR)/%.o	: $(BONUS_DIR)/%.c
	$(CC) $(CFLAGS) -o $@ -c $^

clean		:
	$(RM) -r $(OBJS)

fclean		: clean
	$(RM) $(NAME)

re			: fclean all

.PHONY		: all clean fclean re
