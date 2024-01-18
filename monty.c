#include "monty.h"
#include <string.h>

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
	unsigned int line_number = 0;
	stack_t *stack = NULL;

	stack = NULL;

	handle_args(argc);

	monty_file = open_monty_file(argv[1]);

	do {
		bytes_read = getline(&lineptr, &n, monty_file);
		operation = get_instruction(lineptr);
		line_number++;
		execute(operation, line_number, &stack);
		free(operation.opcode);
	} while (bytes_read != -1);

	free(lineptr);

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


/**
 * execute - executes a stack operation
 * @operation: a struct that contains opcode and value
 * @line_number: the current operation
 * @stack: the head node of a stack_t stack
 *
 * Return: Nothing
*/

void execute(operation_t operation, int line_number, stack_t **stack)
{
	int i, strs_match;

	instruction_t instruction[7] = {
		{"push", push},
		{"pop", pop},
		{"pall", pall},
		{"pint", pint},
		{"swap", swap},
		{"add", add},
		{"nop", nop}
	};

	for (i = 0; i < 7; i++)
	{
		strs_match = strcmp(operation.opcode, instruction[i].opcode);

		if (strs_match == 0)
		{
			instruction[i].f(stack, line_number);
		}
	}

	fprintf(stderr, "L%d: unknown instruction %s", line_number, operation.opcode);
	exit(EXIT_FAILURE);
}


/**
 * get_instruction - gets opcode and value
 * @s: the string to extrac instruction from
 *
 * Return: a structure containing opcode and value
*/

operation_t get_instruction(char *s)
{
	operation_t operation;
	char *token, *opcode;

	int global_push_value = 0;

	replace_newline_char(s);
	opcode = malloc(sizeof(char) * BUFF_SIZE);

	/* todo: print to standard error. don't use printf */
	/* todo: the string opcode should be freed by the caller*/
	if (!opcode)
	{
		fprintf(stderr, "Error: malloc failed");
		exit(EXIT_FAILURE);
	}

	token = strtok(s, " ");
	opcode = strcpy(opcode, token);

	token = strtok(NULL, " ");

	if (token)
	{
		global_push_value = atoi(token);
	}

	operation.opcode = opcode;
	operation.value = global_push_value;
	return (operation);
}
