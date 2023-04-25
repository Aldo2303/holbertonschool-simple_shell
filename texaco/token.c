#include "shell.h"

char **tokenizer(char *command, char *delim)
{
	int i, argc;
	char **argv = NULL;
	char *command_cpy = strdup(command), *token = strtok(command_cpy, delim);

	for (argc = 1; token; argc++)
		token = strtok(NULL, delim);

	argv = malloc(sizeof(char *) * argc);
	if (argv == NULL)
		return (NULL);

	free(command_cpy);
	token = strtok(command, delim);

	for (i = 0; token; i++)
	{
		argv[i] = token;
		token = strtok(NULL, delim);
	}
	argv[i] = NULL;

	return (argv);
}
