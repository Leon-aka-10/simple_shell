#include "shell.h"

/**
 * main - integrates the functions to make the shell work
 * @ac: number of arguments
 * @av: argument list
 * Return: 0 on success
 */
int main(int ac __attribute__((unused)), char **av)
{
	char *buffer;
	list_t *linkedlist_path;
	int characters;
	char **commands;
	size_t bufsize = BUFSIZE;

	if (ac >= 2)
	{
		if (execve(av[1], av, NULL) == -1)
		{
			perror(av[0]);
			exit(-1);
		}
		return (0);
	}
	buffer = (char *)malloc(bufsize * sizeof(char));
	if (buffer == NULL)
	{
		perror("Unable to allocate buffer");
		exit(1);
	}
	linkedlist_path = path_list();
	do {
		write(STDOUT_FILENO, "~$ ", 3);
		characters = getline(&buffer, &bufsize, stdin);
		commands = split_line(buffer);
		if (!commands)
			break;
		if (_builtin(commands[0]))
			_builtin(commands[0])(commands, linkedlist_path, buffer);
		else
			shell_exec(commands, linkedlist_path, av);
		free(commands);
		if (characters == EOF)
		{
			free(buffer);
			continue;
		}
	} while (1);
	return (0);
}
