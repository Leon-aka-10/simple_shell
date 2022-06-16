#include "shell.h"

/**
 * _strpbrk - searches through a string for any set of bytes.
 * @s: string to search through
 * @delims: bytes to search for in the string.
 * Return: pointer to first occurence in s of anything in accept
 */
char *_strpbrk(char *s, char *delims)
{
	char *temp;

	temp = delims;
	for (; *s != '\0'; s++)
	{
		while (*delims != '\0')
		{
			if (*s == *delims)
				return (s);
			delims++;
		}
		delims = temp;
	}
	if (*s == '\0')
		return (0);

	return (s);
}
/**
 * _strtok- replicates strtok, a tokenizer
 * @s: string to be tokenized
 * @delim: delimiter that determines where we split s
 * (@save_ptr: saves index in tokenized s so that repeated
 * fn calls fetch tokens
 * Return: pointer to next token
 */
char *_strtok(char *s, char *delim)
{
	char *token;

	if (s == NULL)
		return (NULL);

	s += _strcspn(s, delim);
	if (*s == '\0')
		return (NULL);

	token = s;
	s = _strpbrk(token, delim);
	if (s != NULL)
		*s = '\0';

	return (token);
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
