CC = cc
CFLAGS = -Wall -Wextra -Werror -g
INCLUDES = -I
SRC = \
	ft_printf.c\
	percent.c\
	utilis.c\

OBJ = $(SRC:.c=.o)
NAME = libftprintf.a

all: $(NAME)

$(NAME): $(OBJ)
	ar rcs $(NAME) $(OBJ)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re