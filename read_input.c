#include "smain.h"

/**
 * assignLine - assigns the line var for getLine
 * @lineptr: Buffer that stores the input string
 * @n: Size of lineptr
 * @buffer: String that is been called to line
 * @j: Size of buffer
 */
void assignLine(char **lineptr, size_t *n, char *buffer, size_t j)
{
	if (*lineptr == NULL)
	{
		if (j > BUFSIZE)
			*n = j;
		else
			*n = BUFSIZE;
		*lineptr = buffer;
	}
	else if (*n < j)
	{
		if (j > BUFSIZE)
			*n = j;
		else
			*n = BUFSIZE;
		*lineptr = buffer;
	}
	else
	{
		_strcpy(*lineptr, buffer);
		free(buffer);
	}
}
