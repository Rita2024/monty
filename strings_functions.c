#include "monty.h"

/**
 * _strcmp - Function that compares two strings.
 * @s1: first type string compared
 * @s2: second type string compared
 * Return: 0 if s1 and s2 are equals or otherwise.
 */

int _strcmp(char *s1, char *s2)
{
	int m;

	for (m = 0; s1[m] == s2[m] && s1[m]; m++)
		;
	if (s1[m] > s2[m])
	{
		return (1);
	}

	if (s1[m] < s2[m])
	{
		return (-1);
	}

	return (0);
}

/**
 * _sch - search if a char is inside a string
 * @s: string to review
 * @c: char to find
 * Return: 1 if successful 0 if unsuccessful
 */

int _sch(char *s, char c)
{
	int t = 0;

	while (s[t] != '\0')
	{
		if (s[t] == c)
		{
			break;
		}
		t++;
	}

	if (s[t] == c)
	{
		return (1);
	}

	else
	{
		return (0);
	}
}

/**
 * _strtoky - function that cut a string into tokens depending of the delimit
 * @s: string to cut in parts
 * @d: delimiters
 * Return: first partition
 */

char *_strtoky(char *s, char *d)
{
	static char *pat;
	int x = 0, y = 0;

	if (!s)
		s = pat;

	while (s[x] != '\0')
	{
		if (_sch(d, s[x]) == 0 && s[x + 1] == '\0')
		{
			pat = s + x + 1;
			*pat = '\0';
			s = s + y;

			return (s);
		}

		else if (_sch(d, s[x]) == 0 && _sch(d, s[x + 1]) == 0)
			x++;

		else if (_sch(d, s[x]) == 0 && _sch(d, s[x + 1]) == 1)
		{
			pat = s + x + 1;
			*pat = '\0';
			pat++;
			s = s + y;

			return (s);
		}

		else if (_sch(d, s[x]) == 1)
		{
			y++;
			x++;
		}
	}

	return (NULL);
}
