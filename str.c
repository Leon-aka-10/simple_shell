#include "shell.h"
/**
 * _strcat - concatenates two strings
 * @str1: first string
 * @str2: second string to be concatenated
 * Return: pointer to the concatenated string
 */
char *_strcat(char *str1, char *str2)
{
	char *concatstr;
	int len1 = _strlen(str1), len2 = _strlen(str2), iter1, iter2;

	concatstr = malloc(sizeof(char) * (len1 + len2 + 1));
	if (!concatstr)
	{
		printf("Error: impossible to allocate memory");
		exit(98);
	}
	for (iter1 = 0; str1[iter1] != '\0'; iter1++)
	{
		concatstr[iter1] = str1[iter1];
	}
	for (iter2 = 0; str2[iter2] != '\0'; iter2++)
	{
		concatstr[iter1 + iter2] = str2[iter2];
	}
	concatstr[iter1 + iter2] = '\0';
	return (concatstr);
}

/**
 * _strcmp - compares two strings
 * @s1: string one
 * @s2: string two
 * Return: 0 if match, anything else if they don't match
 */
int _strcmp(char *s1, char *s2)
{
	int i = 0, j = 0;

	for (; j == 0; i++)
	{
		if ((s1[i] == '\0') && (s2[i] == '\0'))
		{
			break;
		}
		j = s1[i] - s2[i];
	}
	return (j);
}
/**
 * _strcpy - copies the string pointed to by src,
 * including the terminating null byte, to the
 * buffer pointed to by dest.
 * @dest: destination.
 * @src: source.
 * Return: the pointer to dest.
 */
char *_strcpy(char *dest, char *src)
{
	int a = -1;

	do {
		a++;
		dest[a] = src[a];
	} while (src[a] != '\0');

	return (dest);
}
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
