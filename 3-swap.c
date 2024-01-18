#include "monty.h"
/**
 * f_swap - adds the top two elements of the stack.
 * @head: stack head
 * @counter: line_number
 * Return: none
*/
void f_swap(stack_t **head, unsigned int counter)
{

	if (*head == NULL || (*head)->next == NULL)
	{
		fprintf(stderr, "L%u: can't swap, stack too short\n", counter);
		exit(EXIT_FAILURE);
	}
	stack_t *first = *head;
	stack_t *second = first->next;

	int temp = first->n;

	first->n = second->n;

	1second->n = temp;

}
