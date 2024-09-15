# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: plopez-b <plopez-b@student.42malaga.com    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/09/13 23:25:54 by plopez-b          #+#    #+#              #
#    Updated: 2024/09/15 19:00:03 by plopez-b         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

FLAGS			=	-g -I./src #-Wall -Werror -Wextra

TESTS			=	src/tests/matrix.cpp \
					src/tests/ex00.cpp \
					src/tests/ex01.cpp \
					src/tests/ex02.cpp \
					src/tests/ex03.cpp \
					src/tests/ex04.cpp \
					src/tests/ex05.cpp \
					src/tests/ex06.cpp \
					src/tests/ex07.cpp \
					src/tests/ex08.cpp \
					src/tests/ex09.cpp \
					src/tests/ex10.cpp \
					src/tests/ex11.cpp \
					src/tests/ex12.cpp \
					src/tests/ex13.cpp

SRCS			=	src/matrix.hpp \
					src/matrix.tpp \
					src/vector.tpp \
					src/ex00.tpp \
					src/ex01.tpp \
					src/ex02.tpp \
					src/ex03.tpp \
					src/ex04.tpp \
					src/ex05.tpp \
					src/ex06.tpp \
					src/ex07.tpp \
					src/ex08.tpp \
					src/ex09.tpp \
					src/ex10.tpp \
					src/ex11.tpp \
					src/ex12.tpp \
					src/ex13.tpp

BINS			=	$(addprefix bin/, $(TESTS:.cpp=))

COMPILER 		=	g++

all:			${BINS}

bin/%: %.cpp ${SRCS}
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
