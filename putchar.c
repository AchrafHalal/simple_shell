#include "shell.h"
/**
 * _putchar - prints a character c without a new line
 * @c: character input
 * Return: 1 on success -1 Other wise
 */
int _putchar(char c)
{
	return (write(1, &c, 1));
}

