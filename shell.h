#ifndef _SHELL_H_
#define _SHELL_H_

extern char *program_invocation_name;
extern char **environ;

#include <stdio.h>
#include <stdlib.h>
#include <stddef.h>
#include <string.h>
#include <unistd.h>
#include <sys/wait.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <limits.h>
#include <dirent.h>
#include <signal.h>

/* Structs */
/**
 * struct built_in - Struct to handle the built-ins commands
 * @command: input command to handle
 * @f: function pointer to execute the command
 *
 * Description: has a command an function pointer to react to it
 */
typedef struct built_in
{
	char *command;
	int (*f)(char **argv);
} built_in_t;

int ourexit(char **argv);
int _cd(char **argv);

/* shell functions*/
char *read_line();
void sign_handler(int sig);
char **token_buffer(char *buffer, char *delimit);
char *_strchr(char *s, char b);
unsigned int _strcspn(char *s, char *pre);

void _puts(char *s);
int _putchar(const char c);

char *_strtok(char *s, char *del);

void _error_handler(int status, int err, char **argv);
void _print_base_error(int err, char **argv);
 
char *_strcat(char *str1, char *str2);
int _strcmp(char *s1, char *s2);
char *_strcpy(char *dest, char *src);
char *_strdup(char *str);
int _strlen(char *s);
int _atoi(char *s);

char *_getenv(char *name);
int _printenv(char **argv);
int _setenv(char **argv);
int _unsetenv(char **argv);

int shell_exec(char **argv, built_in_t built_in_arr[]);
int shell_launch(char **argv);
void _freeall(char **argv, char **path);
int check_existence(char *path);

void print_number(int n);
void _non_int(built_in_t arr[]);

#endif
