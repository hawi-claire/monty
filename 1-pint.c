#include "monty.h"
/**
 * pint - prints value at the top
 * @head: stack head
 * @line: line number
 * Return: no return
*/
void pint(stack_t **head, unsigned int line)
{
	if (*head == NULL)
	{
		fprintf(stderr, "L%u: can't pint, stack empty\n", line);
		exit(EXIT_FAILURE);
	}

	int top_value = (*head)->n;

	printf("%d\n", top_value);
}
