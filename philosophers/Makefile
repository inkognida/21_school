SRCS = ./funcs/philo.c ./funcs/utils.c ./funcs/parsing_threads.c 

SRCS_OBJ = ${SRCS:.c=.o}

NAME = philo

HEADER = ./headers/philo.h

REM = rm -f

CC = gcc

FLAGS = -Wall -Wextra -Werror -g

.PHONY: clean fclean re all

%.o:	%.c ${HEADER}
			${CC} ${FLAGS} -c $< -o $@
			
${NAME}: ${SRCS_OBJ}
			${CC} ${FLAGS} ${SRCS_OBJ} -o ${NAME}

all: ${NAME}

bonus: all

clean:
	${REM} ${SRCS_OBJ}

fclean: clean
	${REM} ${SRCS_OBJ} ${NAME}

re:	fclean all

# -fsanitize=address