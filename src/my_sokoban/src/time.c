#include <stdlib.h>
#include <ncurses.h>
#include "my.h"
#include "my_sokoban.h"
#include <stdlib.h>
#include <unistd.h>

void make_my_str_time(my_clock_t *clock)
{
    clock->time = sfClock_getElapsedTime (clock->clock);
    clock->seconds = clock->time.microseconds / 1000000;
    if (clock->seconds >= 60) {
        clock->minutes++;
        sfClock_restart(clock->clock);
    }
    if (clock->minutes >= 60) {
        clock->minutes = 0;
        clock->heures++;
    }
    clock->str_time[0] = (clock->heures / 10) + '0';
    clock->str_time[1] = (clock->heures % 10) + '0';
    clock->str_time[3] = (clock->minutes / 10) + '0';
    clock->str_time[4] = (clock->minutes % 10) + '0';
    clock->str_time[6] = (clock->seconds / 10) + '0';
    clock->str_time[7] = (clock->seconds % 10) + '0';
}

void inite_my_clock(my_clock_t *clock)
{
    clock->seconds = 0;
    clock->minutes = 0;
    clock->heures = 0;
    clock->str_time = malloc(sizeof(char) * 9);
    for (int i = 0; i != 8; i++)
        clock->str_time[i] = ':';
    clock->str_time[8] = '\0';
    clock->clock = sfClock_create();
}

//void *thread_1(void *argv)
void my_time(void)
{
    my_clock_t clock;
    WINDOW *win_time;

    initscr();
    noecho();
    curs_set(0);
    win_time = newwin(3, 10, LINES / 2, COLS / 2);
    inite_my_clock(&clock);
    while (1) {
        box(win_time, 0, 0);
        make_my_str_time(&clock);
        attron(COLOR_PAIR(1));
        mvwprintw(win_time, 1, 1, "%s", clock.str_time);
        attroff(COLOR_PAIR(1));
        wrefresh(win_time);
        usleep(1000000);
        refresh();
    }
}
