/*
** ESGI PROJECT, 2022
** snake
** File description:
** snake
*/

#include <stdbool.h>

#ifndef SNAKE_H_
    #define SNAKE_H_

#define UP 65
#define DOWN 66
#define LEFT 68
#define RIGHT 67
#define ESCAP 27
#define RED 4
#define CYAN 3
#define GREEN 1
#define SCREEN_GREEN 5
#define MAGENTA 2
#define EAT "O"
#define HEAD "@"
#define SNAKE "X"
#define SPACE ' '
#define ENTER '\n'

typedef struct snake_s {
    int *x;
    int *y;
    int x_max;
    int y_max;
    int size;
    int speed;
    int score;
    bool border_mode;
    int *border_x;
    int *border_y;
    int size_border;
} snake_t;

void menu_snake();
void init_color_s(void);
snake_t *initialisation(void);
int snake_end(snake_t *snake);
void snake_border(snake_t *snake);
int snake_game_loop(snake_t *snake);
char *read_file(char const *filename);
int random_number(int min_num, int max_num);
char **my_strtok(char const *string, char *delimitor);
void direction_menagement(int ch, snake_t *snake, int x_max, int y_max, int size);
#endif /* !SNAKE_H_ */
