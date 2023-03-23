#include "monty.h"

/**
 * _strcmp - compares two strings
 * @s1: string1
 * @s2: string2
 * Return: 0 if s1 and s2 are equals
 */
int _strcmp(char *s1, char *s2)
{
	int i;

	for (i = 0; s1[i] == s2[i] && s1[i]; i++)
	{
		;
	}
	if (s1[i] > s2[i])
	{
		return (1);
	}
	if (s1[i] < s2[i])
	{
		return (-1);
	}
	return (0);
}

/**
 * _search - search for char in string
 * @s: stirng to review
 * @c: char to find
 * Return: 1 success || 0 not
 */
int _search(char *s, char c)
{
	int cont = 0;

	while (s[cont] != '\0')
	{
		if (s[cont] == c)
		{
			break;
		}
		cont++;
	}
	if (s[cont] == c)
	{
		return (1);
	}
	else
	{
		return (0);
	}
}

/**
 * _strtok - function to tokenize string
 * @s: string to tokenize
 * @d: delimiter
 * Return: first partition
 */
char *_strtok(char *s, char *d)
{
	static char *x;
	int i = 0, j = 0;

	if (!s)
	{
		s = x;
	}
	while (s[i] != '\0')
	{
		if (_search(d, s[i]) == 0 && s[i + 1] == '\0')
		{
			x = s + i + 1;
			*x = '\0';
			s = s + j;
			return (s);
		}
		else if (_search(d, s[i]) == 0 && _search(d, s[i + 1]) == 0)
		{
			i++;
		}
		else if (_search(d, s[i]) == 0 && _search(d, s[i + 1]) == 1)
		{
			x = s + i + 1;
			*x = '\0';
			x++;
			s = s + j;
			return (s);
		}
		else if (_search(d, s[i]) == 1)
		{
			j++;
			i++;
		}
	}
	return (NULL);
}
