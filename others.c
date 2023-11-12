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
