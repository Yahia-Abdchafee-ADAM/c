#include <unistd.h>

void help(void)
{
    char *str = "USAGE\n\t./my_sokoban map\nDESCRIPTION\n\t\
map file representing the warehouse map, containing '#' for walls,\n\t\t\
'P' for the player, 'X' for boxes and 'O' for storage locations.";
    write(0, str, 170);
}
