##
## ESGI PROJECT, 2021
## Makefile
## File description:
## make
##

SRC	=	src/main_tetris.c	\
		src/event_tetris.c	\
		src/display_tetris.c	\
		src/tetris_game_loop.c	\
		src/tetris_destroy.c	\
		src/random_number.c		\
		src/tetris_tetriminos.c	\
		src/tetris_map.c		\
		src/display_test.c		\

OBJ	=	$(SRC:.c=.o)

BINARY_NAME	=	my_tetris

INCLUDE	=	include/

CPPFLAGS	=	-I ./$(INCLUDE)

all:		NAME

NAME:		$(OBJ)
			gcc $(OBJ) -o $(BINARY_NAME) $(CPPFLAGS) -lSDL2 -lSDL2main -g3

clean:
			rm -f $(OBJ)

fclean:		clean
			rm -f $(BINARY_NAME)

re:			fclean all
			rm -f $(OBJ)
