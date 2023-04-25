#include "shell.h"

/**
 * get_env - search the environment variable env_name
 * @env _name: the enviroment variable to look for
 * Return: the string associated to env_name variable
 */

char *get_env(char *env_name)
{
	char *env_var = NULL, *var_name = NULL, *env_value = NULL;
	int i;

	if (!environ|| !env_name)
		return (NULL);

	for (i = 0; environ[i]; i++)
	{
		env_var = strdup(environ[i]);
		var_name = strtok(env_var, "=");
		if (var_name == NULL)
		{
			free(var_name), free(env_var);
			continue;
		}

		if (!(strcmp(var_name, env_name)))
		{
			var_name = strtok(NULL, "=");
			if (var_name)
			{
				env_value = strdup(var_name);
				free(env_var);
				return (env_value);
			}
		}
		free(env_var);
	}
	return (NULL);
}
