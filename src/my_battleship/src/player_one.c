#include "navy.h"
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <sys/stat.h>
#include <stdbool.h>
#include <string.h>

void display_player_one(navy_t *navy)
{
    printf("\nmy positions:\n");
    print_myboard(navy->player_one_map);
    printf("enemy’s positions:\n");
    print_ennemy_board(navy->player_two_map);
}

int player_one_connection(navy_t *navy)
{
    FILE *connect;
    struct stat st;
    char *connection;
    int time_out = 0;

    stat("lgs/connection.txt", &st);
    navy->player_one_pid = 1111;
    printf("My_pid:     %d\nWaiting for enemy connection...\n", navy->player_one_pid);
    while (navy->player_one_pid != navy->player_two_pid) {
        if (time_out >= 60) {
            printf("\033[0;31mErr_Connection_Timed_Out\033[0m\n");
            exit(EXIT_FAILURE);
        }
        sleep(5);
        time_out += 5;
        if (st.st_size != 0) {
            if ((connection = read_file("logs/connection.txt")) != NULL) {
                navy->player_two_pid = atoi(connection);
                free(connection);
            }
        }
    }
    navy->player_two_map = my_strtok(read_file("logs/player_two_map.txt"), "\n");
    remove("logs/player_two_map.txt");
    printf("\033[0;32m\nEnemy connected\033[0m\n");
    connect = fopen("logs/connection.txt", "w+");
    fputs(my_int_to_str(navy->player_one_pid + 1), connect);
    fclose(connect);
    return (EXIT_SUCCESS);
}

void wait_for_attack_player_one(navy_t *navy)
{
    char *go_attack;
    char *attack;
    bool is_wait = true;

    go_attack = read_file("logs/player_one_attack.txt");
    is_wait = true;
    while (go_attack[0] == 'f' && go_attack[1] == 'a') {
        if (is_wait == true) {
            printf("\nwaiting for enemy’s attack...\n");
            is_wait = false;
        }
        sleep(2);
        go_attack = read_file("logs/player_one_attack.txt");
    }
    attack = read_file("logs/attack.txt");
    if (navy->player_one_map[attack[1] - '0'][attack[0] - 'A'] == '0') {
        printf("%c%c:     \033[0;32mhit\033[0m\n", attack[0], attack[1]);
        navy->player_one_map[attack[1] - '0'][attack[0] - 'A'] = '*';
    } else {
        navy->player_one_map[attack[1] - '0'][attack[0] - 'A'] = ' ';
        printf("%c%c:     \033[0;31mmissed\033[0m\n", attack[0], attack[1]);
    }
}

bool is_valid_attack_player_one(char attack[250], navy_t *navy)
{
    for (int i = 0; navy->dico_of_attack[i] != NULL; i++) {
        if (strcmp(navy->dico_of_attack[i], attack) == 0) {
            write_in_file("logs/player_one_attack.txt", "false");
            write_in_file("logs/player_two_attack.txt", "true");
            if (navy->player_two_map[attack[1] - '0'][attack[0] - 'A'] == '0') {
                printf("%s: \033[0;32mhit\033[0m\n", attack);
                navy->player_two_map[attack[1] - '0'][attack[0] - 'A'] = '*';
            } else {
                printf("%s: \033[0;31mmissed\033[0m\n", attack);
                navy->player_two_map[attack[1] - '0'][attack[0] - 'A'] = ' ';
            }
            write_in_file("logs/attack.txt", attack);
            return (true);
        }
    }
    return (false);
}

int game_loop_player_one(navy_t *navy)
{
    char attack[250];
    bool is_valid_attack = false;

    while (1) {
        wait_for_attack_player_one(navy);
        display_player_one(navy);
        is_valid_attack = false;
        while (is_valid_attack == false) {
            printf("attack: ")  ;
            scanf("%s", attack);
            is_valid_attack = is_valid_attack_player_one(attack, navy);
            if (is_valid_attack == false)
                printf("wrong position\n");
        }
        if (get_ship_number(navy->player_two_map) == 0) {
            printf("\033[0;32mYou win\033[0m");
            return (0);
        }
        if (get_ship_number(navy->player_one_map) == 0) {
            printf("\033[0;31mYou lost\033[0m\n");
            return (0);
        }
        display_player_one(navy);
    }
    return (0);
}

int player_one(navy_t *navy, char **av)
{
    navy->player_one_map = generate_random_map();
    if (write_array_in_file("logs/player_one_map.txt", navy->player_one_map, SIZE) == EXIT_FAILURE)
        return (EXIT_FAILURE);
    player_one_connection(navy);
    display_player_one(navy);
    game_loop_player_one(navy);
}
