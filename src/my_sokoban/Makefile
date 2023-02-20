SRC	=	src/main_sokoban.c			\
		src/my_sokoban.c			\
		src/read_file.c				\
		src/my_str_to_world_arr.c 	\
		src/verif_game_over.c		\
		src/cheak_direction.c		\
		src/pose_o.c				\
		src/pose_p.c				\
		src/ending_game_and_free.c	\
		src/my_pop.c				\
		src/handling_error.c		\
		src/help.c					\
		src/open_directory.c		\
		src/time.c					\
		src/do_my_array.c			\
		src/main.c					\

SRC_TEST =	lib/my/my_putchar.c			\
			lib/my/my_put_nbr.c			\
			lib/my/my_putstr.c			\
			lib/my/my_strlen.c			\
			src/my_sokoban.c			\
			src/read_file.c				\
			src/my_str_to_world_arr.c 	\
			src/verif_game_over.c		\
			src/cheak_direction.c		\
			src/pose_o.c				\
			src/pose_p.c				\
			src/ending_game_and_free.c	\
			src/my_pop.c				\
			src/handling_error.c		\
			src/help.c					\

OBJ	=	$(SRC:.c=.o)

BINARY_NAME	=	my_sokoban

MAKE 	=	make

INCLUDE	=	include/

LIB	=		my

LIB_MY	=	lib/my

LIB_MY2	=	lib

CPPFLAGS	=	-I./$(INCLUDE)

LDFLAGS	=	-L $(LIB_MY2) -l$(LIB)

all:		Make NAME

NAME:
			gcc $(SRC) \
			-o $(BINARY_NAME) $(CPPFLAGS) $(LDFLAGS) -l$(LIB) -lncurses \
			-lcsfml-graphics -lcsfml-system -lcsfml-audio -lpthread

tests_run: Make
		gcc -o test $(SRC_TEST) ./tests/test_my_sokoban.c \
		--coverage -lcriterion $(CPPFLAGS) $(LDFLAGS) -l$(LIB) -lncurses
		./test

Make:
			$(MAKE) -C $(LIB_MY)

clean_all:
			rm -f $(OBJ)
			make fclean -C $(LIB_MY)
			rm -f $(BINARY_NAME)
			rm -f test
			rm -f *.gcda
			rm -f *.gcno
			rm -f *~
			rm -f *.o

clean:
			rm -f $(OBJ)

fclean:		clean
			make fclean -C $(LIB_MY)
			rm -f $(BINARY_NAME)

re:			fclean all
			rm -f $(OBJ)
