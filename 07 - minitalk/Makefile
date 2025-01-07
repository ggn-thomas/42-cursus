SRCS = serveur.c client.c
OBJS = $(SRCS:.c=.o)

CC = gcc
CFLAGS = -Wall -Werror -Wextra

all: server client

server : serveur.o libft
		$(CC) -o $@ $< -Llibft -lft
		@echo "\033[1;32m$ SERVEUR compiled successfully!\033[0m"

client : client.o libft
		$(CC) -o $@ $< -Llibft -lft
		@echo "\033[1;32m$ CLIENT compiled successfully!\033[0m"
%.o: %.c
		$(CC) $(CFLAGS) -c $< -o $@
libft :
		make -C libft

clean :
		rm -f $(OBJS)
		make -C libft clean

fclean : clean
		rm -f server client libft/libft.a

re : fclean all

.PHONY: all libft clean fclean re
