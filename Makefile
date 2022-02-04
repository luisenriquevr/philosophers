# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lvarela <lvarela@student.42madrid.com>     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/12/30 14:09:09 by lvarela           #+#    #+#              #
#    Updated: 2022/02/04 10:25:25 by lvarela          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC		=	gcc

NAME	=	philosophers

FLAGS	=	-Wall -Werror -Wextra -pthread

SRCS	=	srcs/parsing.c \
			srcs/init.c \
			lib/ft_atoi.c \
			lib/ft_putstr_fd.c \
			philosophers.c \
			

OBJS	=	$(SRCS:.c=.o)

RM		=	rm -f

$(NAME) : $(OBJS)
		$(CC) $(OBJS) $(FLAGS) -o $(NAME)

all	:	$(NAME)

clean	:
		${RM} ${OBJS}

fclean	: clean
		${RM} ${NAME}

re	: fclean all

%.o	: %.c
	$(CC) $(FLAGS) -c $< -o $(<:.c=.o)
