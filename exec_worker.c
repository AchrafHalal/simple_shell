#include "shell.h"

/**
 * bltin_func - Redirect to builtin functions.
 * @bltin_func: Redirect to builtin functions.
 * Return: 1 if _help works, 0 if exit works.
 */

int (*bltin_func[])(char **args, char *input) = {
	&shell_cd,
	&_help,
	&shell_exit,
	&_env,
};

/**
  * exec_work_builtin - Execute builtin process.
  * @args: List of arguments passed from parsing.
  *
  * @input: Input lines.
  *
  * Return: _launch(args).
  */

int exec_work_builtin(char **args, char *input)
{
	char *bltin_str[] = {"cd", "help", "exit", "env"};
	int i;

	if (args[0] == NULL)
		return (1);

	if (_strcmp(args[0], "setenv") == 0)
		return (_setenv(args[1], args[2]));

	for (i = 0; i < 4; i++)
	{
		if (_strcmp(args[0], bltin_str[i]) == 0)
			return ((*bltin_func[i])(args, input));
	}
	return (_launch(args));
}
