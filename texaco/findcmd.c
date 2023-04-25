#include "shell.h"

char *findcmd(char *cmd, char *path)
{
	struct stat st;

	int i, k = strlen(cmd);
	char **tpath = tokenizer(path, ":");
	char *in;
	char u_cmd[k + 2];
	char where[60];

	u_cmd[0] = 47;
	for (i = 1; i <= k; i++)
		u_cmd[i] = cmd[i - 1];
	u_cmd[k + 1] = '\0';

	for (i = 0; tpath[i]; i++)
	{
		strcpy(where, tpath[i]);
		strcat(where, u_cmd);
		if (!stat(where, &st))
		{
			in = strcat(tpath[i], u_cmd);
			free(tpath);
			return (in);
		}
	}

	in = strcat(tpath[0], u_cmd);
	free(tpath);
	return (in);
}
