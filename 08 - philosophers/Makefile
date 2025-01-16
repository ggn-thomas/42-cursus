SRCS =	ft_atoi.c\
		philo_init.c\
		routine.c\
		utils.c

OBJS = $(SRCS:.c=.o)

CC = cc
CFLAGS = -Wall -Werror

NAME = philosophers

all: $(NAME)

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) -o $(NAME) $(OBJS)

%.o: %.c
	$(CC) $(CFLAGS) -o $@ -c $<
	@echo "\033[1;32mPHILOSOPHERS compiled successfully!\033[0m"

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re

