#include "shell.h"
/**
 * _fork - fork and execve
 * @stk: array of string
 * @av: array of string
 * @argv: array of strings
 * @envp: array of strings environments
 * Return: None
*/
void _fork(char *stk[], char *av[], char *argv[])
{
	pid_t pid;
	int status;

	pid = fork();
	if (pid == 0)
	{
		execve(stk[0], av);
		perror(argv[0]);
		exit(1);
	}
	else if (pid < 0)
	{
		perror("fork");
		exit(1);
	}
	else
	{
		wait(&status);
	}
}

