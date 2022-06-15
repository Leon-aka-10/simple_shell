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
 * _isnumber - checks if chars are digits
 * @c: char to check
 * Return: 1 if yes, 0 if no
 */
int _isnumber(int c)
{
	if (c >= '0' && c <= '9')
		return (1);
	else
		return (0);
}
