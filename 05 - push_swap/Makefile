# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: thomas <thomas@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/10/10 14:16:03 by thgaugai          #+#    #+#              #
#    Updated: 2025/07/22 13:53:28 by thomas           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #


SRCS =   push_swap.c\
		./algorithms/start_sort.c\
		./algorithms/small_sort.c\
		./algorithms/stack_moves.c\
		./commands/swap_command.c\
		./commands/rotate_command.c\
		./commands/reverse_rotate_command.c\
		./commands/push_command.c\
		./utils/error_free.c\
		./utils/stack_init.c\
		./utils/ft_push_swap_utils.c\

OBJS := $(SRCS:.c=.o)

LIBFT_PATH = ./libft
LIBFT_FILE = libft.a
LIBFT = $(addprefix $(LIBFT_PATH)/, $(LIBFT_FILE))

NAME := push_swap

CC := cc
CFLAGS := -Wall -Werror -Wextra

all: $(NAME)

$(NAME): $(OBJS) $(LIBFT)
	$(CC) $(CFLAGS) $(OBJS) $(LIBFT) -o $(NAME)
	@echo "\033[1;32m$(NAME) compiled successfully!\033[0m"
$(LIBFT):
	@$(MAKE) -C $(LIBFT_PATH)

%.o : %.c
	$(CC) $(CFLAGS) -o $@ -c $<

clean:
	rm -f $(OBJS)
	@$(MAKE) clean -C $(LIBFT_PATH)

fclean: clean
	rm -f $(NAME)
	@$(MAKE) fclean -C $(LIBFT_PATH)

re: fclean all

.PHONY: re clean fclean all
