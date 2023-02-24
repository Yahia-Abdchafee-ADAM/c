##
## YAHIA ABDCHAFEE ADAM
## 
## 
## 
##

SRC	=	src/main_navy.c			\
		src/player_one.c	\
		src/player_two.c	\
		src/music.c			\
		src/my_int_to_str.c	\
		src/read_file.c		\
		src/write_in_file.c	\
		src/create_file.c	\
		src/my_strtok.c		\
		src/my_strcmp.c		\
		src/main.c			\
		src/map.c			\

OBJ	=	$(SRC:.c=.o)

BINARY_NAME	=	my_battleship

INCLUDE	=	include/

CPPFLAGS	=	-I./$(INCLUDE)

all:		$(OBJ)	BUILD

BUILD:
			gcc $(SRC) -o $(BINARY_NAME) $(CPPFLAGS)  -lcsfml-audio

clean:
			rm -f $(OBJ)

fclean:		clean
			rm -f $(BINARY_NAME)

re:			fclean all
			rm -f $(OBJ)