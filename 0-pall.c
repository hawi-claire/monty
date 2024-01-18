#include "monty.h"
/**
 * pall - prints the values on the stack
 * @head: stack head
 * @line_number: no used
 *
 * Return: no return
*/
void pall(stack_t **head, unsigned int line_number)
{
	stack_t *current = *head;

	while (current != NULL)
	{
		printf("%d\n", current->n);
		current = current->next;
	}
}
