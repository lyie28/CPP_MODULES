# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: user42 <marvin@42.fr>                      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/10/25 10:54:51 by user42            #+#    #+#              #
#    Updated: 2022/01/06 14:57:13 by lyie             ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS = main.cpp Bureaucrat.cpp Form.cpp ShrubberyCreationForm.cpp RobotomyRequestForm.cpp PresidentialPardonForm.cpp Intern.cpp
OBJS = $(addprefix ${OBJDIR}/,${SRCS:.cpp=.o})
NAME = Intern
DEPF = -MMD -MP
DEP = ${OBJS:.o=.d}
OBJDIR = helper_files
INCLUDES = includes
CC = clang++
RM = rm -f
CFLAGS = -Wall -Wextra -Werror -std=c++98 -g3 -fsanitize=address
all: ${NAME}

$(NAME)	: ${OBJS}
	${CC} -I${INCLUDES} ${CFLAGS} ${DEPF} ${OBJS} -o $@

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
