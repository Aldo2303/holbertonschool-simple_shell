#include "shell.h"

/**
 * findcmd - finds the route of the given command.
 * @cmd: command to be found.
 * @path: PATH.
 * Return: if command is found the route of it, any route if not.
 */
char *findcmd(char *cmd, char *path)
{
	struct stat st;
	int i, k = strlen(cmd);
	char **tpath;
	char *in, *u_cmd, *where;

	if (path)
	{
		tpath = tokenizer(path, ":");
		u_cmd = malloc(sizeof(char) * (k + 2));
		u_cmd[0] = 47;
		for (i = 1; i <= k; i++)
			u_cmd[i] = cmd[i - 1];
		u_cmd[k + 1] = '\0';

		for (i = 0; tpath[i]; i++)
		{
			where = malloc(sizeof(char) * (k + 2 + strlen(tpath[i])));
			strcpy(where, tpath[i]);
			strcat(where, u_cmd);
			if (!stat(where, &st))
			{
				in = strcat(tpath[i], u_cmd);
				free(tpath), free(u_cmd), free(where);
				return (in);
			}
			free(where);
		}
		free(tpath), free(u_cmd);
	}
		return (NULL);
}
