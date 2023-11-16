#include "smain.h"

/**
 * exec_line - finds built-ins and commands
 *
 * @shdata: data relevant (args)
 * Return: 1 on success.
 */
int exec_line(shell_data *shdata)
{
	int (*builtin)(shell_data *shdata);

	if (shdata->args[0] == NULL)
		return (1);

	builtin = get_builtin(shdata->args[0]);

	if (builtin != NULL)
		return (builtin(shdata));

	return (cmd_execve(shdata));
}
