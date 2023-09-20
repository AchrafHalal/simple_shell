#include "shell.h"

/**
 * _getenv - get the value of an environment variable
 * @name: the name of the environment variable
 * @envp: array of strings of environment variables
 * Return: pointer to the value of the environ variable, or NULL if not found
 */

char *_getenv(char *name, char **envp)
{
	char *env, *token, *value;

	while (*envp != NULL)
	{
		env = _strdup(*envp);
		token = strtok(env, "=");
		if (_strcmp(name, env, _strlen(name)) == 0)
		{
			token = strtok(NULL, "=");
			value = _strdup(token);
			free(env);
			return (value);
		}
		envp++;
		free(env);
	}
	free(name);
	return (NULL);
}
