#include "shell.h"

/**
 * main - integrates the functions to make the shell work
 * Return: 0 on success
 */

int main(void)

{
	char *buffer, **commands;
	list_t *linkedlist_path, *env_list;
	int characters;
	size_t bufsize = BUFSIZE;

	buffer = (char *)malloc(bufsize * sizeof(char));
	if (buffer == NULL)
	{
		perror("Unable to allocate buffer");
		exit(1);
	}

	linkedlist_path = path_list();
	env_list = environ_list();
	while (1)
	{
		if (isatty(STDIN_FILENO))
			write(STDOUT_FILENO, "$ ", 3);
		else
			non_int(env_list);

		signal(SIGINT, ctrl_c);
		characters = getline(&buffer, &bufsize, stdin);
		ctrl_D(characters, buffer, env_list);

		commands = split_line(buffer);
		if (_builtin(commands[0]))
			_builtin(commands[0])(commands, linkedlist_path, buffer);
		else
			shell_exec(commands, linkedlist_path);
		free(commands);
	}

	return (0);
}
