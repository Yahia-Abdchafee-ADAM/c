//YAHIA ABDCHAFEE Adam
#include <unistd.h>
#include <stdio.h>
#include <sys/stat.h>
#include <errno.h>
#include <string.h>
#include <stdlib.h>

char *read_file(char const *filename)
{
	struct stat st;
    FILE *file_descriptor = fopen(filename, "r");
    char *file_content;

    if (!file_descriptor) {
    	printf("fopen failed, errno = %d\n", errno);
        exit (1);
    }
    stat(filename, &st);
	file_content = malloc(sizeof(char) * (st.st_size + 1));
	fread(file_content, st.st_size + 1, sizeof(char) * (st.st_size + 1), file_descriptor);
	file_content[st.st_size] = '\0';
	fclose(file_descriptor);
	return (file_content);
}
