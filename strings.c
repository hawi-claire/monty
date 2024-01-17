/**
  * _strlen - calculates the length of a string
  * @s: the string to calculate the length of
  *
  * Return: Length of string s
  */

int _strlen(char *s)
{
	int chars = 0;
	char characters = *s;

	while (characters != '\0')
	{
		characters = *(s + chars);

		if (characters == '\0')
		{
			break;
		}

		chars++;
	}

	return (chars);
}

/**
  * _strcpy - copies string pointed by src to dest
  * @dest: where to copy to
  * @src: where to copy from
  *
  * Return: pointer to dest
  */

char *_strcpy(char *dest, char *src)
{
	int str_length = _strlen(src);
	int i = 0;

	while (i <= str_length)
	{
		*(dest + i) = *(src + i);
		i++;
	}

	return (dest);

}
