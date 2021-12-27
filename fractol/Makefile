SRCS	=	./funcs/fractol.c ./funcs/utils.c ./funcs/pars_init.c \
			./funcs/julia.c ./funcs/colors.c ./funcs/key_mouse.c \
			./funcs/mandelbrot.c ./funcs/bonus.c

OBJ_SRC = ${SRCS:.c=.o}

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

all: ${NAME}

bonus: all

clean:
	${REM} ${OBJ_SRC} ${OBJ_B}

fclean: clean
	${REM} ${OBJ_SRC} ${OBJ_B} ${NAME} ${BONUS}
	
re: fclean all