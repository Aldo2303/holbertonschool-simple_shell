#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>
#include <string.h>

#define MAX_COMMAND_LENGTH 256
#define MAX_ARGS 10

int main() {
	char command[MAX_COMMAND_LENGTH];
	char *args[MAX_ARGS];
	int status;

	while (1) {
		// Leer la entrada del usuario
		printf("$ ");
		fgets(command, MAX_COMMAND_LENGTH, stdin);

		// Eliminar el salto de línea del final de la entrada
		command[strcspn(command, "\n")] = 0;

		// Parsear los argumentos de la línea de comando
		char *token = strtok(command, " ");
		int i = 0;
		while (token != NULL && i < MAX_ARGS) {
			args[i++] = token;
			token = strtok(NULL, " ");
		}
		args[i] = NULL;

		// Si no se ingresó ningún comando, seguir leyendo la entrada del usuario
		if (args[0] == NULL) {
			continue;
		}
		// Comprobación especial para el comando "cd"
		if (strcmp(args[0], "cd") == 0) {
			if (chdir(args[1]) == -1) {
				perror("cd");
			}
			continue;
		}

		// Crear un proceso hijo para ejecutar el comando
		pid_t pid = fork();

		if (pid == 0) {
			// En el proceso hijo, ejecutar el comando
			execvp(args[0], args);

			// Si execvp retorna, hubo un error al ejecutar el comando
			printf("shell: %s: command not found\n", args[0]);
			exit(1);
		} else if (pid > 0) {
			// En el proceso padre, espera a que el proceso hijo termine
			wait(&status);
		} else {
			// Si fork retorna un valor negativo, hubo un error al crear el proceso hijo
			printf("shell: error creating child process\n");
		}
	}

	return 0;
}
