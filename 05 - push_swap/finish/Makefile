# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: thgaugai <thgaugai@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/10/10 14:16:03 by thgaugai          #+#    #+#              #
#    Updated: 2024/12/18 18:24:54 by thgaugai         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #


SRCS =  ./src/start_sort.c\
		./src/ft_push_swap_utils.c\
		./src/small_sort.c\
        ./src/push_swap.c\
		./command/swap_command.c\
		./command/rotate_command.c\
		./command/reverse_rotate_command.c\
		./command/push_command.c\
		./src/error_free.c\
		./src/stack_init.c\
		./src/stack_moves.c\

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
