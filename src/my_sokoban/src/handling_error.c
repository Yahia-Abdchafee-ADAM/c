#include "my_sokoban.h"

int verif_suspect_char(char *map)
{
    int error = 0;

    for (int i = 0; map[i] != '\0'; i++) {
        error = 0;
        if (map[i] != ' ')
            error++;
        if (map[i] != 'O')
            error++;
        if (map[i] != 'X')
            error++;
        if (map[i] != '#')
            error++;
        if (map[i] != 'P')
            error++;
        if (map[i] != '\n')
            error++;
        if (error == 6)
            return (ERROR);
    }
    return (SUCCESS);
}

int verif_count_o_x_p(char *map)
{
    int nbr_o = 0;
    int nbr_x = 0;
    int nbr_p = 0;

    for (int i = 0; map[i] != '\0'; i++) {
        if (map[i] == 'O')
            nbr_o++;
        if (map[i] == 'X')
            nbr_x++;
        if (map[i] == 'P')
            nbr_p++;
    }
    if ((nbr_o != nbr_x) || (nbr_p != 1))
        return (ERROR);
    return (SUCCESS);
}

int handling_error(char *map)
{
    if (verif_suspect_char(map) == ERROR)
        return (ERROR);
    if (verif_count_o_x_p(map) == ERROR)
        return (ERROR);
    return (SUCCESS);
}