SRCS_PRINTF		=	./srcs/./printf/ft_printf.c ./srcs/./printf/ft_putchar.c ./srcs/./printf/ft_putdnbr.c \
					./srcs/./printf/ft_putendl.c ./srcs/./printf/ft_puthex.c ./srcs/./printf/ft_puthexup.c \
					./srcs/./printf/ft_putnbr.c ./srcs/./printf/ft_putstr.c ./srcs/./printf/ft_putvoid.c 

SRCS_LIBFT		=	./srcs/./libft/ft_atoi.c ./srcs/./libft/ft_bzero.c ./srcs/./libft/ft_calloc.c \
					./srcs/./libft/ft_isalnum.c ./srcs/./libft/ft_isalpha.c ./srcs/./libft/ft_isascii.c \
					./srcs/./libft/ft_isdigit.c ./srcs/./libft/ft_isprint.c ./srcs/./libft/ft_itoa.c \
					./srcs/./libft/ft_memchr.c ./srcs/./libft/ft_memcmp.c ./srcs/./libft/ft_memcpy.c \
					./srcs/./libft/ft_memmove.c ./srcs/./libft/ft_memset.c ./srcs/./libft/ft_split.c \
					./srcs/./libft/ft_strchr.c ./srcs/./libft/ft_strdup.c ./srcs/./libft/ft_strjoin.c \
					./srcs/./libft/ft_strlcat.c ./srcs/./libft/ft_strlcpy.c ./srcs/./libft/ft_strlen.c \
					./srcs/./libft/ft_strncmp.c ./srcs/./libft/ft_strnstr.c ./srcs/./libft/ft_strrchr.c \
					./srcs/./libft/ft_strtrim.c ./srcs/./libft/ft_substr.c ./srcs/./libft/ft_tolower.c \
					./srcs/./libft/ft_toupper.c ./srcs/./libft/ft_putchar_fd.c ./srcs/./libft/ft_putendl_fd.c \
					./srcs/./libft/ft_putnbr_fd.c ./srcs/./libft/ft_putstr_fd.c ./srcs/./libft/ft_striteri.c \
					./srcs/./libft/ft_strmapi.c ./srcs/./libft/ft_lstnew.c  ./srcs/./libft/ft_lstadd_front.c \
					./srcs/./libft/ft_lstsize.c ./srcs/./libft/ft_lstlast.c ./srcs/./libft/ft_lstadd_back.c \
					./srcs/./libft/ft_lstdelone.c ./srcs/./libft/ft_lstclear.c ./srcs/./libft/ft_lstiter.c \
					./srcs/./libft/ft_lstmap.c	

OBJ_SRC = $(SRCS_PRINTF:.c=.o)
OBJ_LIB = $(SRCS_LIBFT:.c=.o)

NAME = libftprintf.a

CC = gcc

REM = rm -f

HEADER = ./srcs/./printf/ft_printf.h

HEADER_LIB = ./srcs/./libft/libft.h

FLAGS = -Wall -Wextra -Werror

.PHONY: all clean fclean re

all: $(NAME)

$(NAME): $(OBJ_SRC) $(OBJ_LIB)
			ar rc $(NAME)  $(OBJ_SRC) $(OBJ_LIB)
			ranlib $(NAME)

%.o:	%.c $(HEADER) $(HEADER_LIB)
			$(CC) $(FLAGS) -c $< -o $@

clean:
	$(REM) $(OBJ_SRC) $(OBJ_LIB)

fclean: clean
	$(REM) $(NAME) $(OBJ_LIB)

re: fclean all
# ar rc $(NAME) ./libft/*.o ./srcs.*.o