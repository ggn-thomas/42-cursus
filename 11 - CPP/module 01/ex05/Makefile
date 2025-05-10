# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: thomas <thomas@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/05/10 10:12:51 by thomas            #+#    #+#              #
#    Updated: 2025/05/10 10:22:00 by thomas           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS =  main.cpp \
		Harl.cpp\

OBJS = $(SRCS:.cpp=.o)

NAME = Harl

CC = c++
FLAGS = -Wall -Werror -Wextra -std=c++98

all: $(NAME)

$(NAME): $(OBJS)
	$(CC) $(FLAGS) $(OBJS) -o $(NAME)
	@echo "\033[1;32m$(NAME) compiled successfully!\033[0m"

%.o: %.cpp
	$(CC) $(FLAGS) -c $< -o $@

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: re clean fclean all