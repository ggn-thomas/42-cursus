# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: thomas <thomas@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/10/10 14:16:03 by thgaugai          #+#    #+#              #
#    Updated: 2024/10/17 16:44:24 by thomas           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #


SRCS =  ft_printf.c\
		ft_printf_utils.c\

OBJS := $(SRCS:.c=.o)

CC := cc 
FLAGS := -Wall -Werror -Wextra

NAME := libftprintf.a

all: $(NAME)

$(NAME): $(OBJS)
	ar -rc $(NAME) $(OBJS)

%.o : %.c
	$(CC) $(FLAGS) -o $@ -c $<

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: re clean fclean all
