#include <ncurses.h>
#include <unistd.h>
#include "my.h"
#include "my_sokoban.h"

void init_color_sokoban(void)
{
    start_color();
    init_pair(1, COLOR_GREEN, COLOR_BLACK);
    init_pair(2, COLOR_BLUE, COLOR_BLACK);
    init_pair(3, COLOR_RED, COLOR_BLACK);
    init_pair(4, COLOR_YELLOW, COLOR_BLACK);
    init_pair(5, COLOR_MAGENTA, COLOR_BLACK);
    init_pair(6, COLOR_CYAN, COLOR_BLACK);
    init_pair(7, COLOR_WHITE, COLOR_BLACK);
    init_pair(8, COLOR_CYAN, COLOR_BLACK);
    init_pair(9, COLOR_YELLOW, COLOR_BLACK);
}

int charge_map(pos_t *p)
{
    p->maps[1].str = read_file("maps/level1.txt");
    p->maps[2].str = read_file("maps/level2.txt");
    p->maps[3].str = read_file("maps/level3.txt");
    p->maps[4].str = read_file("maps/level4.txt");
    p->maps[5].str = read_file("maps/level5.txt");
    p->maps[6].str = read_file("maps/level6.txt");
    p->maps[7].str = read_file("maps/level7.txt");
    p->maps[8].str = read_file("maps/level8.txt");
    p->maps[9].str = read_file("maps/level9.txt");
    p->maps[10].str = read_file("maps/level10.txt");
    p->maps[11].str = read_file("maps/level11.txt");
    p->maps[12].str = read_file("maps/level12.txt");
}

void inite_my_value(pos_t *p)
{
    int i = 0;

    p->level = 1;
    p->score_max = my_getnbr(p->map);
    p->maps[0].level = my_str_to_word_arr(p->map, "\n");
    charge_map(p);
}

