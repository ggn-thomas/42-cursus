NAME = minitalk
CC = gcc
CFLAGS = -Wall -Werror -Wextra

LIBFT_PATH = ./libft
FT_PRINTF_PATH = ./ft_printf

SRV_SRC = serveur.c
CLT_SRC = client.c

SRV_OBJ = $(SRV_SRC:.c=.o)
CLT_OBJ = $(CLT_SRC:.c=.o)

all: client serveur

%.o: %.c
	$(CC) $(CFLAGS) -Iincludes -Ilibft -Ift_printf -c $< -o $@

client: $(CLT_OBJ)
	@make -C $(LIBFT_PATH)
	@make -C $(FT_PRINTF_PATH)
	$(CC) $(CLT_OBJ) -L$(LIBFT_PATH) -L$(FT_PRINTF_PATH) -lft -lft_printf -o $@

serveur: $(SRV_OBJ)
	@make -C $(LIBFT_PATH)
	@make -C $(FT_PRINTF_PATH)
	$(CC) $(SRV_OBJ) -L$(LIBFT_PATH) -L$(FT_PRINTF_PATH) -lft -lft_printf -o $@

clean:
	rm -f $(SRV_OBJ) $(CLT_OBJ)
	@make clean -C $(LIBFT_PATH)
	@make clean -C $(FT_PRINTF_PATH)

fclean: clean
	rm -f client serveur
	@make fclean -C $(LIBFT_PATH)
	@make fclean -C $(FT_PRINTF_PATH)


re: fclean all

libft:
	@make -C $(LIBFT_PATH)

.PHONY: all clean fclean re libft
