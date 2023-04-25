#include "shell.h"
/**
 * execute - creates a child process and executes.
 * @command: command to be executed.
 * @command_cpy: @command duplicated.
 * @av: each word of command.
 * @path: PATH.
 * Return: if couldn't create child proccess -1, 0 if success.
 */
int execute(char *command, char *command_cpy, char **av, char *path)
{
	int status = 0;
	pid_t pid = fork();

	if (pid == -1)
	{
		perror("Error");
		return (-1);
	}
	if (!pid)
	{
		execve(av[0], av, environ);
		perror("Shell");
		free(command), free(command_cpy), free(av), free(path);
		exit(EXIT_FAILURE);
	}
	wait(&status);
	return (0);
}

/**
 * eway - checks for '/' in @av[0], and exits if @av[0] is "exit".
 * @cmd: command to be executed.
 * @cmdcpy: @command duplicated.
 * @av: each word of command.
 * @path: PATH.
 * Return: calls the concerned function.
 */
int eway(char *cmd, char *cmdcpy, char **av, char *path)
{
	struct stat st;
	int i;

	if (!strcmp(av[0], "exit"))
	{
		free(cmd), free(cmdcpy), free(av), free(path);
		exit(EXIT_SUCCESS);
	}
	for (i = 0; cmd[i]; i++)
	{
		if (cmd[i] == 47)
		{
			if (!stat(av[0], &st))
			{
				return (execute(cmd, cmdcpy, av, path));
			}
			printf("Shell: %s: No such file or directory\n", av[0]);
			return (0);
		}
	}
	return (exec_no_path(av, path, cmdcpy, cmd));
}

/**
 * exec_no_path - adds the route of the command.
 * @cmd: command to be executed.
 * @cmdcpy: @command duplicated.
 * @av: each word of command.
 * @path: PATH.
 * Return: calls to execute if the command exists, 0 if not.
 */
int exec_no_path(char **av, char *path, char *cmdcpy, char *cmd)
{
	struct stat st;
	char *where = findcmd(av[0], path), *cmdc = av[0];

	av[0] = where;

	if (!stat(where, &st))
	{
		return (execute(cmd, cmdcpy, av, path));
	}
	printf("Shell: %s: command not found\n", cmdc);
	return (0);
}
