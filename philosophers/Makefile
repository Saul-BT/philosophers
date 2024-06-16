NAME = philo
SOURCES = main.c parse.c
SOURCES += safe/alloc.c safe/mutex.c safe/thread.c safe/util.c

CC = gcc
CFLAGS = -g -Wall -Wextra -Werror

all: $(NAME)

$(NAME): $(SOURCES)
	@echo "Building $@"
	@$(CC) $(CFLAGS) $(SOURCES) -o $(NAME)

clean:
	@echo "Cleaning objects"

fclean: clean
	@echo "Cleaning executable"
	@rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re