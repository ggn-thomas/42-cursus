# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: thomas <thomas@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/05/28 14:52:39 by thgaugai          #+#    #+#              #
#    Updated: 2025/05/29 10:02:08 by thomas           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #


SRCS =  src/main.cpp \
		src/Dog.cpp\
		src/Cat.cpp\
		src/Animal.cpp\
		src/WrongAnimal.cpp\
		src/WrongCat.cpp\

OBJS = $(SRCS:.cpp=.o)

NAME = Animal

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
