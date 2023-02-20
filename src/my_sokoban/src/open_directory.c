#include <dirent.h>
#include <stddef.h>
#include <stdlib.h>
#include "my.h"

char **fill_arr(struct dirent *pDdirent, DIR *directory , int nbr_of_file)
{
    char **files_name;
    int count = 0;
    files_name = malloc(sizeof(char*) * (nbr_of_file - 1));
    while ((pDdirent = readdir(directory)) != NULL) {
        if (pDdirent->d_name[0] != '.') {
            files_name[count] = my_strdup(pDdirent->d_name);
            count++;
        }
    }
    files_name[count] = NULL;
    closedir(directory);
    return (files_name);
}

char **open_directory(char *directory_name)
{
    DIR *directory;
    int nbr_of_file = 0;
    struct dirent *pDdirent;

    directory = opendir(directory_name);
    for (; ((pDdirent = readdir(directory)) != NULL); nbr_of_file++);
    if (nbr_of_file == 2)
        return NULL;
    else
        directory = opendir(directory_name);
    return (fill_arr(pDdirent, directory, nbr_of_file));
}
