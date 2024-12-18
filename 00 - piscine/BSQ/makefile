# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: thgaugai <thgaugai@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/07/27 18:29:30 by asmith            #+#    #+#              #
#    Updated: 2024/07/31 11:41:26 by thgaugai         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #


SRC = builders.c main.c
OBJ = builders.o main.o
CC = cc
DEPS = hearder.h
CFLAGS = -Wall -Werror -Wextra
EXEC = BSQ

all: $(EXEC)
 
%.o: %.c $(DEPS)
	$(CC) -o $@ -c $< $(CFLAGS)
	
$(EXEC): $(OBJ)
	$(CC) -o $@ $^ $(CFLAGS)

clean:
	rm -f $(OBJ)
	
fclean: clean
	rm -f $(EXEC)

re: fclean all
