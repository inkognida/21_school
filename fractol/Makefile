SRCS	=	./funcs/fractol.c ./funcs/utils.c

SRCS_B	= 	./funcs/fractol.c

OBJ_SRC = ${SRCS:.c=.o}

OBJ_B = ${SRCS_B:.c=.o}

CC = gcc

NAME = fractol

REM = rm -f

HEADER = ./headers/fractol.h

FLAGS = -Wall -Wextra -Werror -g

.PHONY: all clean fclean re

%.o:	%.c ${HEADER}
			${CC} ${FLAGS} -Imlx -c $< -o $@

${NAME}: ${OBJ_SRC}
			${CC} ${FLAGS} ${OBJ_SRC} -lmlx -framework OpenGL -framework AppKit -o ${NAME}

${BONUS}: ${OBJ_B}
			${CC} ${FLAGS} ${OBJ_B} -o ${BONUS}

run: fractol
	./fractol

all: ${NAME} run

clean:
	${REM} ${OBJ_SRC} ${OBJ_B}

bonus: ${BONUS}

fclean: clean
	${REM} ${OBJ_SRC} ${OBJ_B} ${NAME} ${BONUS}
	
re: fclean all