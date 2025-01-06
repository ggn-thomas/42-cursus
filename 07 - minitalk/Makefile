NAME = minitalk
CC = gcc
CFLAGS = -Wall -Werror -Wextra

LIBFT_PATH = ./libft
FT_PRINTF_PATH = ./ft_printf

SRC = 	client.c\
		serveur.c\

OBJS = $(SRC:.c=.o)

all: $(NAME)

$(NAME): $(OBJS)
	@echo "\033[0;33mCompiling libraries...\033[0m"
	@make -C $(LIBFT_PATH)
	@make -C $(FT_PRINTF_PATH)
	@echo "\033[0;33mLinking $(NAME)...\033[0m"
	$(CC) $(CFLAGS) $(OBJS) $(LDFLAGS) -o $(NAME)
	@echo "\033[1;32m$(NAME) compiled successfully!\033[0m"

%.o: %.c
	@echo "\033[0;34mCompiling $<...\033[0m"
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	@echo "\033[0;31mCleaning object files...\033[0m"
	@rm -f $(OBJS)
	@make clean -C $(LIBFT_PATH)
	@make clean -C $(FT_PRINTF_PATH)
	@echo "\033[1;32mObject files cleaned!\033[0m"

fclean: clean
	@echo "\033[0;31mCleaning $(NAME)...\033[0m"
	@rm -f $(NAME)
	@make fclean -C $(LIBFT_PATH)
	@make fclean -C $(FT_PRINTF_PATH)
	@echo "\033[1;32m$(NAME) cleaned!\033[0m"

re: fclean all

.PHONY: all clean fclean re
