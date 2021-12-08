SRCS	=	./funcs/ft_split.c ./funcs/ft_strjoin.c ./funcs/ft_strnstr.c \
			./funcs/ft_utils.c ./funcs/pipex.c ./funcs/ft_errors.c \
			./funcs/ft_strncmp.c 

SRCS_B	= 	./funcs/ft_split.c ./funcs/ft_strjoin.c ./funcs/ft_strnstr.c \
			./funcs/ft_utils.c ./funcs/ft_errors.c \
			./funcs/ft_strncmp.c ./funcs/get_next_line.c ./funcs/get_next_line_utils.c \
			./funcs/pipex_bonus.c

OBJ_SRC = ${SRCS:.c=.o}

OBJ_B = ${SRCS_B:.c=.o}

CC = gcc

NAME = pipex

REM = rm -f

HEADER = ./headers/pipex.h

FLAGS = -Wall -Wextra -Werror -g

.PHONY: all clean fclean re

%.o:	%.c ${HEADER}
			${CC} ${FLAGS} -c $< -o $@

${NAME}: ${OBJ_SRC}
			${CC} ${FLAGS} ${OBJ_SRC} -o ${NAME}

all: ${NAME}

clean:
	${REM} ${OBJ_SRC} ${OBJ_B}

bonus: ${OBJ_B}
	${CC} ${FLAGS} ${OBJ_B} -o ${NAME}

fclean: clean
	${REM} ${OBJ_SRC} ${OBJ_B} ${NAME}

re: fclean all