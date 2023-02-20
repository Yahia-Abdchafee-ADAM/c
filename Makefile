##
## ESGI PROJECT, 2021
## Makefile
## File description:
## make
##

SRC	=	src/main.c				\
		src/my_tetris/src/*.c	\
		src/my_snake/src/*.c	\
		src/my_sokoban/src/*.c	\
		src/my_battleship/src/*.c	\

OBJ	=	$(SRC:.c=.o)

BINARY_NAME	=	my_games

INCLUDE			= include/
INCLUDE_tetris	=	src/my_tetris/include/
INCLUDE_snake 	= 	src/my_snake/include/
INCLUDE_sokoban	=	src/my_sokoban/include/
INCLUDE_battleship	=	src/my_battleship/include/

CPPFLAGS	=	-I ./$(INCLUDE)
CPPFLAGS	+=	-I ./$(INCLUDE_tetris)
CPPFLAGS	+=	-I ./$(INCLUDE_snake)
CPPFLAGS	+=	-I ./$(INCLUDE_sokoban)
CPPFLAGS	+=	-I ./$(INCLUDE_battleship)

all:		NAME

NAME:		$(OBJ)
			gcc $(OBJ) -o $(BINARY_NAME) $(CPPFLAGS) -lSDL2 -lSDL2main -lncurses \
			-lcsfml-graphics -lcsfml-system -lcsfml-audio -lpthread -lcsfml-audio

clean:
			rm -f $(OBJ)

fclean:		clean
			rm -f $(BINARY_NAME)

re:			fclean all
			rm -f $(OBJ)
