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
	if (*stack == NULL)
	{
		fprintf(stderr, "L%d: can't pchar, stack empty\n", line_number);
		return;
	}

	char *str = NULL;

	if (is_n_string_pointer)
	{
	str = (*stack)->n;
	}

	if (str != NULL)
	{
		while (*str != '\0')
		{
			putchar(*str);
			str++;
		}
		putchar('\n');
	}
	else
	{
		fprintf(stderr, "L%d: invalid string type at top of stack\n", line_number);
	}
}

/**
  *f_rotl- rotates the stack to the top
  *@stack: stack head
  *@line_number: line_number
  *Return: no return
 */
void f_rotl(stack_t **stack,  __attribute__((unused)) unsigned int line_number)
{
	if (*stack == NULL || (*stack)->next == NULL)
		return;

	stack_t *temp = *stack;
	stack_t *second = (*stack)->next;

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
	if (*stack == NULL || (*stack)->next == NULL)
		return;

	stack_t *tail = *stack;

	while (tail->next != NULL)
	tail = tail->next;

	tail->prev->next = NULL;

	tail->next = *stack;
	*stack = tail;

	(*stack)->prev = tail->prev;
	tail->prev = NULL;
}
