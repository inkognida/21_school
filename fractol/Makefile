SRCS	=	./funcs/fractol.c ./funcs/utils.c ./funcs/pars_init.c \
			./funcs/julia.c ./funcs/colors.c ./funcs/key_mouse.c \
			./funcs/mandelbrot.c ./funcs/bonus.c

OBJS = ${SRCS:.c=.o}

CC = gcc

NAME = fractol

REM = rm -f

HEADER = ./headers/fractol.h

CFLAGS = -Wall -Wextra -Werror

.PHONY: 	clean fclean all re bonus

all:		$(NAME)

.c.o:
			gcc $(CFLAGS) -c $< -o $@

$(NAME):	$(OBJS)
			make -C ./MinilibX
			gcc -o $(NAME) $(OBJS) $(CFLAGS) -lmlx -L./MinilibX -framework OpenGL -framework AppKit

clean:
			rm -f $(OBJS)

fclean: 	clean
			rm -f $(NAME)

re:			fclean all
