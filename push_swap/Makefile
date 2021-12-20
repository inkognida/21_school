SRCS	=	./funcs/commands.c ./funcs/commands2.c ./funcs/commands3.c \
			./funcs/errors.c ./funcs/parsing.c ./funcs/push_bf.c \
			./funcs/push_swap.c ./funcs/sort_five.c ./funcs/sort_three.c \
			./funcs/sort_hund.c ./funcs/utils_sort.c ./funcs/utils_sort2.c \
			./funcs/utils.c 

SRCS_B	= 	./funcs/commands.c ./funcs/commands2.c ./funcs/commands3.c \
			./funcs/errors.c ./funcs/parsing.c ./funcs/push_bf.c \
			./funcs/checker_bonus.c ./funcs/sort_five.c ./funcs/sort_three.c \
			./funcs/sort_hund.c ./funcs/utils_sort.c ./funcs/utils_sort2.c \
			./funcs/utils.c 

OBJ_SRC = ${SRCS:.c=.o}

OBJ_B = ${SRCS_B:.c=.o}

CC = gcc

NAME = push_swap

BONUS = checker

REM = rm -f

HEADER = ./headers/push_swap.h

FLAGS = -Wall -Wextra -Werror -g

.PHONY: all clean fclean re

%.o:	%.c ${HEADER}
			${CC} ${FLAGS} -c $< -o $@

${NAME}: ${OBJ_SRC}
			${CC} ${FLAGS} ${OBJ_SRC} -o ${NAME}

${BONUS}: ${OBJ_B}
			${CC} ${FLAGS} ${OBJ_B} -o ${BONUS}

all: ${NAME}

clean:
	${REM} ${OBJ_SRC} ${OBJ_B}

bonus: ${BONUS}

fclean: clean
	${REM} ${OBJ_SRC} ${OBJ_B} ${NAME} ${BONUS}


re: fclean all