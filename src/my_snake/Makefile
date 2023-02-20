##
## ESGI PROJECT, 2021
## Makefile
## File description:
## make
##

SRC	=	src/main_snake.c	\
		src/random_number.c	\
		src/init_snake.c	\
		src/direction_menagement.c	\
		src/snake_game_loop.c	\
		src/read_file.c	\
		src/my_strtok.c	\
		src/snake_menu.c	\
		src/snake_end.c		\
		src/snake_border.c	\

OBJ	=	$(SRC:.c=.o)

BINARY_NAME	=	my_snake

INCLUDE	=	include/

CPPFLAGS	=	-I ./$(INCLUDE)

all:		NAME

NAME:		$(OBJ)
			gcc $(OBJ) -o $(BINARY_NAME) $(CPPFLAGS) -lncurses

clean:
			rm -f $(OBJ)

fclean:		clean
			rm -f $(BINARY_NAME)

re:			fclean all
			rm -f $(OBJ)
