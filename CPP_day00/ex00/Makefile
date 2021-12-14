# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: user42 <marvin@42.fr>                      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/10/25 10:54:51 by user42            #+#    #+#              #
#    Updated: 2021/12/03 14:44:36 by lyie             ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS =	./megaphone.cpp

OBJS = ${SRCS:.c=.o}
NAME = megaphone
CC = c++
RM = rm -f
CFLAGS = -Wall -Wextra -Werror -std=c++98
all: ${NAME}

$(NAME)	: ${OBJS}
	${CC} ${CFLAGS} ${OBJS} -o $(NAME)

clean:

fclean: clean
	${RM} ${NAME}

re: fclean all

.PHONY: all clean fclean re
