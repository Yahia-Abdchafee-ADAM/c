#include <stdio.h>
#include <stdlib.h>

int write_in_file(char *file_name, char *string)
{
    FILE *file = fopen(file_name, "w+");

    if (file != NULL) {
        fputs(string, file);
    } else
        return (EXIT_FAILURE);
    fclose(file);
    return (EXIT_SUCCESS);
}


int write_array_in_file(char *file_name, char **arr, int size)
{
    FILE *file = fopen(file_name, "w+");

    if (file != NULL) {
        for (int i = 0; i != size; i++) {
            fputs(arr[i], file);
            fputs("\n", file);
        }
    } else
        return (EXIT_FAILURE);
    fclose(file);
    return (EXIT_SUCCESS);
}