SRCS = serveur.c client.c
SRCS_BONUS = serveur_bonus.c client_bonus.c

OBJS = $(SRCS:.c=.o)
OBJS_BONUS = $(SRCS_BONUS:.c=.o)

CC = gcc
CFLAGS = -Wall -Werror -Wextra

all: server client server_bonus client_bonus

server : serveur.o libft
		$(CC) -o $@ $< -Llibft -lft
		@echo "\033[1;32m$ SERVEUR compiled successfully!\033[0m"

client : client.o libft
		$(CC) -o $@ $< -Llibft -lft
		@echo "\033[1;32m$ CLIENT compiled successfully!\033[0m"

server_bonus : serveur_bonus.o libft
		$(CC) -o $@ $< -Llibft -lft

client_bonus : client_bonus.o libft
		$(CC) -o $@ $< -Llibft -lft

%.o: %.c
		$(CC) $(CFLAGS) -c $< -o $@
libft :
		make -C libft

clean :
		rm -f $(OBJS) $(OBJS_BONUS)
		make -C libft clean

fclean : clean
		rm -f server client server_bonus client_bonus libft/libft.a

re : fclean all

.PHONY: all libft clean fclean re
