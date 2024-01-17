#include "monty.h"
#include <stdio.h>

/**
 * open_my_file - opens the file in read mode
 * @filename: file name
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

/**
 * main - prints all args it receives
 * @argc: number of args
 * @argv: array of args
 *
 * return:always 0 (success)
 */
int main(int argc, char *argv[])

{

        int j;


        for (j = 0; j < argc; j++)

        {

                printf("%s\n", argv[j]);

        }

        return (0);

}
