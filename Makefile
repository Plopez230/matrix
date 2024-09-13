# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: plopez-b <plopez-b@student.42malaga.com    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/09/13 23:25:54 by plopez-b          #+#    #+#              #
#    Updated: 2024/09/14 01:46:03 by plopez-b         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

FLAGS			=	-Wall -Werror -Wextra -std=c++98 -I./src

TESTS			=	src/tests/matrix.cpp \
					src/tests/ex00.cpp

BINS			=	$(addprefix bin/, $(TESTS:.cpp=))

COMPILER 		=	g++

all:			${BINS}

bin/%: %.cpp
	@mkdir -p $(dir $@)
	${COMPILER} ${FLAGS} $< -o $@

test:			${BINS}
	$(foreach EXE, $(BINS), $(EXE);)

valgrind:		${BINS}
	$(foreach EXE, $(BINS), \
		valgrind --leak-check=full --track-origins=yes \
		--error-exitcode=1 $(EXE); \
	)

clean:
	@rm -rf ${BINS} bin/

fclean:	clean

re:		fclean all

.PHONY: all test valgrind clean fclean re
