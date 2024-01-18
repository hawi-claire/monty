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
	stack_t *temp = malloc(sizeof(stack_t));

	if (!temp)
	{
		fprint(stderr, "Error: malloc failed\n");
		exit(EXIT_FAILURE);
	}

	temp->n = value;

	if (*head == NULL)
	{
		*head = temp;
		(*head)->next = NULL;
		(*head)->prev = NULL;
		return;
	}

	temp->next = *head;
	temp->prev = NULL;
	*head = temp;
}
