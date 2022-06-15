#include "shell.h"
/**
 * token_buffer - splits the buffer into tokens
 * @buffer: pointer to the buffer
 * @delimit: delimitator chosen
 * Return: double pointer to the tokens
 **/
char **token_buffer(char *buffer, char *delimit)
{
	int buffsize = 64, iter = 0;
	char **tokens = malloc(sizeof(char *) * (buffsize));
	char *stoken;

	if (!tokens)
	{
		perror("Not possible to allocate memory");
		free(buffer);
		exit(98);
	}
	stoken = _strtok(buffer, delimit);
	while (stoken)
	{
		tokens[iter] = stoken;
		iter++;
		stoken = _strtok(NULL, delimit);
	}
	tokens[iter] = NULL;
	return (tokens);
}
