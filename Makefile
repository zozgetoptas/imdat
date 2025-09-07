NAME = push_swap
CC = cc 
CFLAGS = -Wall -Wextra -Werror

SRCS = sources/error_handling.c \
		sources/arg_checks.c \
		sources/easy_sorting.c \
		sources/hard_sorting.c \
		sources/parsing.c \
		sources/main.c \
		sources/pushing.c \
		sources/swapping.c \
		sources/reverse_rotating.c \
		sources/rotating.c \
		sources/optimising.c \
		sources/getting_values.c \
		sources/getting_positions.c \

OBJS = $(SRCS:.c=.o)

all: $(NAME)

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -o $(NAME)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	$(RM) $(OBJS)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re