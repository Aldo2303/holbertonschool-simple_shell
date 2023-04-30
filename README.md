# Simple Shell

  
A shell is a user interface that allows users to interact with an operating system by entering text-based commands on a command line. It is a program that runs on top of the operating system kernel and provides an interface for users to execute commands and run programs.

## Index
- [Files](#Files)
- [Functions](#Functions)
- [Functions and system calls allowed](#Functions_and_system_calls_allowed)
- [Compilation](#Compilation)
- [ Authors](#Authors)

# Files

- shell.h
	> The shell.h file is a header file that includes function declarations and other definitions necessary for a shell program implementation.
	
- main.c
	> The main.c file is the central source code file of a shell program. It contains the main function and serves as the entry point of the program. The file also includes calls to other external functions that provide the required functionality for the shell, such as parsing user input, executing commands, and handling signals. The code in main.c coordinates the overall functioning of the shell program and calls the appropriate functions to execute the user commands.
	
- _gentenv.c
	> The _getenv.c file is a C source code file that contains the implementation of the get_env function. This function uses the environ variable to retrieve the string value of a specified environment variable. The file is a crucial component of shell programs that rely on environment variables to execute user commands.
	
- execute.c
	> The file contains the implementation of the eway, execute, and exec_no_path functions. The eway function checks if the user's command is "exit", if so, the shell stops. The execute function uses fork and execve to execute commands in the operating system. Finally, the exec_no_path function uses findcmd to search for the command within the PATH environment variable. These functions are essential for the proper functioning of the shell and its execution.
	
- findcmd.c
	> The file contains the implementation of the findcmd function. This function separates the PATH environment variable into its corresponding directories and saves them into a double array. It then concatenates the command with each directory path to create the full path to the command. If the command is found in any of the directories, the full path is returned. This function is essential for executing commands within the shell.
	
- token.c
	> The token.c file is responsible for the implementation of the tokenizer function. This function is essential for parsing user input and executing commands within the shell. The file contains additional code for manipulating strings and arrays, which is necessary for the tokenizer function to work properly. The tokenizer function plays a critical role in the overall functionality of the shell.

## Functions
-main
>The main function is the entry point of the program. It contains the main logic of the shell program and calls other functions as needed.

-get_env
>This function takes a string argument that corresponds to an environment variable name, and returns the value of that variable as a string.

-tokenizer 
>This function takes a string argument that corresponds to a command entered by the user, and returns an array of strings where each element is a token in the command.

-eway
>This function checks if the command entered by the user is "exit" and returns 1 if it is. Otherwise, it returns 0.

-execute
>This function forks a child process to execute a command entered by the user. It uses the `execve()` system call to replace the child process with the command to be executed.

-exec_no_path
>This function searches for the command in the directories listed in the `PATH` environment variable. If it finds the command, it executes it using the `execute()` function. If it doesn't find the command, it returns an error message.

-findcmd
>This function takes a command name as input and searches for it in the directories listed in the `PATH` environment variable. It returns the full path to the command if it is found, or NULL if it is not found.

## Functions_and_system_calls_allowed

-   all functions from strings.h
-   `access`  (man 2 access)
-   `chdir`  (man 2 chdir)
-   `close`  (man 2 close)
-   `closedir`  (man 3 closedir)
-   `execve`  (man 2 execve)
-   `exit`  (man 3 exit)
-   `_exit`  (man 2 _exit)
-   `fflush`  (man 3 fflush)
-   `fork`  (man 2 fork)
-   `free`  (man 3 free)
-   `getcwd`  (man 3 getcwd)
-   `getline`  (man 3 getline)
-   `getpid`  (man 2 getpid)
-   `isatty`  (man 3 isatty)
-   `kill`  (man 2 kill)
-   `malloc`  (man 3 malloc)
-   `open`  (man 2 open)
-   `opendir`  (man 3 opendir)
-   `perror`  (man 3 perror)
-   `printf`  (man 3 printf)
-   `fprintf`  (man 3 fprintf)
-   `vfprintf`  (man 3 vfprintf)
-   `sprintf`  (man 3 sprintf)
-   `putchar`  (man 3 putchar)
-   `read`  (man 2 read)
-   `readdir`  (man 3 readdir)
-   `signal`  (man 2 signal)
-   `stat`  (__xstat) (man 2 stat)
-   `lstat`  (__lxstat) (man 2 lstat)
-   `fstat`  (__fxstat) (man 2 fstat)
-   `strtok`  (man 3 strtok)
-   `wait`  (man 2 wait)
-   `waitpid`  (man 2 waitpid)
-   `wait3`  (man 2 wait3)
-   `wait4`  (man 2 wait4)
-   `write`  (man 2 write)

## Compilation
Clone this repository and compile the files in the following way:
```
gcc -Wall -Werror -Wextra -pedantic -std=gnu89 *.c -o hsh
```

You can rename the current file by clicking the file name in the navigation bar or by clicking the **Rename** button in the file explorer.

## Authors

Aldo Sanchez

Franco Herrera
