#include "shell.h"

/**
 * shell_cd - Change the directory.
 * @args: List of arguments passed from parsing
 * @input: Input line for free.
 * Return: 1 if works.
 */

int shell_cd(char **args, __attribute__((unused)) char *input)
{

	if (args[1] == NULL)
	{
		if (chdir(_getenv_("HOME")) != 0)
		{
			perror("shell:");
		}
	}
	else
	{
		if (chdir(args[1]) != 0)
		{
			perror("shell:");
		}
	}
	return (1);
}


/**
 * _help - Display the help for a command.
 * @args: List of arguments passed from parsing.
 * @input: Input line for free.
 * Return: 1 on success.
 */

int _help(__attribute__((unused)) char **args,
		__attribute__((unused)) char *input)
{
	int i;
	char *bltin_str[] = {"cd", "help", "exit"};

	for (i = 0; i < 3; i++)
	{
		write(STDOUT_FILENO, bltin_str[i], _strlen(bltin_str[i]));
		write(STDOUT_FILENO, "\n", 1);
	}
	return (1);
}


/**
 * shell_exit - shell exit command.
 * @args: List of arguments passed from parse.
 * @input: Input line for free.
 * Return: 0 on success.
*/

int shell_exit(__attribute__((unused)) char **args, char *input)
{
	int varble;

	if (args[1] == NULL)
		return (0);

	varble = _atoi(args[1]);

	if (varble < 0)
	{
		perror("shell:");
		return (1);
	}
	else if (varble == 0)
	{
		return (0);
	}
	else if (varble >= 256)
	{
		free(input);
		free(args);
		exit(varble - 256);
	}
	else
	{
		free(input);
		free(args);
		exit(varble);
	}
}
