# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: thgaugai <thgaugai@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/03/20 08:14:42 by hfeufeu           #+#    #+#              #
#    Updated: 2025/03/31 16:57:55 by thgaugai         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS = 	main/main.c \
		parsing/ft_split_operator.c \
		parsing/sort_arguments.c \
		parsing/utils_parsing.c \
		parsing/check_operator_glued.c \
		parsing/signal_handler.c \
		parsing/tokeniser.c \
		parsing/tokeniser_utils.c\
		parsing/lexing.c \
		parsing/free_parsing.c\
		main/ft_free.c \
		builtins/builtins.c \
		builtins/ft_cd.c \
		builtins/ft_echo.c \
		builtins/ft_env.c \
		builtins/ft_exit.c \
		builtins/ft_export.c \
		builtins/ft_pwd.c \
		builtins/ft_unset.c \
		builtins/builtins_utils.c \
		exec/exec.c \
		exec/exec_utils.c \
		exec/redirection.c\
		exec/here_doc.c\
		exec/pipe.c\
		exec/env_variable.c \

SRCDIR := src
SRCS := $(addprefix $(SRCDIR)/, $(SRCS))

OBJDIR := .build
OBJS := $(addprefix $(OBJDIR)/, $(SRCS:.c=.o))

CC = cc
CFLAGS = -Wall -Werror -Wextra -g
LDFLAGS = -lreadline
IFLAGS = -I ./includes
LIBFT = libft/libft.a

NAME = minishell

all: $(LIBFT) $(NAME)

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) -o $(NAME) $(OBJS) $(LIBFT) $(LDFLAGS)
	@echo "\033[1;32mMINISHELL compiled successfully!\033[0m"

$(LIBFT):
	@make -C libft

$(OBJDIR)/%.o: %.c
	@mkdir -p $(dir $@)
	$(CC) $(CFLAGS) $(IFLAGS) -g -c $< -o $@

clean:
	rm -rf $(OBJDIR)
	@make -C libft clean

fclean: clean
	rm -f $(NAME)
	@make -C libft fclean

re: fclean all

.PHONY: all clean fclean re