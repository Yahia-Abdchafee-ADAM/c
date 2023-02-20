#include "snake.h"
#include <unistd.h>

void direction_menagement(int ch, snake_t *snake, int x_max, int y_max, int size)
{
    if (ch == RIGHT) {
        if (snake->x[size] >= x_max)
            snake->x[size] = 1;
        snake->x[size] += 1;
    }
    if (ch == LEFT) {
        if (snake->x[size] <= 0)
            snake->x[size] = x_max;
        snake->x[size] -= 1;
    }
    if (ch == UP) {
        usleep(10000);
        if (snake->y[size] <= 0)
            snake->y[size] = y_max;
        snake->y[size] -= 1;
    }
    if (ch == DOWN) {
        usleep(10000);
        if (snake->y[size] >= y_max)
            snake->y[size] = 1;
        snake->y[size] += 1;
    }
}
