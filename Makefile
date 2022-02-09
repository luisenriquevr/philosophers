# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lvarela <lvarela@student.42madrid.com>     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/12/30 14:09:09 by lvarela           #+#    #+#              #
#    Updated: 2022/02/08 17:52:32 by lvarela          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC		=	gcc

NAME	=	philosophers

FLAGS	=	-Wall -Werror -Wextra -pthread

SRCS	=	srcs/parsing.c \
			srcs/initializing.c \
			srcs/philosophing.c \
			srcs/utils.c \
			lib/ft_atoi.c \
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
