#include "monty.h"

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
		exit(EXIT_FAILURE);
	}

	temp->n = global_push_value;
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
