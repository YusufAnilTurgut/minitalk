NAME = minitalk.a

CC = gcc

CFLAGS = -Wall -Werror -Wextra

SRC =

OBJ = $(SRC:.c=.o)

all : $(NAME)

@(NAME) :
		$(CC) $(CFLAGS) -c $(SRC)
		ar -rcs $(NAME) $(OBJ)
re : fclean all

clean :
	rm -rf $(OBJ)

fclean : clean
	rm -rf $(NAME)

.PHONY: all bonus clean fclean re