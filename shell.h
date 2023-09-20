#ifndef SHELL_H
#define SHELL_H

/* Required libraries */
#include <stdio.h>
#include <sys/wait.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include <stddef.h>

/*** Environmental variables ***/
extern char **environ;


/* customised string function */
int _strlen(char *str);
char *_strcat(char *dest, char *src);
char *_strcpy(char *dest, char *src);
int _strcspn(char *str, const char *delim);
int _strspn(char *str, const char *delim);
int _strcmp(char *s1, char *s2);
char *_strtok_s(char *s, const char *delim, char **sav_str);
char *_strtok(char *s, const char *delim);
int _strncmp(const char *s1, const char *s2, int n);
int _atoi(char *s);


/*** Function prototypes for main functions****/
int _launch(char **args);
char **_checks_path(char **args, int *flag);
char *_getenv_(const char *n);
char **_splits_paths(char *commd, char *copy_commd);
void sigint_handler(int signa);
char **splits_txts(char *commd);
int exec_work_builtin(char **args, char *input);
char *read_commd_(void);
int _setenv(char *name, char *val);

/** allocation of errors**/
int alloc_errors1_(char *buf);
int alloc_errors_(char *buf, char *dest_path);
int allocs_errors(char *buffer);

/* memory allocation */
void *_realloc(void *ptr, unsigned int old_size, unsigned int new_size);

/**
  * _help - the help function
  * @args: list of arguments passed from parsing.
  * @input: input line free.
  * Return: 1 on success.
  */
int _help(__attribute__((unused)) char **args,
		__attribute__((unused)) char *input);

/**
  * _env - the environ function
  * @args: list of arguments passed from parsing.
  * @input: input line free.
  * Return: 1 on success.
  */
int _env(__attribute__((unused)) char **args,
	__attribute__((unused)) char *input);


/** builtins**/
int shell_cd(char **args, __attribute__((unused)) char *input);
int shell_exit(__attribute__((unused)) char **args, char *input);

/**customised getline function**/
ssize_t _getline_(char **line,
		size_t *n, __attribute__((unused))FILE * stream);


int _putchar(char c);
void _puts(char *str);
int _getc(void);

/* interact_loop */
void interact_loop(void);

#endif /* SHELL_H */
