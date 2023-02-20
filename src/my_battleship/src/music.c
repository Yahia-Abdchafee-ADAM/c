#include "navy.h"
#include <stdbool.h>
#include <stdio.h>

void music(navy_t *navy)
{
    char if_music[25];

    printf("\e[1;1H\e[2J\n");
    printf("Music [N/Y] ? ");
    scanf("%s", if_music);
    if (my_strcmp(if_music, "Y") == 1 || my_strcmp(if_music, "y") == 1) {
        navy->music = sfMusic_createFromFile("music/navy_music.ogg");
        sfMusic_setLoop(navy->music, true);
        sfMusic_play(navy->music);
        printf("\e[1;1H\e[2J\n");
        return;
    } else if (my_strcmp(if_music, "N") == 1 || my_strcmp(if_music, "n") == 1)
        return;
    else {
        music(navy);
    }
}
