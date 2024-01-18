#include "monty.h"
/**
 * pop - prints the top
 * @head: stack head
 * @line_number: line_number
 *
 * Return: none
*/
void pop(stack_t **head, unsigned int line_number)
{
	if (*head == NULL)
	{
		fprintf(stderr, "L%u: can't pop an empty stack\n", line_number);
		exit(EXIT_FAILURE);
	}

	stack_t *temp = *head;

	*head = temp->next;

	free(temp);
}
