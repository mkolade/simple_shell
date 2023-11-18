#include "smain.h"

/**
 * count_char - counts the repetitions of a char
 *
 * @input: input string
 * @i: index
 * Return: repetitions
 */
int count_char(char *input, int i)
{
	if (*(input - 1) == *input)
		return (count_char(input - 1, i + 1));

	return (i);
}

/**
 * find_sy_error - finds syntax errors
 *
 * @input: input string
 * @i: index
 * @last: last char read
 * Return: index of error. 0 when there are no errors
 */
int find_sy_error(char *input, int i, char last)
{
	int count;

	count = 0;
	if (*input == '\0')
		return (0);

	if (*input == ' ' || *input == '\t')
		return (find_sy_error(input + 1, i + 1, last));

	if (*input == ';')
		if (last == '|' || last == '&' || last == ';')
			return (i);

	if (*input == '|')
	{
		if (last == ';' || last == '&')
			return (i);

		if (last == '|')
		{
			count = count_char(input, 0);
			if (count == 0 || count > 1)
				return (i);
		}
	}

	if (*input == '&')
	{
		if (last == ';' || last == '|')
			return (i);

		if (last == '&')
		{
			count = count_char(input, 0);
			if (count == 0 || count > 1)
				return (i);
		}
	}

	return (find_sy_error(input + 1, i + 1, *input));
}
