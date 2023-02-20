#include <sys/stat.h>
#include <stdlib.h>
#include <stdio.h>

char *read_file(char *file_name)
{
    struct stat st;
    char *file_content;
    FILE *file = fopen(file_name, "r");

    stat(file_name, &st);
    if (st.st_size != 0) {
            file_content = malloc(sizeof(char) * st.st_size);
            for (struct {char c; int i;} loopy = {0, 0}; (loopy.c = fgetc(file)) != EOF; loopy.i++)
                file_content[loopy.i] = loopy.c;
            fclose(file);
    } else
        return (NULL);
    return (file_content);
}
