# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: aachhoub <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/01/16 19:05:40 by aachhoub          #+#    #+#              #
#    Updated: 2023/01/16 19:05:41 by aachhoub         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap
BONUS = checker

CC = clang

CFLAGS = -Wall -Wextra -Werror

SRC = ${addprefix ./src, /check_input.c /push_swap.c /move.c /operations2.c} \
	${addprefix ./src, /operations.c /position.c /sort.c /stack.c} \
	${addprefix ./src, 	/string_utils.c /utils2.c /utils.c}

SRCB = ${addprefix ./bonus, /check_input.c /operations2.c /stack.c /string_utils2.c} \
	${addprefix ./bonus, /operations.c /utils.c /checker_bonus.c /string_utils.c} \

all: ${NAME}

${NAME}: ${SRC}
	@echo "Compiling push_swap -_-"
	@${CC} ${CFLAGS} ${SRC} -o ${NAME}
	@echo "Done ^_^"

bonus : ${BONUS}

${BONUS} : ${NAME} ${SRCB}
	@echo "Compiling checker -_-"
	@${CC} ${CFLAGS} ${SRCB} -o ${BONUS}a	
	@echo "Done ^_^"

clean:
	@echo "There are no object files -_-"

fclean: clean
	@echo "Deleting executables -_-"
	@rm -f ${NAME} ${BONUS}
	@echo "Done ^_^"

re: fclean all

.PHONY: clean fclean re bonus
