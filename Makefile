CC = gcc
CFLAGS = -Wall -Wextra -Werror

NAME = push_swap

MANDATORY = parsing.c parsing_utils.c  utils.c libft.c

SRCS = $(MANDATORY)

OBJ = $(SRCS:.c=.o)

.c.o:
	${CC} ${CFLAGS} -c $< -o $(<:.c=.o)

all: $(NAME)

$(NAME): $(OBJ)
	$(CC) $(CFLAGS) $(OBJ) -o $(NAME)

clean:
	rm -f $(OBJB)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re