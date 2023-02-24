#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>
#include <errno.h>
#include <string.h>

int main(int ac, char **av)
{
    char input[20];

    while (1) {
        printf("1: my_sokoban\n");
        printf("2: my_snake\n");
        printf("3: my_tetris\n");
        printf("4: my_battleship\n");
        printf("stop: to quit\n>>");
        scanf("%s", input);
        if (strcmp(input, "stop") == 0) {
            return (0);
        }
        if (strcmp(input, "1") == 0) {
            chdir("./src/my_sokoban/");
            system("./my_sokoban");
            chdir("..");
            chdir("..");
        }
        if (strcmp(input, "2") == 0) {
            chdir("./src/my_snake/");
            system("./my_snake");
            chdir("..");
            chdir("..");
        }
        if (strcmp(input, "3") == 0) {
            chdir("./src/my_tetris/");
            system("./my_tetris");
            chdir("..");
            chdir("..");
        }
        if (strcmp(input, "4") == 0) {
            chdir("./src/my_battleship/");
            system("gnome-terminal --tab -- bash -c 'sleep 1s; ./my_battleship maps/position2.txt; exec bash -i'");
            system("./my_battleship maps/position1.txt 1111");
            chdir("..");
            chdir("..");
        }
    }
    return (0);
}
