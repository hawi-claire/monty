#include "monty.h"
/**
 * swap - adds the top two elements of the stack.
 * @head: stack head
 * @line_number: line_number
 * Return: none
*/
void swap(stack_t **head, unsigned int line_number)
{

	if (*head == NULL || (*head)->next == NULL)
	{
		fprintf(stderr, "L%u: can't swap, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}
	stack_t *first = *head;
	stack_t *second = first->next;

	int temp = first->n;

	first->n = second->n;

	second->n = temp;
}
