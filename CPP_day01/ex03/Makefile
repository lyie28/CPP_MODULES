# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: user42 <marvin@42.fr>                      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/10/25 10:54:51 by user42            #+#    #+#              #
#    Updated: 2021/12/07 16:25:33 by lyie             ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS = main.cpp Weapon.cpp HumanA.cpp HumanB.cpp
OBJS = $(addprefix ${OBJDIR}/,${SRCS:.cpp=.o})
NAME = battle_of_Mordor
DEPF = -MMD -MP
OBJDIR = helper_files
DEP = ${OBJS:.o=.d})
CC = c++
RM = rm -f
CFLAGS = -Wall -Wextra -Werror -std=c++98 -g3
all: ${NAME}

$(NAME)	: ${OBJS}
	${CC} ${CFLAGS} ${DEPF} ${OBJS} -o $@

${OBJDIR}/%.o:%.cpp
	@mkdir -p ${@D}
	${CC} ${CFLAGS} ${DEPF} -c $< -o $@

clean:
	rm -rf ${OBJDIR}

fclean: clean
	${RM} ${NAME}

re: fclean all

.PHONY: all clean fclean re

-include ${DEP}
