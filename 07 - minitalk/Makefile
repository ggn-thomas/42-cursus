SRCS = serveur.c client.c
SRCS_BONUS = serveur_bonus.c client_bonus.c

OBJS = $(SRCS:.c=.o)
OBJS_BONUS = $(SRCS_BONUS:.c=.o)

CC = clang
CFLAGS = -Wall -Werror -Wextra
LIBFT = libft/libft.a

all: server client

server: serveur.o $(LIBFT)
	$(CC) -o $@ serveur.o $(LIBFT)
	@echo "\033[1;32m$ SERVEUR compiled successfully!\033[0m"

client: client.o $(LIBFT)
	$(CC) -o $@ client.o $(LIBFT)
	@echo "\033[1;32m$ CLIENT compiled successfully!\033[0m"

bonus: server_bonus client_bonus

server_bonus: serveur_bonus.o $(LIBFT)
	$(CC) -o $@ $< -Llibft -lft
	@echo "\033[1;32m$ SERVER_BONUS compiled successfully!\033[0m"

client_bonus: client_bonus.o $(LIBFT)
	$(CC) -o $@ $< -Llibft -lft
	@echo "\033[1;32m$ CLIENT_BONUS compiled successfully!\033[0m"

$(LIBFT):
	@make -C libft

clean:
	rm -f $(OBJS) $(OBJS_BONUS)
	@make -C libft clean

fclean: clean
	rm -f server client server_bonus client_bonus
	@make -C libft fclean

re: fclean all

.PHONY: all bonus clean fclean re
