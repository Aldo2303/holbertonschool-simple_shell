#include "shell.h"

int execute(char *command, char *command_cpy, char **av, char *path)
{
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
	wait(NULL);
	return (0);
}

int eway(char *cmd, char *cmdcpy, char **av, char *path)
{
	int i;

	for (i = 0; cmd[i]; i++)
	{
		if (cmd[i] == 47)
			return (execute(cmd, cmdcpy, av, path));
	}

	return (exec_no_path(av, path, cmdcpy, cmd));
}

int exec_no_path(char **av, char *path, char *cmdcpy, char *cmd)
{
	char *where = findcmd(av[0], path);

	av[0] = where;

	execute(cmd, cmdcpy, av, path);

	return (0);
}
