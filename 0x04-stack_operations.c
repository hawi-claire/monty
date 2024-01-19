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
	if (!(*stack))
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

/**
 * f_pstr - prints the string starting at the top of the stack,
 * followed by a new line
 * @stack: stack head
 * @line_number: the current line we are operating on
 * Return: no return
*/
void f_pstr(stack_t **stack, unsigned int line_number)
{
	stack_t *current;
	int ascii_value;

	current = *stack;
	(void)line_number;

	if (*stack == NULL)
	{
		putchar('\n');
		return;
	}

	while (current != NULL)
	{
		ascii_value = current->n;

		if (ascii_value >= 0 && ascii_value <= 127)
		{
			putchar(ascii_value);
		}
		else
		{
			break;
		}

		if (ascii_value == 0)
			break;

		current = current->next;
	}

	putchar('\n');
}

/**
  *f_rotl- rotates the stack to the top
  *@stack: stack head
  *@line_number: line_number
  *Return: no return
 */
void f_rotl(stack_t **stack,  __attribute__((unused)) unsigned int line_number)
{
	stack_t *temp, *second;

	tail = *stack;

	if (*stack == NULL || (*stack)->next == NULL)
		return;

	temp = *stack;
	second = (*stack)->next;
	*stack = second;

	temp->next = second->next;
	second->next = temp;

	if (temp->next == NULL)
		(*stack)->prev = temp;
	else
		temp->next->prev = temp;
}

/**
  *f_rotr- rotates the stack to the bottom
  *@stack: stack head
  *@line_number: line_number
  *Return: no return
 */
void f_rotr(stack_t **stack, __attribute__((unused)) unsigned int line_number)
{
	stack_t *tail;

	if (*stack == NULL || (*stack)->next == NULL)
		return;

	tail = *stack;

	while (tail->next != NULL)
	{
		tail = tail->next;
		tail->prev->next = NULL;
		tail->next = *stack;
		*stack = tail;
		(*stack)->prev = tail->prev;
		tail->prev = NULL;
	}
}
