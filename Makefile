MY_SOKOBAN = src/my_sokoban

MY_SNAKE	= src/my_snake

MY_TETRIS	= src/my_tetris

MY_BATTLESHIP	= src/my_battleship

BIN				=	my_games

all:
	make -C $(MY_SOKOBAN)
	make -C $(MY_SNAKE)
	make -C $(MY_TETRIS)
	make -C $(MY_BATTLESHIP)
	gcc -o $(BIN) src/main.c

clean:
	make clean -C $(MY_SOKOBAN)
	make clean -C $(MY_SNAKE)
	make clean -C $(MY_TETRIS)
	make clean -C $(MY_BATTLESHIP)
	rm $(BIN)

fclean:	clean
	make fclean -C $(MY_SOKOBAN)
	make fclean -C $(MY_SNAKE)
	make fclean -C $(MY_TETRIS)
	make fclean -C $(MY_BATTLESHIP)

re:	fclean all