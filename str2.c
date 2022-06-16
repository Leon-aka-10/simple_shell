#include "shell.h"

/**
 * _strdup - gives a pointer to memory space
 * @str: string
 * Return: pointer
 */
char *_strdup(char *str)
{
	char *s;

	unsigned int size = 0, i;

	if (!str)
		return (NULL);

	while (str[size])
		size++;

	s = malloc(sizeof(char) * (size + 1));

	if (!s)
		return (NULL);

	for (i = 0; i < size; i++)
		s[i] = str[i];

	s[size] = '\0';
	return (s);
}
/**
 * _strlen - len of string
 * Return: length of string
 * @s: string
 */
int _strlen(char *s)
{
	int length = 0;

	while (*(s + length) != '\0')
	{
		length++;
	}
	return (length);
}

/**
 * _isdigit - defines if string passed is a number
 *
 * @s: input string
 * Return: 1 if string is a number. 0 in other case.
 */
int _isdigit(const char *s)
{
	unsigned int i;

	for (i = 0; s[i]; i++)
	{
		if (s[i] < 48 || s[i] > 57)
			return (0);
	}
	return (1);
}

/**
 * rev_string - reverses a string.
 * @s: input string.
 * Return: no return.
 */
void rev_string(char *s)
{
	int count = 0, i, j;
	char *str, temp;

	while (count >= 0)
	{
		if (s[count] == '\0')
			break;
		count++;
	}
	str = s;

	for (i = 0; i < (count - 1); i++)
	{
		for (j = i + 1; j > 0; j--)
		{
			temp = *(str + j);
			*(str + j) = *(str + (j - 1));
			*(str + (j - 1)) = temp;
		}
	}
}
