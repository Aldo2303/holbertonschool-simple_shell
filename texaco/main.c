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
	int interactive = isatty(STDIN_FILENO);
	(void)ac;

	while (1)
	{

		if (interactive == 1)
			printf("$ ");

		if (getline(&command, &size, stdin) == -1)
		{
			free(command);
			exit(EXIT_FAILURE);
		}
		if (!command)
		{
			free(path);
			return (0);
		}

		if (command[0] == '\n')
			continue;

		path = get_env("PATH");
		command_cpy = strdup(command);
		av = tokenizer(command_cpy, delim);
		eway(command, command_cpy, av, path);

		free(command), free(command_cpy), free(argv), free(path);
	}
	return (0);
}
