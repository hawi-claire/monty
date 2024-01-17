#include "monty.h"
#include <stdio.h>

/**
 * fopen - opens the file in read mode
 * @monty.h: file name
 * @r: mode of operation
 *
 * Return: file pointer, null if error occurs
 */

FILE *open_my_file(const char *filename)
{
	FILE *fp = fopen(filename, "r");

	if (fp == NULL)
	{
		fprintf(stderr, "Error opening file: %s\n", filename);

		return fp;
	}
}
