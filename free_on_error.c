#include "monty.h"

/**
 * free_global_items - frees items
 *
 * Return: Nothing
*/

void free_global_items(void)
{
	fclose(global_items.file);
	free(*global_items.lineptr);
	free_stack(global_items.head); /* test whether this works */
}
