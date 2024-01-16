#include <stdio.h>

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
