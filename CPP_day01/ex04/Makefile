# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mlecuyer@student.42.fr <mlecuyer>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/10/25 10:54:51 by user42            #+#    #+#              #
#    Updated: 2021/12/08 15:58:32 by mlecuyer@st      ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS = main.cpp
OBJS = $(addprefix ${OBJDIR}/,${SRCS:.cpp=.o})
NAME = replace
DEPF = -MMD -MP
DEP = ${OBJS:.o=.d}
OBJDIR = helper_files
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
	rm tests/*.replace

fclean: clean
	${RM} ${NAME}

re: fclean all

.PHONY: all clean fclean re

-include ${DEP}
