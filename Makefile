# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: plopez-b <plopez-b@student.42malaga.com    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/09/13 23:25:54 by plopez-b          #+#    #+#              #
#    Updated: 2024/09/14 16:35:16 by plopez-b         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

FLAGS			=	-g -Wall -Werror -Wextra -I./src

TESTS			=	src/tests/matrix.cpp \
					src/tests/ex00.cpp \
					src/tests/ex01.cpp \
					src/tests/ex02.cpp \
					src/tests/ex03.cpp

BINS			=	$(addprefix bin/, $(TESTS:.cpp=))

COMPILER 		=	g++

all:			${BINS}

bin/%: %.cpp
	@mkdir -p $(dir $@)
	${COMPILER} ${FLAGS} $< -o $@

test:			${BINS} ${TESTS}
	$(foreach EXE, $(BINS), $(EXE);)

valgrind:		${BINS} ${TESTS}
	$(foreach EXE, $(BINS), \
		valgrind --leak-check=full --track-origins=yes \
		--error-exitcode=1 $(EXE); \
	)

clean:
	@rm -rf ${BINS} bin/

fclean:	clean

re:		fclean all

.PHONY: all test valgrind clean fclean re
