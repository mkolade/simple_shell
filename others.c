#include "smain.h"

/**
 * free_line_list - Frees a line_list.
 *
 * @head: Address of the head of the linked list.
 *
 * Return: return null.
 */
void free_line_list(line_list **head)
{
	if (head)
	{
		line_list *curr = *head;

		while (curr)
		{
			line_list *temp = curr;

			curr = curr->next;
			free(temp);
		}
		*head = NULL;
	}
}

/**
 * msg_exit_shell - Generates a generic error message for the exit command.
 *
 * @shdata: Data structure containing relevant information.
 *
 * Return: Error message.
 */
char *msg_exit_shell(shell_data *shdata)
{
	int length;
	char *error;
	char *var_str;

	var_str = int_to_string(shdata->counter);
	length = _strlen(shdata->av[0]) + _strlen(var_str);
	length += _strlen(shdata->args[0]) + _strlen(shdata->args[1]) + 23;
	error = malloc(sizeof(char) * (length + 1));

	if (error == 0)
	{
		free(var_str);
		return (NULL);
	}

	/* Concatenate program name, counter, command, and error message */
	_strcpy(error, shdata->av[0]);
	_strcat(error, ": ");
	_strcat(error, var_str);
	_strcat(error, ": ");
	_strcat(error, shdata->args[0]);
	_strcat(error, ": Illegal number: ");
	_strcat(error, shdata->args[1]);
	_strcat(error, "\n\0");
	free(var_str);

	return (error);
}
