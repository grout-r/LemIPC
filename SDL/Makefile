CC =		gcc -g3

RM =		rm -f

CFLAGS =	-Wall -Werror -Wextra -g3

LDFLAGS =	-lSDLmain -lSDL -lSDL_image 

SRC =		gui.c \

OBJ =		$(SRC:.c=.o)

NAME =		../gui

all:		$(NAME)

$(NAME):	$(OBJ)
	$(CC)  $(OBJ) -o $(NAME) $(LDFLAGS)

clean:
	$(RM) $(OBJ)

fclean:		clean
	$(RM) $(NAME)

re: fclean all

.PHONY: re all clean fclean
