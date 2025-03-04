CC = gcc
CFLAGS = -Wall -Wextra -Werror

NAME = push_swap

MANDATORY = 
SRCS = $(MANDATORY)

SRCSB = $(MANDATORY)

OBJ = $(SRCS:.c=.o)

OBJB = $(SRCSB:.c=.o)

.c.o:
	${CC} ${CFLAGS} -c $< -o $(<:.c=.o)

all: $(NAME)

$(NAME): $(OBJ)
	ar rcs $(NAME) $(OBJ)

clean:
	rm -f $(OBJB)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re