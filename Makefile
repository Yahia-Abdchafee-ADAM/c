##
## ESGI PROJECT, 2021
## Makefile
## File description:
## make
##

SRC	=	src/main.c				\

SRC +=	src/my_tetris/src/main_tetris.c	\
		src/my_tetris/src/event_tetris.c	\
		src/my_tetris/src/display_tetris.c	\
		src/my_tetris/src/tetris_game_loop.c	\
		src/my_tetris/src/tetris_destroy.c	\
		src/my_tetris/src/random_number.c		\
		src/my_tetris/src/tetris_tetriminos.c	\
		src/my_tetris/src/tetris_map.c		\
		src/my_tetris/src/display_test.c		\

SRC +=	src/my_sokoban/src/main_sokoban.c			\
		src/my_sokoban/src/my_sokoban.c			\
		src/my_sokoban/src/read_file.c				\
		src/my_sokoban/src/verif_game_over.c		\
		src/my_sokoban/src/cheak_direction.c		\
		src/my_sokoban/src/pose_o.c				\
		src/my_sokoban/src/pose_p.c				\
		src/my_sokoban/src/ending_game_and_free.c	\
		src/my_sokoban/src/my_pop.c				\
		src/my_sokoban/src/handling_error.c		\
		src/my_sokoban/src/help.c					\
		src/my_sokoban/src/open_directory.c		\
		src/my_sokoban/src/my_getnbr.c					\
		src/my_sokoban/src/my_str_to_world_arr.c	\

SRC +=	src/my_snake/src/main_snake.c	\
		src/my_snake/src/init_snake.c	\
		src/my_snake/src/direction_menagement.c	\
		src/my_snake/src/snake_game_loop.c	\
		src/my_snake/src/my_strtok.c	\
		src/my_snake/src/snake_menu.c	\
		src/my_snake/src/snake_end.c		\
		src/my_snake/src/snake_border.c	\

SRC +=	src/my_battleship/src/main_navy.c			\
		src/my_battleship/src/player_one.c	\
		src/my_battleship/src/player_two.c	\
		src/my_battleship/src/music.c			\
		src/my_battleship/src/my_int_to_str.c	\
		src/my_battleship/src/write_in_file.c	\
		src/my_battleship/src/create_file.c	\
		src/my_battleship/src/attack_value.c	\
		src/my_battleship/src/my_strcmp.c		\

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
