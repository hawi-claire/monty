#include "monty.h"

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
	int value;

	replace_newline_char(s);
	opcode = malloc(sizeof(char) * 5);

	/* todo: print to standard error. don't use printf */
	/* todo: the string opcode should be freed by the caller*/
	if (!opcode)
	{
		printf("Error: malloc failed");
		exit(EXIT_FAILURE);
	}

	token = strtok(s, " ");
	opcode = strcpy(opcode, token);

	token = strtok(NULL, " ");

	if (token)
	{
		value = atoi(token);
		operation.value = value;
	}
	else
	{
		operation.value = 0;
	}

	operation.opcode = opcode;
	return (operation);
}
