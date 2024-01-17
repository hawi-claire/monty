#include "monty.h"

/**
 * main - runs the monty program
 * @argc: number of args
 * @argv: array of args
 *
 * Return: always 0 (success)
 */

int main(int argc, char *argv[])
{
	FILE *monty_file;
	size_t n;
	operation_t operation;
	
	ssize_t bytes_read = 0;
	char *lineptr = NULL;
	/* char **free = &lineptr; */

	handle_args(argc);

	monty_file = open_monty_file(argv[1]);

	do {
		bytes_read = getline(&lineptr, &n, monty_file);
		operation = get_instruction(lineptr);
		printf("opcode: %s\nvalue: %d\n", operation.opcode, operation.value);
	} while (bytes_read != -1);

	/* free *free */

	return (0);
}


/**
 * open_monty_file - opens the file in read mode
 * @filename: file name
 *
 * Return: file pointer
 */

FILE *open_monty_file(const char *filename)
{
	FILE *monty_file = fopen(filename, "r");

	if (monty_file == NULL)
	{
		fprintf(stderr, "Error opening file: %s\n", filename);
		exit(EXIT_FAILURE);
	}

	return (monty_file);
}

/**
 * handle_args - handles arguments passed to the program
 * @argc: number of arguments passed to the program
 *
 * Return: Nothing
*/

void handle_args(int argc)
{
	if (argc != 2)
	{
		fprintf(stderr, "USAGE: monty file\n");
		exit(EXIT_FAILURE);
	}
}
