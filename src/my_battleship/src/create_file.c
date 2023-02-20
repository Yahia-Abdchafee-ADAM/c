#include <stdio.h>
#include <stdlib.h>

int create_file(char *file_name)
{
    FILE *file = fopen(file_name, "w");

    if (file == NULL)
        return (EXIT_FAILURE);    
    fclose(file);
    return (EXIT_SUCCESS);
}
