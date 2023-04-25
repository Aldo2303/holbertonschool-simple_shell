#ifndef nnn
#define nnn

extern char **environ;

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/wait.h>
#include <sys/types.h>
#include <sys/stat.h>

char *getprompt(void);
char **tokenizer(char *command, char *delim);
char *get_env(char *env_name);
int eway(char *cmd, char *cmdcpy, char **av, char *path);
int execute(char *command, char *command_cpy, char **av, char *path);
int exec_no_path(char **av, char *path, char *cmdcpy, char *cmd);
char *findcmd(char *cmd, char *path);

#endif
