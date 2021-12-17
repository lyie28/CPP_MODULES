# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: user42 <marvin@42.fr>                      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/10/25 10:54:51 by user42            #+#    #+#              #
#    Updated: 2021/12/03 14:45:16 by lyie             ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS = main.cpp ClapTrap.cpp ScavTrap.cpp FragTrap.cpp DiamondTrap.cpp
OBJS = $(addprefix ${OBJDIR}/,${SRCS:.cpp=.o})
NAME = Multi_inheritance_go
DEPF = -MMD -MP
DEP = ${OBJS:.o=.d}
OBJDIR = helper_files
CC = c++
RM = rm -f
CFLAGS = -Wall -Wextra -Werror -std=c++98 -g3 -Wno-shadow
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
