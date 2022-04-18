CC = gcc
SRCS = main.c init_data.c time.c atoi.c print.c start_prog.c check.c
NAME = philo
OBJS = $(SRCS:.c=.o)
CFLAGS = -Wall -Wextra -Werror -pthread
%.o:%.c *.h
	$(CC) $(CFLAGS) -c $< -o $@
all: *.h
	@$(MAKE) $(NAME)
$(NAME): $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -o $(NAME)
clean:
	rm -rf *.o
fclean: clean
	rm -rf $(NAME)
re: fclean all