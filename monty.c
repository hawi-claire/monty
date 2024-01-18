#include "monty.h"

global_items_t global_items;

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
	char *opcode;

	ssize_t bytes_read = 0;
	char *lineptr = NULL;
	unsigned int line_number = 0;
	stack_t *stack = NULL;

	global_items.lineptr = &lineptr;
	global_items.head = stack;
	stack = NULL;

	handle_args(argc);

	monty_file = open_monty_file(argv[1]);
	global_items.file = monty_file;

	do {
		bytes_read = getline(&lineptr, &n, monty_file);
		line_number++;

		if (bytes_read > 1)
		{
			opcode = get_instruction(lineptr, line_number);

			if (!opcode)
				continue;

			execute(opcode, line_number, &stack);
			free(opcode);
		}
	} while (bytes_read != -1);

	free(lineptr);
	free_stack(stack);
	fclose(monty_file);

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
		fprintf(stderr, "Error: Can't open file %s\n", filename);
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
 * @opcode: the opcode
 * @line_number: the current operation
 * @stack: the head node of a stack_t stack
 *
 * Return: Nothing
*/

void execute(char *opcode, int line_number, stack_t **stack)
{
	int i, strs_match;

	instruction_t instruction[11] = {
		{"push", push},
		{"pop", pop},
		{"pall", pall},
		{"pint", pint},
		{"swap", swap},
		{"add", add},
		{"nop", nop},
		{"pchar", pchar}
	};

	if (opcode[0] == '#')
		return;

	for (i = 0; i < 11; i++)
	{
		strs_match = strcmp(opcode, instruction[i].opcode);

		if (strs_match == 0)
		{
			instruction[i].f(stack, line_number);
			return;
		}
	}

	fprintf(stderr, "L%d: unknown instruction %s\n", line_number, opcode);
	free_global_items_and_exit();
}


/**
 * get_instruction - gets opcode and value
 * @s: the string to extrac instruction from
 * @line_number: current instruction
 *
 * Return: a structure containing opcode and value
*/

char *get_instruction(char *s, unsigned int line_number)
{
	char *token, *opcode;

	opcode = malloc(sizeof(char) * BUFF_SIZE);

	if (!opcode)
	{
		fprintf(stderr, "Error: malloc failed\n");
		free_global_items_and_exit();
	}

	token = strtok(s, " \n");

	if (!token)
		return (NULL);

	opcode = strcpy(opcode, token);
	token = strtok(NULL, " \n");

	if ((token && isdigit(token[0])) || token[0] == '-' && isdigit(token[1]))
	{
		initialize_global_value(atoi(token));
	}
	else if ((!token || isdigit(token[0]) == 0) && strcmp(opcode, "push") == 0)
	{
		fprintf(stderr, "L%u: usage: push integer\n", line_number);
		free_global_items_and_exit();
	}
	else if (token && strcmp(opcode, "nop") == 0)
	{
		fprintf(stderr, "L%u: usage: nop\n", line_number);
		free_global_items_and_exit();
	}

	return (opcode);
}
