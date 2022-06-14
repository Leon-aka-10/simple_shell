#include "shell.h"

/**
 * read_line - read input form stdin
 * Return: pointer to buffer read
 */

char *read_line()
{
	char *buffer;
	size_t len = 1024;
	int read;

	buffer = malloc(sizeof(size_t) * len);

	read = getline(&buffer, &len, stdin);
	if (read == EOF)
	{
		printf("\n");
		free(buffer);
		exit(EXIT_SUCCESS);
	}
	buffer[_strlen(buffer) - 1] = '\0';
	return (buffer);
}
