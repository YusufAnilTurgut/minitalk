SERVER = server
SERVER_BONUS = server_bonus

CLIENT = client
CLIENT_BONUS = client_bonus

SRC_client = client.c
SRC_server = server.c
SRC_BONUS_client = client_bonus.c
SRC_BONUS_server = server_bonus.c

CC = gcc

CFLAGS = -Wall -Werror -Wextra

all: $(SERVER) $(CLIENT) $(PRINTF)

bonus: all $(CLIENT_BONUS) $(SERVER_BONUS) $(PRINTF)

$PRINTF:
		make -C ./utils/ft_printf

$(CLIENT):
		$(CC) $(CFLAGS) $(SRC_client) ./utils/ft_printf/libftprintf.a -o $(CLIENT)
$(SERVER):
		$(CC) $(CFLAGS) $(SRC_server) ./utils/ft_printf/libftprintf.a -o $(SERVER)
$(CLIENT_BONUS):
		$(CC) $(CFLAGS) $(SRC_BONUS_client) ./utils/ft_printf/libftprintf.a -o $(CLIENT_BONUS)
$(SERVER_BONUS):
		$(CC) $(CFLAGS) $(SRC_BONUS_server) ./utils/ft_printf/libftprintf.a -o $(SERVER_BONUS)

clean:
		@rm -rf $(SERVER) $(CLIENT) $(CLIENT_BONUS) $(SERVER_BONUS)

fclean: clean

re: fclean all

.PHONY: all clean fclean re bonus