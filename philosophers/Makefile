NAME = philo
SOURCES = main.c

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

.PHONY: all clean fclean