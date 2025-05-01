# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: thgaugai <thgaugai@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/04/28 17:38:52 by thomas            #+#    #+#              #
#    Updated: 2025/05/01 15:33:28 by thgaugai         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS =  PhoneBook.cpp \
		contact.cpp \
		main.cpp

OBJS = $(SRCS:.cpp=.o)

NAME = PhoneBook

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
