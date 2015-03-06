CC =		gcc

RM =		rm -f

CFLAGS =	-Wall -Werror -Wextra -g3

LDFLAGS =	-lSDLmain -lSDL -lSDL_image	

SRC1 =		main.c \
	        init.c \
		map.c \
		init_ia.c \
		ia.c \
		msgq.c \
		check_around.c \
		win.c \
		move.c

SRC2 =		gui.c

OBJ1 =		$(SRC1:.c=.o)

OBJ2 =		$(SRC2:.c=.o)

NAME1 =		lemipc

NAME2 =		gui

all:		lemipc gui

lemipc:		$(OBJ1)
	$(CC) $(CFLAGS) $(OBJ1) -o $(NAME1)

gui:		$(OBJ2)
	$(CC) $(CFLAGS) $(OBJ2) -o $(NAME2) $(LDFLAGS)

clean:
	$(RM) $(OBJ1) $(OBJ2)

fclean:		clean
	$(RM) $(NAME1) $(NAME2)

re: fclean all

.PHONY: re all clean fclean
