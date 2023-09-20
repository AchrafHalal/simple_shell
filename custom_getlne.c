#include "shell.h"

/**
 * _getline_ -  Reads an entire line from stream,
 * Description: storing the address of
 * the buffer containing the text into *b.
 * @line: pointer to buffer which contains read text
 * @n: size of buffer
 * @stream: File to read from.
 * Return: Return the number of char read,
 * including the delimiter character.
 */

ssize_t _getline_(char **line, size_t *n, __attribute__((unused))FILE * stream)
{
	size_t tempsize = 1024, indx = 0;
	int a, c = 0;
	char *buf;

	if (*n == 0)
		tempsize = 1024;
	buf = malloc(sizeof(char) * (tempsize));
	if (allocs_errors(buf) == -1)
		return (-1);
	*line = buf;
	while (1) /* Infinite loop for prompt*/
	{ fflush(stdout);
		a = _getc();
		if (a == EOF || a == '\n')
		{ *(buf + indx) = '\0';
			if (a == EOF)
				return (-1);
			else
				return (indx + 1);
		}
		else if (a == ' ')
		{
			if (c == 0)
			{ c = 1;
				*(buf + indx) = a;
				indx++;
			}
		}
		else
		{ c = 0;
			*(buf + indx) = a;
			indx++;
		}
		if (indx >= tempsize)
		{ tempsize += 1024;
			buf = _realloc(buf, tempsize - 1024, tempsize);
			if (allocs_errors(buf) == -1)
				return (-1);
		}
	}
}
