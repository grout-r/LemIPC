CC =		gcc

RM =		rm -f

CFLAGS =	-Wall -Werror -Wextra -g3

LDFLAGS =	

SRC =		main.c \
	        init.c \
		map.c \
		ia.c

OBJ =		$(SRC:.c=.o)

NAME =		lemipc

all:		$(NAME)

$(NAME):	$(OBJ)
	$(CC) $(LDFLAGS) $(OBJ) -o $(NAME)

clean:
	$(RM) $(OBJ)

fclean:		clean
	$(RM) $(NAME)

re: fclean all

.PHONY: re all clean fclean
