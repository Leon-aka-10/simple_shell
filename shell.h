#ifndef _SHELL_H_
#define _SHELL_H_

#define BUFSIZE 1024
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
  * struct builtin_commands - stuct for function pointers to builtin commands
  * @cmd_str: commands (env, cd, alias, history)
  * @fun: function
  */
typedef struct builtin_commands
{
	char *cmd_str;
	int (*fun)();
} builtin_t;


/**
 * struct env_path - linked list for environmental variables
 * @str: holds environmental variable string
 * @len: holds the length of the string
 * @next: points to next node
 */
typedef struct env_path
{
	char *str;
	unsigned int len;
	struct env_path *next;

} list_t;


int (*_builtin(char *cmd))();
int ourexit(char **tokens, list_t *linkedlist_path, char *buffer);
int _cd(char **tokens);
int _alias(void);
int _history(void);

/* shell functions*/
char *_strchr(char *s, char b);
unsigned int _strcspn(char *s, char *pre);

void _puts(char *s);
int _putchar(const char c);

char *_strtok(char *s, char *del);

void _error_handler(int status, int err, char **argv);
void _print_base_error(int err, char **argv);

char *_strcat(char *str1, char *str2);
int _strcmp(char *s1, char *s2);
int _strncmp(char *s1, char *s2, size_t bytes);
char *_strcpy(char *dest, char *src);
char *_strdup(char *str);
int _strlen(char *s);
int _atoi(char *s);

void shell_exec(char *argv[], list_t *linkedlist_path, char **av);
char **split_line(char *line);

char *_getenv(char *name);
int _setenv(char **tokens);
int _unsetenv(char **tokens);
int _printenv(char **tokens, list_t *environment);

list_t *add_node(list_t **head, char *str, unsigned int len);
list_t *path_list(void);
list_t *environ_list(void);
char *_which(char *cmd, list_t *linkedlist_path);
void free_list(list_t *head);

int _isnumber(int c);

void *_realloc(void *ptr, unsigned int old_size, unsigned int new_size);
void __exit(char **str, list_t *env);
void free_double_ptr(char **str);

#endif
