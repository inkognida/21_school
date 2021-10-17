SRCS		=	ft_printf.c ft_putchar.c ft_putdnbr.c \
				ft_putendl.c ft_puthex.c ft_puthexup.c \
				ft_putnbr.c ft_putstr.c ft_putvoid.c 


OBJ_SRC = $(SRCS:.c=.o)

OBJ_BONUS = $(BONUS_SRCS:.c=.o)

NAME = libftprintf.a

CC = gcc

REM = rm -f

LIBH = libftprintf.h

FLAGS = -Wall -Wextra -Werror

all: $(NAME)

$(NAME): $(OBJ_SRC)
			ar rc $(NAME) $(OBJ_SRC)
			ranlib $(NAME)

%.o:	%.c $(LIBH)
			$(CC) $(FLAGS) -c $< -o $@

clean:
	$(REM) $(OBJ_SRC) $(OBJ_BONUS) 

fclean: clean
	$(REM) $(NAME)

re: fclean all

.PHONY: all bonus clean fclean re