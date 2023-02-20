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
		src/attack_value.c	\
		src/my_strcmp.c		\

SRC_TEST =	

OBJ	=	$(SRC:.c=.o)

BINARY_NAME	=	navy

INCLUDE	=	include/

LDFLAGS	=	-L $(LIB_MY2) -l$(LIB)

LIB	=		my

LIB_MY	=	lib/my

LIB_MY2	=	lib

CPPFLAGS	=	-I./$(INCLUDE)

all:		$(OBJ) Make BUILD

BUILD:
			gcc $(SRC) -o $(BINARY_NAME) $(CPPFLAGS) $(LDFLAGS) -l$(LIB) -lcsfml-audio

tests_run: Make
		gcc -o test $(SRC_TEST) ./tests/test_navy.c \
		--coverage -lcriterion $(CPPFLAGS)
		./test
Make:
			$(MAKE) -C $(LIB_MY)

debug:
			gcc $(SRC) -o $(BINARY_NAME) $(CPPFLAGS) -lcsfml-audio -g3

clean:
			rm -f $(OBJ)
			make clean -C $(LIB_MY)

fclean:		clean
			rm -f $(BINARY_NAME)
			make fclean -C $(LIB_MY)

re:			fclean all
			rm -f $(OBJ)
