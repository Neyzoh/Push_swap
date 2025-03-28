CC = gcc
CFLAGS = -Wall -Wextra -Werror

NAME = push_swap

MANDATORY = parsing.c parsing_utils.c  utils.c libft.c operations.c push_swap.c sort_big_list.c sort_utils.c

SRCS = $(MANDATORY)

OBJ = $(SRCS:.c=.o)

.c.o:
	${CC} ${CFLAGS} -c $< -o $(<:.c=.o)

all: $(NAME)

$(NAME): $(OBJ)
	$(CC) $(CFLAGS) $(OBJ) -o $(NAME)

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re