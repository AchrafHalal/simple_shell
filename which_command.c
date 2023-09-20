#include "shell.h"

/**
 * _which - Find the full path of a command
 * @command: Command to find
 * @env: Environment variables array
 * Return: Full path of the command
 */

char *_which(char *command, char **env)
{
	char *path = _getenv("PATH", env), *token, *full_path = NULL;
	struct stat st;
	char *command_copy = strdup(command);
	char *command_name = strtok(command_copy, " ");
	char *command2 = strtok(NULL, " ");

	token = strtok(path, ":");
	while (token != NULL)
	{
		full_path = malloc(sizeof(char) * 50);
		if (full_path == NULL)
		{
			perror("malloc");
			free(command_name);
			free(command2);
			free(command_copy);
			free(path);
			free(command);
			exit(1);
		}
		_strcpy(full_path, token);
		_strcat(full_path, "/");
		_strcat(full_path, command_name);
		if (stat(full_path, &st) == 0)
		{
			if (command2 != NULL)
			{
				strcat(full_path, " ");
				strcat(full_path, command2);
			}
			free(command_copy);
			free(path);
			return (full_path);
		}
		free(full_path);
		token = strtok(NULL, ":");
	}
	free(command_copy);
	free(path);
	return (_strdup(command));
}

