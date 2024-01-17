#include "monty.h"
/**
 * f_add - adds the top two elements of the stack.
 * @head: stack head
 * @counter: line_number
 * Return: no return
*/
#include "monty.h"

void f_add(stack_t **head, unsigned int counter)
{
	if (*head == NULL || (*head)->next == NULL)
	{
		fprintf(stderr, "L%u: can't add, stack too short\n", counter);
		exit(EXIT_FAILURE);
	}

	stack_t *top = *head;
	int first_value = top->n;
	stack_t *second = top->next;
	int second_value = second->n
	* head = second->next;
	free(second);
	free(top);

	int sum = first_value + second_value;

	push(head, sum);
}
