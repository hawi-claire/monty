#include "monty.h"

/**
 * replace_newline_char - replaces end dollar sign with NULL character
 * @s: the string for whom to remove null character
 *
 * Return: Nothing
*/

void replace_newline_char(char *s)
{
	int i = 0;

	while (1)
	{
		if (s[i] == '\n')
		{
			s[i] = '\0';
			break;
		}

		i++;
	}
}
