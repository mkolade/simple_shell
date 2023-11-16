#include "smain.h"

/**
 * main - Main entry point
 * @ac: number of argument count
 * @av: number of argument vector
 *
 * Return: 0 on success.
 */
int main(int ac, char **av)
{
	shell_data shdata;
	(void) ac;

	signal(SIGINT, getSignal);
	setData(&shdata, av);
	shellPrompt(&shdata);
	freeData(&shdata);
	if (shdata.status < 0)
		return (255);
	return (shdata.status);
}
/**
 * freedata - frees up data structure
 * @shdata: data structure
 * Return: return null
 */
void freeData(shell_data *shdata)
{
	unsigned int i;

	for (i = 0; shdata->_environ[i]; i++)
	{
		free(shdata->_environ[i]);
	}

	free(shdata->_environ);
	free(shdata->pid);
}

/**
 * setdata - Initialize the data structure
 * @shdata: data structure
 * @av: argument vector
 * Return: return null
 */
void setData(shell_data *shdata, char **av)
{
	unsigned int i;

	shdata->av = av;
	shdata->input = NULL;
	shdata->args = NULL;
	shdata->status = 0;
	shdata->counter = 1;

	for (i = 0; environ[i]; i++)
		;

	shdata->_environ = malloc(sizeof(char *) * (i + 1));

	for (i = 0; environ[i]; i++)
	{
		shdata->_environ[i] = _strdup(environ[i]);
	}

	shdata->_environ[i] = NULL;
	shdata->pid = int_to_string(getpid());
}

/**
 * shellprompt - Loops of shell
 * @shdata: data is relevant (av, input, args)
 *
 * Return: return null.
 */
void shellPrompt(shell_data *shdata)
{
	int to_continue, i_eof;
	char *input;

	to_continue = 1;
	while (to_continue == 1)
	{
		write(STDIN_FILENO, "^J-S^ > ", 8);
		input = _get_line(&i_eof);
		if (i_eof != -1)
		{
			input = without_comment(input);
			if (input == NULL)
				continue;

			if (check_syntax_error(shdata, input) == 1)
			{
				shdata->status = 2;
				free(input);
				continue;
			}

			input = rep_str_var(input, shdata);
			to_continue = div_commands(shdata, input);
			shdata->counter += 1;
			free(input);
		}
		else
		{
			to_continue = 0;
			free(input);
		}
	}
}



/**
 * getSignal - Handle the Ctrl+C call in the prompt
 * @s: Signal handler
 */
void getSignal(int s)
{
	(void)s;
	write(STDOUT_FILENO, "\n^J-S^ > ", 8);
}
