# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: votre_login <votre_login@student.42.fr>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/01/01 00:00:00 by votre_login      #+#    #+#              #
#    Updated: 2024/01/01 00:00:00 by votre_login     ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

RED = \033[1;31m
GREEN = \033[1;32m
YELLOW = \033[1;33m
BLUE = \033[1;34m
RESET = \033[0m

NAME_SERVER = server
NAME_CLIENT = client
NAME_SERVER_BONUS = server_bonus
NAME_CLIENT_BONUS = client_bonus

CC = cc
CFLAGS = -Wall -Wextra -Werror
RM = rm -f

SRC_DIR = ./srcs
LIBFT_DIR = ./libft
INCLUDE_DIR = ./includes


SRCS_SERVER = $(SRC_DIR)/serveur.c
SRCS_CLIENT = $(SRC_DIR)/client.c
SRCS_SERVER_BONUS = $(SRC_DIR)/serveur_bonus.c
SRCS_CLIENT_BONUS = $(SRC_DIR)/client_bonus.c


OBJS_SERVER = $(SRCS_SERVER:.c=.o)
OBJS_CLIENT = $(SRCS_CLIENT:.c=.o)
OBJS_SERVER_BONUS = $(SRCS_SERVER_BONUS:.c=.o)
OBJS_CLIENT_BONUS = $(SRCS_CLIENT_BONUS:.c=.o)

LIBFT = $(LIBFT_DIR)/libft.a

INCLUDES = -I$(INCLUDE_DIR) -I$(LIBFT_DIR)

all: $(LIBFT) $(NAME_SERVER) $(NAME_CLIENT)

$(NAME_SERVER): $(OBJS_SERVER) $(LIBFT)
	@echo "$(YELLOW)Compilation du serveur...$(RESET)"
	$(CC) $(CFLAGS) $(OBJS_SERVER) $(LIBFT) -o $(NAME_SERVER)
	@echo "$(GREEN)✓ $(NAME_SERVER) compilé avec succès!$(RESET)"

$(NAME_CLIENT): $(OBJS_CLIENT) $(LIBFT)
	@echo "$(YELLOW)Compilation du client...$(RESET)"
	$(CC) $(CFLAGS) $(OBJS_CLIENT) $(LIBFT) -o $(NAME_CLIENT)
	@echo "$(GREEN)✓ $(NAME_CLIENT) compilé avec succès!$(RESET)"

bonus: $(LIBFT) $(NAME_SERVER_BONUS) $(NAME_CLIENT_BONUS)

$(NAME_SERVER_BONUS): $(OBJS_SERVER_BONUS) $(LIBFT)
	@echo "$(YELLOW)Compilation du serveur bonus...$(RESET)"
	$(CC) $(CFLAGS) $(OBJS_SERVER_BONUS) $(LIBFT) -o $(NAME_SERVER_BONUS)
	@echo "$(GREEN)✓ $(NAME_SERVER_BONUS) compilé avec succès!$(RESET)"

$(NAME_CLIENT_BONUS): $(OBJS_CLIENT_BONUS) $(LIBFT)
	@echo "$(YELLOW)Compilation du client bonus...$(RESET)"
	$(CC) $(CFLAGS) $(OBJS_CLIENT_BONUS) $(LIBFT) -o $(NAME_CLIENT_BONUS)
	@echo "$(GREEN)✓ $(NAME_CLIENT_BONUS) compilé avec succès!$(RESET)"

%.o: %.c
	@echo "$(BLUE)Compilation de $<...$(RESET)"
	$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

$(LIBFT):
	@echo "$(YELLOW)Compilation de libft...$(RESET)"
	@make -C $(LIBFT_DIR)
	@echo "$(GREEN)✓ libft compilée avec succès!$(RESET)"

clean:
	@echo "$(RED)Suppression des fichiers objets...$(RESET)"
	$(RM) $(OBJS_SERVER) $(OBJS_CLIENT) $(OBJS_SERVER_BONUS) $(OBJS_CLIENT_BONUS)
	@make -C $(LIBFT_DIR) clean

fclean: clean
	@echo "$(RED)Suppression des exécutables...$(RESET)"
	$(RM) $(NAME_SERVER) $(NAME_CLIENT) $(NAME_SERVER_BONUS) $(NAME_CLIENT_BONUS)
	@make -C $(LIBFT_DIR) fclean

re: fclean all

.PHONY: all bonus clean fclean re test help
