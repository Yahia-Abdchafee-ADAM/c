#include "snake.h"
#include <ncurses.h>
#include <unistd.h>
#include <stdlib.h>

int snake_game_loop(snake_t *snake)
{
    int ch = RIGHT;
    int o_x = 0;
    int o_y = 0;
    int test_ch = 0;
    int speed = 100000;
    int i = 0;

    initscr();
    noecho();
    curs_set(0);
    nodelay(stdscr, true);
    start_color();
    getmaxyx(stdscr, snake->y_max, snake->x_max);
    snake->y[0] = snake->y_max / 2;
    snake->y[1] = snake->y_max / 2;
    snake->y[2] = snake->y_max / 2;
    o_x = random_number(13, snake->x_max - 13);
    o_y = random_number(13, snake->y_max - 13);
    snake_border(snake);
    init_color_snake();
    while (1) {
        mvprintw(1, 6, "Your score: %i", snake->score);
        if (snake->border_mode == true) {
            for (int i = 0; i != snake->size_border; i++)
                mvprintw(snake->border_y[i], snake->border_x[i], "x");
            for (int i = 0; i != snake->size_border; i++) {
                if (snake->border_x[i] == snake->x[snake->size] && snake->border_y[i] == snake->y[snake->size]) {
                    clear();
                    endwin();
                    snake_end(snake);
                }
            }
        }
        attron(COLOR_PAIR(MAGENTA));
        for (int i = 0; i < snake->size; i++)
            mvprintw(snake->y[i], snake->x[i], SNAKE);
        mvprintw(snake->y[snake->size], snake->x[snake->size], HEAD);
        attroff(COLOR_PAIR(MAGENTA));
        attron(COLOR_PAIR(GREEN));
        mvprintw(o_y, o_x, EAT);
        attroff(COLOR_PAIR(GREEN));
        if (snake->x[snake->size] == o_x && snake->y[snake->size] == o_y) {
            beep();
            snake->size++;
            snake->x[snake->size] = o_x;
            snake->y[snake->size] = o_y;
            snake->score++;
            o_x = random_number(13, snake->x_max - 13);
            o_y = random_number(13, snake->y_max - 13);
        }
        if ((test_ch = getch()) != ERR)
            ch = test_ch;
        refresh();
        usleep(speed - (10000 * snake->speed));
        clear();
        for (int i = 0; i != snake->size; i++) {
            snake->x[i] = snake->x[i + 1];
            snake->y[i] = snake->y[i + 1];
        }
        direction_menagement(ch, snake, snake->x_max, snake->y_max, snake->size);
    }
    endwin();
}
