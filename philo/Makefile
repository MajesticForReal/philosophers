# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: anrechai <anrechai@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/07/07 18:31:29 by anrechai          #+#    #+#              #
#    Updated: 2022/07/20 16:17:49 by anrechai         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS		=	main.c utils.c init.c check.c routine.c

OBJS		=	${SRCS:.c=.o}

NAME		=	philo

CFLAGS		=	-Wall -Wextra -lpthread

CC			=	cc

HEADER		=	philo.h

%.o:%.c
			$(CC) $(CFLAGS) -c $< -o $@ -I./

$(NAME):	${OBJS}
			$(CC) $(CFLAGS) $(OBJS) -o $(NAME) -L.

all:		$(NAME)

clean:
			rm -f ${OBJS}
			@echo "\033[92mstatus $@ is [OK]\033[0m"

fclean:		clean
			rm -f ${NAME}
			@echo "\033[92mstatus $@ [OK]\033[0m"

re:			fclean all

.PHONY:		fclean clean re all
