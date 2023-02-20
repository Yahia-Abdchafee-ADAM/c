#include "snake.h"
#include <ncurses.h>
#include <stdlib.h>

void init_color_snake(void)
{
    start_color();
    init_pair(GREEN, COLOR_GREEN, COLOR_BLACK);
    init_pair(MAGENTA, COLOR_MAGENTA, COLOR_BLACK);
    init_pair(CYAN, COLOR_CYAN, COLOR_BLACK);
    init_pair(RED, COLOR_RED, COLOR_BLACK);
    init_pair(SCREEN_GREEN, COLOR_BLACK, COLOR_GREEN);
}

snake_t *initialisation_snake(void)
{
    snake_t *snake = malloc(sizeof(snake_t));

    snake->x = malloc(sizeof(int) * 2000);
    snake->y = malloc(sizeof(int) * 2000);
    snake->speed = 5;
    snake->score = 0;
    snake->border_mode = true;
    snake->x[0] = 1;
    snake->x[1] = 2;
    snake->y[0] = snake->y_max / 2;
    snake->y[1] = snake->y_max / 2;
    snake->y[2] = snake->y_max / 2;
    snake->x[2] = 3;
    snake->size = 2;
    return (snake);
}