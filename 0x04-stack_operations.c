#include "monty.h"

/**
 * pchar - prints the ascii char that corresponds
 * with value at the top of the stack
 * @stack: the head of stack
 * @line_number: the current line we're operating on
 *
 * Return - Nothing
*/

void pchar(stack_t **stack, unsigned int line_number)
{
	if (!(*stack)->n)
	{
		fprintf(stderr, "L%u: can't pchar, stack empty\n", line_number);
		free_global_items_and_exit();
	}

	if ((*stack)->n > 127 || (*stack)->n < 0)
	{
		fprintf(stderr, "L%u: can't pchar, value out of range\n", line_number);
		free_global_items_and_exit();
	}

	printf("%c\n", (*stack)->n);
}
