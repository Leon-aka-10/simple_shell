#include "shell.h"

/**
 * _strtok - tokenizes a string
 * @s: string to be tokenized
 * @del: delimitator for the tokens
 * Return: pointer to each token
 */
char *_strtok(char *s, char *del)
{
	int c;
	static char *str;

	if (s == NULL)
		s = str;
	c = *s++;
	while (_strchr(del, c))
	{
		if (c == 0)
			return (0);
		c = *s++;
	}
	--s;
	str = s + _strcspn(s, del);
	if (*str)
	{
		*str = 0;
		str++;
	}
	return (s);
}
/**
 * _strchr - locates character in string
 * @s: string
 * @loc: character to locate
 * Return: pointer to the first occurrence of the character
 */
char *_strchr(char *s, char loc)
{
	unsigned int a;

	for (a = 0; s[a] != '\0'; a++)
	{
		if (s[a] == loc)
		{
			return (s + a);
		}
	}
	if (s[a] == loc)
	{
		return (s + a);
	}
	return ('\0');
}

/**
 * _strcspn - gets the length of a prefix substring.
 * @s: initial segment.
 * @accept: accepted bytes.
 * Return: the number of accepted bytes.
 */
unsigned int _strcspn(char *s, char *accept)
{
	unsigned int a, b, alph;

	for (a = 0; s[a] != '\0'; a++)
	{
		alph = 1;
		for (b = 0; accept[b] != '\0'; b++)
		{
			if (s[a] == accept[b])
			{
				alph = 0;
				break;
			}
		}
		if (alph == 1)
		{
			break;
		}
	}
	return (a);
}
