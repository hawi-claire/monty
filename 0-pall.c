#include "monty.h"
/**
 * f_pall - prints the values on the stack
 * @head: stack head
 * @line: no used
 * Return: no return
*/
void f_pall(stack_t **head, unsigned int line)
{
	stack_t *current = *head;

	while (current != NULL)
	{
		printf("%d\n", current->n);
		current = current->next;
	}
}
