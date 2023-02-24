#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "navy.h"
void init_board(char **board) {
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            board[i][j] = '~';
        }
    }
}

void print_myboard(char **board) {
    printf("  | A  B  C  D  E  F  G  H  I  J |\n");
    printf("--+-------------------------------\n");
    for (int i = 0; i < SIZE; i++) {
        printf("%i |", i);
        for (int j = 0; j < SIZE; j++) {
            if (board[i][j] == '0')
                printf("%s[%c]%s", GREEN, board[i][j], RESET);
            else if (board[i][j] == '~')
                printf("%s[%c]%s", CYAN, board[i][j], RESET);
            else if (board[i][j] == '*')
                printf("%s[%c]%s", RED, board[i][j], RESET);
            else
                printf("[%c]", board[i][j]);
        }
        printf("|\n");
    }
    printf("\n");
}

int get_ship_number(char **map)
{
    int ship = 0;

    for (int i = 0; i != SIZE; i++) {
        for (int j = 0; j != SIZE; j++) {
            if (map[i][j] == '0')
                ship++;
        }
    }
    return (ship);
}

void print_ennemy_board(char **board) {
    printf("  | A  B  C  D  E  F  G  H  I  J |\n");
    printf("--+-------------------------------\n");
    for (int i = 0; i < SIZE; i++) {
        printf("%i |", i);
        for (int j = 0; j < SIZE; j++) {
            if (board[i][j] == '0')
                printf("%s[~]%s", CYAN, RESET);
            else if (board[i][j] == '~')
                printf("%s[%c]%s", CYAN, board[i][j], RESET);
            else if (board[i][j] == '*')
                printf("%s[%c]%s", RED, board[i][j], RESET);
            else
                printf("[%c]", board[i][j]);
        }
        printf("|\n");
    }
    printf("\n");
}

void place_ship(char **board, int size) {
    int dir = rand() % 2;
    int x, y;
    if (dir == 0) {
        x = rand() % (SIZE - size + 1);
        y = rand() % SIZE;
        for (int i = 0; i < size; i++) {
            board[y][x+i] = '0';
        }
    } else {
        x = rand() % SIZE;
        y = rand() % (SIZE - size + 1);
        for (int i = 0; i < size; i++) {
            board[y+i][x] = '0';
        }
    }
}

char **generate_random_map(void)
{
    char **board = (char**) malloc(SIZE * sizeof(char*));
    for (int i = 0; i < SIZE; i++) {
        board[i] = (char*) malloc(SIZE * sizeof(char));
    }

    srand(time(NULL));
    init_board(board);
    place_ship(board, 5);  // place un porte-avions de 5 cases
    place_ship(board, 4);  // place un croiseur de 4 cases
    place_ship(board, 3);  // place un contre-torpilleur de 3 cases
    place_ship(board, 3);  // place un sous-marin de 3 cases
    place_ship(board, 2);  // place un torpilleur de 2 cases
    return (board);
}
