#include <ncurses.h>
#include <unistd.h>
#include "snake.h"
#include <stdlib.h>

void snake_border(snake_t *snake)
{
    int count = 0;
    int i = 0;

    snake->border_x = malloc(sizeof(int) * ((snake->x_max + snake->y_max) * 2));
    snake->border_y = malloc(sizeof(int) * ((snake->x_max + snake->y_max) * 2));
    for (snake->size_border = 0; snake->size_border != (snake->y_max / 2) - 6; snake->size_border++) {
        snake->border_y[snake->size_border] = snake->size_border + 2;
        snake->border_x[snake->size_border] = 6;
    }
    for (snake->size_border = snake->size_border + 6; snake->size_border != snake->y_max - 6; snake->size_border++) {
        snake->border_y[snake->size_border - 6] = snake->size_border + 2;
        snake->border_x[snake->size_border - 6] = 6;
    }
    count = snake->size_border + 1;
    snake->size_border -= 7;
    for (i = 0; i != (snake->x_max / 2) - 12; i++, snake->size_border++) {
        snake->border_y[snake->size_border] = count;
        snake->border_x[snake->size_border] = 6 + i;
    }
    for (i += 12; i != snake->x_max - 24; i++, snake->size_border++) {
        snake->border_y[snake->size_border] = count;
        snake->border_x[snake->size_border] = 12 + i;
    }
    for (i = 0; i != (snake->x_max / 2) - 12; i++, snake->size_border++) {
        snake->border_y[snake->size_border] = 2;
        snake->border_x[snake->size_border] = 6 + i;
    }
    for (i += 12; i != snake->x_max - 24; i++, snake->size_border++) {
        snake->border_y[snake->size_border] = 2;
        snake->border_x[snake->size_border] = 12 + i;
    }
    count = 12 + i;
    for (i = 0; i != (snake->y_max / 2) - 6; i++, snake->size_border++) {
        snake->border_y[snake->size_border] = i + 2;
        snake->border_x[snake->size_border] = count;
    }
    for (i = i + 6; i != snake->y_max - 6; i++, snake->size_border++) {
        snake->border_y[snake->size_border] = i + 2;
        snake->border_x[snake->size_border] = count;
    }
}