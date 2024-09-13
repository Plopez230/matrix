# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: plopez-b <plopez-b@student.42malaga.com    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/09/13 23:25:54 by plopez-b          #+#    #+#              #
#    Updated: 2024/09/14 00:36:23 by plopez-b         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

FLAGS			=	-Wall -Werror -Wextra -std=c++98 -I./src/include

TESTS			=	src/tests/matrix.cpp \
					src/tests/ex00.cpp

OBJ_TESTS		=	$(addprefix obj/, $(TESTS:.cpp=.o))

BIN_TESTS		=	$(addprefix bin/, $(TESTS:.cpp=))

COMPILER 		=	g++

all:			${OBJ_TESTS} ${BIN_TESTS}

obj/%.o: %.cpp
	@mkdir -p $(dir $@)
	@${COMPILER} ${FLAGS} -c $< -o $@

bin/%: obj/%.o
	@mkdir -p $(dir $@)
	@${COMPILER} ${FLAGS} $< -o $@
	valgrind --leak-check=full --track-origins=yes --error-exitcode=1 $@;
	
clean:
	@rm -rf ${OBJ_TESTS} ${BIN_TESTS} obj/ bin/

fclean:	clean
	@rm -f ${NAME} ${NAME_BONUS}

re:		fclean all

.PHONY: all clean fclean re
