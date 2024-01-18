#include "monty.h"

/**
 * initialize_global_value - initiliazes global variable value
 * @value: number
 *
 * Return: number
*/

int initialize_global_value(int value)
{
	global_items.value = value;

	return (global_items.value);
}

/**
  *nop- does nothing
  *@head: stack head
  *@line_number: line_number
  *Return: none
 */
void nop(stack_t **head, unsigned int line_number)
{
	(void)head;
	(void)line_number;
}

/**
 * push - adds an integer to top of a stack_t stack
 * @head: the head of a stack_t stack
 * @line_number: the current instruction being executed
 *
 * Return: Nothing
*/


void push(stack_t **head, unsigned int line_number)
{
	stack_t *temp;

	temp  = malloc(sizeof(stack_t));
	(void)line_number;

	if (!temp)
	{
		fprintf(stderr, "Error: malloc failed\n");
		free_global_items();
		exit(EXIT_FAILURE);
	}

	temp->n = global_items.value;
	temp->prev = NULL;

	if (*head == NULL)
	{
		*head = temp;
		(*head)->next = NULL;
		return;
	}

	temp->next = *head;
	*head = temp;
}

/**
 * free_stack - frees a stack_t stack
 * @head: head of a stack_t stack
 *
 * Return: NULL
 */

void free_stack(stack_t *head)
{
	if (!head)
		return;

	free_stack(head->next);
	free(head);
}
