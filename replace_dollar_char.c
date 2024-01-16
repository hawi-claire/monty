#include "monty.h"

/**
 * replace_dollar_char - replaces end dollar sign with NULL character
 * @s: the string for whom to remove null character
 *
 * Return: Nothing
*/

void replace_dollar_char(char *s)
{
	int i = 0;

	while (i > -1)
	{
		if (s[i] == '$')
		{
			s[i] = '\0';
			break;
		}

		i++;
	}
}
