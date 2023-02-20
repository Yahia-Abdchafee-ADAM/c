#include <stdlib.h>
#include <ncurses.h>
#include "my.h"
#include "my_sokoban.h"

void find_line_col(char **map_arr, int *cols, int *line)
{
    int i = 0;
    int j = 0;

    j = my_strlen(map_arr[0]);
    for (i = 0; map_arr[i] != NULL; i++) {
        if (my_strlen(map_arr[i]) > j)
            j = my_strlen(map_arr[i]);
    }
    *cols = j;
    *line = i;
}

void my_sokoban_s(int line, int cols, pos_t *p)
{
    WINDOW *win = newwin(line + 4, cols + 4, (LINES / 2)
    - (line / 2) - 2, (COLS / 2) - (cols / 2) - 2);

    initscr();
    noecho();
    curs_set(0);
    refresh();
    box(win, 0, 0);
    mvwprintw(win, 0, 1, "LEVEL : %i ", (p->level));
    wrefresh(win);
    attron(COLOR_PAIR(3));
    if (LINES / 2 > cols / 2 + 12)
        for (int i = 0; p->maps[0].level[i] != NULL; i++)
            mvprintw(i + 5, ((COLS / 2) - 50), p->maps[0].level[i]);
    attroff(COLOR_PAIR(3));
}

void play_map(char **map_arr, int line, int cols, int i)
{
    for (int j = 0; map_arr[i][j] != '\0'; j++) {
        if (map_arr[i][j] == 'P') {
            attron(COLOR_PAIR(1));
            mvprintw(LINES / 2 - (line / 2) + i, ((COLS / 2) -
            (cols / 2) + j),"%c", map_arr[i][j]);
            attroff(COLOR_PAIR(1));
        }
        if (map_arr[i][j] == 'X') {
            attron(COLOR_PAIR(4));
            mvprintw(LINES / 2 - (line / 2) + i,
            ((COLS / 2) - (cols / 2) + j),"%c", map_arr[i][j]);
            attroff(COLOR_PAIR(4));
        } else if (map_arr[i][j] == 'O') {
            attron(COLOR_PAIR(5));
            mvprintw(LINES / 2 - (line / 2) + i, ((COLS / 2) -
            (cols / 2) + j),"%c", map_arr[i][j]);
            attroff(COLOR_PAIR(5));
        } else if (map_arr[i][j] != 'P')
            mvprintw(LINES / 2 - (line / 2) + i, ((COLS / 2) -
            (cols / 2) + j),"%c", map_arr[i][j]);
    }
}

int my_pop(char **map_arr, pos_t *p)
{
    int key = 0;
    int line = 0;
    int cols = 0;

    find_line_col(map_arr, &cols, &line);
    initscr();
    noecho();
    curs_set(0);
    init_color_s();
    if (LINES < line || COLS < (cols))
        mvprintw(LINES / 2, ((COLS / 2) - 12), "Too small...");
    else {
        my_sokoban_s(line, cols, p);
        for (int i = 0; map_arr[i] != NULL; i++)
            play_map(map_arr, line, cols, i);
    }
    key = getch();
    clear();
    return (key);
}
