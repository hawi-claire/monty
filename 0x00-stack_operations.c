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
		free_global_items();
		exit(EXIT_FAILURE);
	}

	top_value = (*head)->n;

	printf("%d\n", top_value);
}


/**
 * pop - prints the top
 * @head: stack head
 * @line_number: line_number
 *
 * Return: none
*/

void pop(stack_t **head, unsigned int line_number)
{
	stack_t *temp = *head;

	if (*head == NULL)
	{
		fprintf(stderr, "L%u: can't pop an empty stack\n", line_number);
		free_global_items();
		exit(EXIT_FAILURE);
	}

	*head = temp->next;
	free(temp);
}


/**
 * swap - adds the top two elements of the stack.
 * @head: stack head
 * @line_number: line_number
 * Return: none
*/

void swap(stack_t **head, unsigned int line_number)
{
	stack_t *first;
	stack_t *second;
	int temp;

	if (*head == NULL || (*head)->next == NULL)
	{
		fprintf(stderr, "L%u: can't swap, stack too short\n", line_number);
		free_global_items();
		exit(EXIT_FAILURE);
	}

	first = *head;
	second = first->next;
	temp = first->n;

	first->n = second->n;
	second->n = temp;
}


/**
 * add - adds the top two elements of the stack.
 * @head: stack head
 * @line_number: line_number
 * Return: no return
*/

void add(stack_t **head, unsigned int line_number)
{
	stack_t *top, *second;
	int first_value, second_value, sum;

	if (*head == NULL || (*head)->next == NULL)
	{
		fprintf(stderr, "L%u: can't add, stack too short\n", line_number);
		free_global_items();
		exit(EXIT_FAILURE);
	}

	top = *head;
	first_value = top->n;
	second = top->next;
	second_value = second->n;
	*head = second->next;

	free(second);
	free(top);

	sum = first_value + second_value;
	global_items.value = sum;

	push(head, 0);
}
