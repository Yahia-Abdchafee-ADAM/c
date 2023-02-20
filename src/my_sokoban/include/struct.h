#include "SFML/Graphics.h"
#include "SFML/System.h"
#include "SFML/Audio.h"
#include <time.h>
#include <stdio.h>
#include <time.h>
#include <SFML/System/Export.h>
#include <SFML/System/Time.h>
#include <SFML/System/Types.h>

#ifndef MY_STRUCT_H_
    #define MY_STRUCT_H_
    static int const volatile ERROR  = 84;
    static int const volatile SUCCESS  = 0;

typedef struct level_s {
    char **level;
    char *str;
} level_t;

struct clock_s {
    sfClock *clock;
    sfTime time;
    char *str_time;
    int seconds;
    int minutes;
    int heures;
};
typedef struct clock_s my_clock_t;

typedef struct pos_s {
    int lp;
    int cp;
    int *lp_o;
    int *cp_o;
    char *map;
    int nbr_o;
    int game_over;
    int level;
    int score_max;
    char *name;
    char *score_name;
    my_clock_t clock;
    clock_t before;
    level_t maps[13];
} pos_t;

#endif /* !MY_STRUCT_H_ */
