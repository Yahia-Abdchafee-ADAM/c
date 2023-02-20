
#include "snake.h"
#include <ncurses.h>
#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>
#include <string.h>

void menu_snake()
{
    int ch = 0;
    int test_ch = 0;
    char speed_str[2];
    char border_on[] = "border on";
    char border_off[] = "border off";
    char *snake_map = read_file("config/snake_template.txt");
    char **my_snake = my_strtok(read_file("config/my_snake.txt"), "\n");
    char **menu_choise = my_strtok(read_file("config/menu_choice.txt"), "\n");
    snake_t *snake = initialisation();

    initscr();
    noecho();
    curs_set(0);
    start_color();
    init_color_s();
    nodelay(stdscr, true);
    getmaxyx(stdscr, snake->y_max, snake->x_max);
    while(1) {
        mvprintw((snake->y_max / 2) - 15, 1, snake_map);
        for (int i = 0; my_snake[i] != NULL; i++)
            mvprintw(i + 1, (65 + ((snake->x_max - 65) / 2) - 77), my_snake[i]);
        attron(COLOR_PAIR(CYAN));
        for (int i = 0; menu_choise[i] != NULL; i++)
            mvprintw(i + ((snake->y_max + 16) / 2) - 6, (65 + ((snake->x_max - 65) / 2) - 50), menu_choise[i]);
        attroff(COLOR_PAIR(CYAN));
        for (int i = 0; menu_choise[i] != NULL; i++) {
            for (int j = 0; menu_choise[i][j] != '\0'; j++) {
                if (menu_choise[i][j] - '0' == snake->speed) {
                    speed_str[0] = menu_choise[i][j];
                    mvprintw(i + ((snake->y_max + 16) / 2) - 6, (65 + ((snake->x_max - 65) / 2) - 50) + j, speed_str);
                }
                if (menu_choise[i][j] == 'b' && snake->border_mode == true) {
                    mvprintw(i + ((snake->y_max + 16) / 2) - 6, (65 + ((snake->x_max - 65) / 2) - 50) + j, border_on);
                    i += 2;
                }
                if (menu_choise[i][j] == 'b' && snake->border_mode == false) {
                    i++;
                    mvprintw(i + ((snake->y_max + 16) / 2) - 6, (65 + ((snake->x_max - 65) / 2) - 50) + j, border_off);
                }
            }
        }
        if ((test_ch = getch()) != ERR) {
            ch = test_ch;
            if (ch == UP || ch == DOWN) {
                if (snake->border_mode == true)
                    snake->border_mode = false;
                else if (snake->border_mode == false)
                    snake->border_mode = true;
            }
            if (ch == LEFT && snake->speed > 1)
                snake->speed--;
            if (ch == RIGHT && snake->speed < 10)
                snake->speed++;
        }
        if (ch == ENTER ||ch == SPACE)
            break;
        if (ch == 'q') {
            endwin();
            exit(0);
        }
        refresh();
        usleep(100000);
        clear();
    }
    endwin();
    snake_game_loop(snake);
}
