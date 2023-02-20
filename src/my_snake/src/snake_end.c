#include "snake.h"
#include <ncurses.h>
#include <unistd.h>
#include <stdlib.h>

void restart()
{
    snake_t *snake = initialisation_snake();
    snake_game_loop(snake);
}

int snake_end(snake_t *snake)
{
    int i = 0;
    int choice = 0;
    int ch = 0;
    int test_ch = 0;
    char **end_choice = my_strtok(read_file("config/end_choice.txt"), "\n");
    char **end = my_strtok(read_file("config/game_over_template.txt"), "\n");

    initscr();
    noecho();
    curs_set(0);
    start_color();
    init_color_snake();
    nodelay(stdscr, true);
    getmaxyx(stdscr, snake->y_max, snake->x_max);
    while(1) {
        attron(COLOR_PAIR(RED));
        for (i = 0; end[i] != NULL; i++)
            mvprintw(5 + i, ((snake->x_max / 2) - 25), end[i]);
        i += 7;
        attroff(COLOR_PAIR(RED));
        attron(COLOR_PAIR(GREEN));
        mvprintw(i , ((snake->x_max / 2) - 8), "Your score: %i", snake->score);
        attroff(COLOR_PAIR(GREEN));
        attron(COLOR_PAIR(CYAN));
        for (int j = 0; end_choice[j] != NULL; j++)
            mvprintw(i + j, ((snake->x_max / 2) - 27), end_choice[j]);
        attroff(COLOR_PAIR(CYAN));
        for (int j = 0; end_choice[j] != NULL; j++)
            for (int o = 0; end_choice[j][o] != '\0'; o++) {
                if (choice == 0 && end_choice[j][o] == 'R') {
                    attron(COLOR_PAIR(SCREEN_GREEN));
                    mvprintw((i + j), ((snake->x_max / 2) - 27) + o, "restart");
                    attroff(COLOR_PAIR(SCREEN_GREEN));
                }
                if (choice == 1 && end_choice[j][o] == 'Q') {
                    attron(COLOR_PAIR(SCREEN_GREEN));
                    mvprintw((i + j), ((snake->x_max / 2) - 27) + o, "Quit");
                    attroff(COLOR_PAIR(SCREEN_GREEN));
                }
                if (choice == 2 && end_choice[j][o] == 'M') {
                    attron(COLOR_PAIR(SCREEN_GREEN));
                    mvprintw((i + j), ((snake->x_max / 2) - 27) + o, "Menu");
                    attroff(COLOR_PAIR(SCREEN_GREEN));
                }
            }
        if ((test_ch = getch()) != ERR) {
            ch = test_ch;
            if (ch == ENTER && choice == 0)
                restart();
            if (ch == ENTER && choice == 1) {
                endwin();
                exit(0);
                return (0);
            }
            if (ch == ENTER && choice == 2) {
                menu_snake(snake);
                return (0);
            }
            if (ch == LEFT) {
                choice--;
                if (choice < 0)
                    choice = 2;
            }
            if (ch == RIGHT) {
                choice++;
                if (choice > 2)
                    choice = 0;
            }
        }
        refresh();
        usleep(10000);
        clear();
    }
}