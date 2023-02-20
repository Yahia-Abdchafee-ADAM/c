#include <stdio.h>
#include "navy.h"
#include <unistd.h>
#include <sys/stat.h>
#include <stdlib.h>
#include <string.h>

int initialisation_navy(navy_t *navy)
{
    create_file("logs/attack.txt");
    create_file("logs/connection.txt");
    create_file("logs/player_two_map.txt");
    create_file("logs/player_two_attack.txt");
    create_file("logs/player_one_attack.txt");
    write_in_file("logs/player_two_attack.txt", "true");
    write_in_file("logs/player_one_attack.txt", "false");
    navy->dico_of_attack = my_strtok(read_file("configs/dico_attack.txt"), " ");
    navy->map = read_file("configs/map.txt");
    if (!(navy->player_one_map = strdup(navy->map)))
        return (EXIT_FAILURE);
    if (!(navy->player_two_map = strdup(navy->map)))
        return (EXIT_FAILURE);
    music(navy);
    return (EXIT_SUCCESS);
}

int my_navy(int ac, char **av)
{
    FILE *help = fopen("configs/help.txt", "r");
    navy_t n;

    if ((ac == 1 || ac > 3) || (strcmp(av[1], "-h") == 0 || strcmp(av[1], "--help") == 0)) {
        if (help)
            for (char c = 0; (c = fgetc(help)) != EOF; printf("%c", c));
        return (EXIT_SUCCESS);
    }
    if (initialisation_navy(&n) == EXIT_FAILURE)
        return (EXIT_FAILURE);
    if (ac == 2)
        if (player_one(&n, av) == EXIT_FAILURE)
            return (EXIT_FAILURE);
    if (ac == 3)
        if (player_two(&n, av) == EXIT_FAILURE)
            return (EXIT_FAILURE);
    sfMusic_destroy(n.music);
    fclose(help);
    return (EXIT_SUCCESS);
}

// int main(int ac, char **av)
// {
//     my_navy(ac, av);
// }
