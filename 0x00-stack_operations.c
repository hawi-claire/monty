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

	while (current != NULL)
	{
		printf("%d\n", current->n);
		current = current->next;
	}
}


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


/**
 * pop - prints the top
 * @head: stack head
 * @line_number: line_number
 *
 * Return: none
*/

void pop(stack_t **head, unsigned int line_number)
{
	if (*head == NULL)
	{
		fprintf(stderr, "L%u: can't pop an empty stack\n", line_number);
		exit(EXIT_FAILURE);
	}

	stack_t *temp = *head;

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

	if (*head == NULL || (*head)->next == NULL)
	{
		fprintf(stderr, "L%u: can't swap, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}
	stack_t *first = *head;
	stack_t *second = first->next;

	int temp = first->n;

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
	if (*head == NULL || (*head)->next == NULL)
	{
		fprintf(stderr, "L%u: can't add, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}

	stack_t *top = *head;
	int first_value = top->n;
	stack_t *second = top->next;
	int second_value = second->n;
	*head = second->next;
	free(second);
	free(top);

	int sum = first_value + second_value;

	push(head, sum);
}
