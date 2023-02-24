#include "navy.h"
#include <stdio.h>
#include <sys/stat.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

void display_player_two(navy_t *navy)
{
    printf("\nMy positions:\n");
    print_myboard(navy->player_two_map);
    printf("\nEnemy’s positions:\n");
    print_ennemy_board(navy->player_one_map);
}

int player_two_connection(navy_t *navy, char *player_one_pid)
{
    FILE *connect = fopen("logs/connection.txt", "w+");
    char *connection;
    struct stat st;
    int time_out = 0;

    fputs(player_one_pid, connect);
    fclose(connect);
    navy->player_two_pid = atoi(player_one_pid) + 1;
    printf("My_pid:     %i\n", navy->player_two_pid);
    while (navy->player_one_pid != navy->player_two_pid) {
        stat("logs/connection.txt", &st);
        if (time_out >= 60) {
            printf("\033[0;31mErr_Connection_Timed_Out\033[0m\n");
            exit(EXIT_FAILURE);
        }
        if (st.st_size != 0) {
            connect = fopen("logs/connection.txt", "r");
            connection = malloc(sizeof(char) * st.st_size);
            for (struct {char c; int i;} loopy = {0, 0}; (loopy.c = fgetc(connect)) != EOF; loopy.i++)
                connection[loopy.i] = loopy.c;
            navy->player_one_pid = atoi(connection);
            free(connection);
            fclose(connect);
        }
        sleep(2);
        time_out += 5;
    }
    navy->player_one_map = my_strtok(read_file("logs/player_one_map.txt"), "\n");
    remove("logs/player_one_map.txt");
    printf("\033[0;32mSuccessfully connected\033[0m\n");
}

void wait_for_attack_player_two(navy_t *navy)
{
    char *go_attack;
    bool is_wait = true;
    char *attack;

    go_attack = read_file("logs/player_two_attack.txt");
    is_wait = true;
    while(go_attack[0] == 'f' && go_attack[1] == 'a') {
        if (is_wait == true) {
            printf("\nwaiting for enemy’s attack...\n");
            is_wait = false;
        }
        sleep(3);
        go_attack = read_file("logs/player_two_attack.txt");
    }
    attack = read_file("logs/attack.txt");
    if (navy->player_two_map[attack[1] - '0'][attack[0] - 'A'] == '~') {
        printf("%c%c:     \033[0;31mmissed\033[0m\n", attack[0], attack[1]);
        navy->player_two_map[attack[1] - '0'][attack[0] - 'A'] = ' ';
    } else {
        printf("%c%c:     \033[0;32mhit\033[0m\n", attack[0], attack[1]);
        navy->player_two_map[attack[1] - '0'][attack[0] - 'A'] = '*';
    }
}

bool is_valid_attack_player_two(char attack[250], navy_t *navy)
{
    for (int i = 0; navy->dico_of_attack[i] != NULL; i++) {
        if (strcmp(navy->dico_of_attack[i], attack) == 0) {
            write_in_file("logs/player_two_attack.txt", "false");
            write_in_file("logs/player_one_attack.txt", "true");
            if (navy->player_one_map[attack[1] - '0'][attack[0] - 'A'] == '0') {
                printf("%s: \033[0;32mhit\033[0m\n", attack);
                navy->player_one_map[attack[1] - '0'][attack[0] - 'A'] = '*';
            } else {
                printf("%s: \033[0;31mmissed\033[0m\n", attack);
                navy->player_one_map[attack[1] - '0'][attack[0] - 'A'] = ' ';
            }
            write_in_file("logs/attack.txt", attack);
            return (true);
        }
    }
    return (false);
}

int game_loop_player_two(navy_t *navy)
{
    char attack[250];
    bool is_valid_attack = false;

    while (1) {
        display_player_two(navy);
        is_valid_attack = false;
        while (is_valid_attack == false) {
            printf("attack: ");
            scanf("%s", attack);
            is_valid_attack = is_valid_attack_player_two(attack, navy);
            if (is_valid_attack == false)
                printf("wrong position\n");
        }
        display_player_two(navy);
        if (get_ship_number(navy->player_one_map) == 0) {
            printf("\033[0;32mYou win\033[0m");
            return (0);
        }
        if (get_ship_number(navy->player_two_map) == 0) {
            printf("\033[0;31mYou lost\033[0m\n");
            return (0);
        }
        wait_for_attack_player_two(navy);
    }
}

int player_two(navy_t *navy, char **av)
{
    navy->player_two_map = generate_random_map();
    if (write_array_in_file("logs/player_two_map.txt", navy->player_two_map, SIZE) == EXIT_FAILURE)
        return (EXIT_FAILURE);
    player_two_connection(navy, av[2]);
    game_loop_player_two(navy);
}
