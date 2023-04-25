#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>
#include <signal.h>
#include <string.h>

#define MAX_COMMAND_LENGTH 256
#define MAX_ARGS 10
/**
 * run_command - function that executes a command
 * @args: arguments array
 *
 * Return: child process ID
 */
void run_command(char **args)
{
	pid_t pid = fork();
	int status;

	if (pid == 0)
	{
		execve(args[0], args, NULL);
		printf("shell: %s: command not found\n", args[0]);
		exit(1);
	}
	else if (pid > 0)
	{
		wait(&status);
	}
	else
	{
		printf("shell: error creating child process\n");
	}
}

/**
 * main - Shell entry point
 *
 * Return: Always 0.
 */
int main(void)
{
	char *command = NULL, *args[MAX_ARGS];
	size_t command_size = 0;

	while (1)
	{
		/* Check if standard input is connected to a terminal */
		if (isatty(STDIN_FILENO))
		{
			printf("$ ");
			fflush(stdout);
		}

		ssize_t read = getline(&command, &command_size, stdin);

		if (read == -1)/* Exit program if Ctrl+D is pressed */
			break;

		command[strcspn(command, "\n")] = 0;/* Remove newline from end of input */

		char *token = strtok(command, " ");/* Parse command line arguments */
		int i = 0;

		while (token != NULL && i < MAX_ARGS)
		{
			args[i++] = token;
			token = strtok(NULL, " ");
		}
		args[i] = NULL;
		/* If no command was entered, continue reading user input */
		if (args[0] == NULL)
			continue;
		run_command(args);
	}
	free(command);
	return (0);
}
