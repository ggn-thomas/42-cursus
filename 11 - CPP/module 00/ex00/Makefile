# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: thomas <thomas@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/04/28 17:38:52 by thomas            #+#    #+#              #
#    Updated: 2025/04/28 17:50:46 by thomas           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS = megaphone.cpp

OBJS = $(SRCS:.cpp=.o)

NAME = megaphone

CC = c++
FLAGS = -Wall -Werror -Wextra

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
