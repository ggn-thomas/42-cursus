NAME        =   so_long

CC          =   gcc
CFLAGS      =   -Wall -Wextra -Werror -I$(INC_DIR) -I$(MLX_PATH) -I$(FT_PRINTF_PATH) -I$(LIBFT_PATH)/includes
LDFLAGS     =   -L$(MLX_PATH) -lmlx_Linux -L/usr/lib -lXext -lX11 -lm -lbsd -L$(FT_PRINTF_PATH) -lftprintf -L$(LIBFT_PATH) -lft

LIBFT_PATH  =   ./libft
FT_PRINTF_PATH = ./ft_printf
MLX_PATH    =   ./minilibx-linux

SRC_DIR     =   ./src
GNL_DIR     =   ./gnl
PARSING_DIR =   ./parsing
INC_DIR     =   ./includes

SRCS        =   $(SRC_DIR)/main.c \
                $(SRC_DIR)/map_init.c \
                $(SRC_DIR)/so_long_utils.c \
                $(SRC_DIR)/free.c \
                $(SRC_DIR)/window_init.c \
                $(SRC_DIR)/so_long_utils2.c \
                $(SRC_DIR)/window_draw.c \
				$(SRC_DIR)/player_moves.c \
                $(GNL_DIR)/get_next_line.c \
                $(GNL_DIR)/get_next_line_utils.c \
                $(PARSING_DIR)/check_valid_map.c \
				$(PARSING_DIR)/utils_parsing.c \
                $(PARSING_DIR)/flood_fill.c

OBJS        =   $(SRCS:.c=.o)

# Règle principale
all: $(NAME)

$(NAME): $(OBJS)
	@echo "\033[0;33mCompiling libraries...\033[0m"
	@make -C $(LIBFT_PATH)
	@make -C $(FT_PRINTF_PATH)
	@make -C $(MLX_PATH)
	@echo "\033[0;33mLinking $(NAME)...\033[0m"
	$(CC) $(CFLAGS) $(OBJS) $(LDFLAGS) -o $(NAME)
	@echo "\033[1;32m$(NAME) compiled successfully!\033[0m"

# Compilation des fichiers objets
%.o: %.c
	@echo "\033[0;34mCompiling $<...\033[0m"
	$(CC) $(CFLAGS) -c $< -o $@

# Nettoyage des fichiers objets
clean:
	@echo "\033[0;31mCleaning object files...\033[0m"
	@rm -f $(OBJS)
	@make clean -C $(LIBFT_PATH)
	@make clean -C $(FT_PRINTF_PATH)
	@make clean -C $(MLX_PATH)
	@echo "\033[1;32mObject files cleaned!\033[0m"

# Nettoyage complet
fclean: clean
	@echo "\033[0;31mCleaning $(NAME)...\033[0m"
	@rm -f $(NAME)
	@make fclean -C $(LIBFT_PATH)
	@make fclean -C $(FT_PRINTF_PATH)
	@echo "\033[1;32m$(NAME) cleaned!\033[0m"

# Rebuild
re: fclean all

# Déclaration des règles phony
.PHONY: all clean fclean re
