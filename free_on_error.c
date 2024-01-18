#include "monty.h"

/**
 * free_global_items_and_exit - frees items
 *
 * Return: Nothing
*/

void free_global_items_and_exit(void)
{
	fclose(global_items.file);
	free(*global_items.lineptr);
	free_stack(global_items.head); /* test whether this works */
	exit(EXIT_FAILURE);
}
