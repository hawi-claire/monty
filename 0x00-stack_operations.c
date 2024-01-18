#include "monty.h"

/**
 * pall - prints the values on the stack
 * @head: stack head
 * @line_number: no used
 *
 * Return: no return
*/
void pall(stack_t **head, unsigned int line_number)
{
	stack_t *current = *head;

	(void)line_number;

	while (current != NULL)
	{
		printf("%d\n", current->n);
		current = current->next;
	}
}


/**
 * pint - prints value at the top
 * @head: stack head
 * @line_number: line number
 * Return: no return
*/
void pint(stack_t **head, unsigned int line_number)
{
	int top_value;

	if (*head == NULL)
	{
		fprintf(stderr, "L%u: can't pint, stack empty\n", line_number);
		free_global_items_and_exit();
	}

	top_value = (*head)->n;

	printf("%d\n", top_value);
}


/**
 * pop - prints the top
 * @head: stack head
 * @line_number: line_number
 *
 * Return: no return
*/
void pop(stack_t **head, unsigned int line_number)
{
	stack_t *temp = *head;

	if (*head == NULL)
	{
		fprintf(stderr, "L%u: can't pop an empty stack\n", line_number);
		free_global_items_and_exit();
	}

	*head = temp->next;
	free(temp);
}


/**
 * swap - adds the top two elements of the stack.
 * @head: stack head
 * @line_number: line_number
 * Return: no return
*/
void swap(stack_t **head, unsigned int line_number)
{
	stack_t *first;
	stack_t *second;
	int temp;

	if (*head == NULL || (*head)->next == NULL)
	{
		fprintf(stderr, "L%u: can't swap, stack too short\n", line_number);
		free_global_items_and_exit();
	}

	first = *head;
	second = first->next;
	temp = first->n;

	first->n = second->n;
	second->n = temp;
}
