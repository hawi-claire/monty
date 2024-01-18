#include "monty.h"
/**
 * f_add - adds the top two elements of the stack.
 * @head: stack head
 * @line_number: line_number
 * Return: no return
*/

void f_add(stack_t **head, unsigned int line_number)
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
