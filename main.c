#include "shell.h"

/**
 * main - calls the concerned functions.
 * @ac: Number of arguments passed.
 * @av: arguments given.
 * Return: 0.
 */
int main(int ac, char **av)
{
	char *command_cpy = NULL, *path, *command = NULL, *delim = " \n\t";
	size_t size = 0;
	int interactive = isatty(STDIN_FILENO), status = 1;
	(void)ac;

	while (1)
	{
		path = get_env("PATH");
		if (interactive == 1)
			printf("$ ");

		if (getline(&command, &size, stdin) == -1)
		{
			free(command);
			if (path && strlen(path))
				free(path);
			exit(status);
		}
		if (!command)
		{
			free(path);
			return (status);
		}
		command_cpy = strdup(command);
		av = tokenizer(command_cpy, delim);
		status = eway(command, command_cpy, av, path);
		free(command_cpy), free(av);
	}
	return (status);
}
