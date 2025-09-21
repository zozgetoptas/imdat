NAME = push_swap
CC = cc 
CFLAGS = -Wall -Wextra -Werror

SRCS = sources/error_handling.c \
		sources/arg_checks.c \
		sources/easy_sorting.c \
		sources/easy_sorting_utils.c \
		sources/hard_sorting.c \
		sources/parsing.c \
		sources/main.c \
		sources/pushing.c \
		sources/swapping.c \
		sources/reverse_rotating.c \
		sources/rotating.c \
		sources/optimising.c \
		sources/chunk_sort_stuff.c \
		sources/chunk_sort_stuff_2.c \
		sources/normalize.c \

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