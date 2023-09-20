#include "shell.h"

/**
 * _setenv - this function sets an environment variable.
 * @name:Name of the variable
 * @value: Value in the variable.
 * Return: 1 if works.
 */

int _setenv(char *name, char *value)
{
	char *tempval, new_env_var[1024];
	char **currenv = environ;
	char **nenv;
	int count = 0, i;

	if (value == NULL)
	{
		perror("shell:");
	}
	tempval = _getenv_(name);
	if (tempval != NULL)
	{
		_strcpy(tempval, value);
	}
	else
	{
		while (currenv[count] != NULL)
		{
			count++;
		}
		count += 2;
		nenv = malloc(count * sizeof(char *));
		for (i = 0; currenv[i] != NULL; i++)
		{
			nenv[i] = currenv[i];
		}
		_strcat(new_env_var, name);
		_strcat(new_env_var, "=");
		_strcat(new_env_var, value);
		nenv[i] = new_env_var;
		nenv[++i] = NULL;
		environ = nenv;
		free(currenv);
	}

	return (1);
}

/**
  * _env - this function display the environ in the shell.
  * @args: it lists the number of args passed from parsing.
  * @input: Input line for free.
  * Return: 1 on success.
  */

int _env(__attribute__((unused)) char **args,
		__attribute__((unused)) char *input)
{
	int i = 0;

	while (environ[i] != 0)
	{
		/*int len = _strlen(*ep);*/

		_puts(environ[i]);
		_puts("\n");

		i++;
	}
	return (1);
}
