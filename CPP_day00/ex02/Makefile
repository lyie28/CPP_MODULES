# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: user42 <marvin@42.fr>                      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/10/25 10:54:51 by user42            #+#    #+#              #
#    Updated: 2021/12/03 14:45:49 by lyie             ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS = Account.cpp tests.cpp
OBJS = ${SRCS:.cpp=.o}
NAME = account_tests
DEPF = -MMD -MP
DEP = ${OBJS:.o=.d}
CC = c++
RM = rm -f
CFLAGS = -Wall -Wextra -Werror --std=c++98
all: ${NAME}

$(NAME)	: ${OBJS}
	${CC} ${CFLAGS} ${DEPF} ${OBJS} -o $@

%.o:%.cpp
	${CC} ${CFLAGS} ${DEPF} -c $< -o $@

clean:	
	${RM} ${DEP} ${OBJS}
fclean: clean
	${RM} ${NAME}

re: fclean all

.PHONY: all clean fclean re

-include ${DEP}
