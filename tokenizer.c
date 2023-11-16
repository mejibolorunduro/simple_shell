#include "shell.h"

/**
 * **strtow - splits a string into words. Repeat delimiters are ignored
 * @str: the input string
 * @d: the delimeter string
 * Return: a pointer to an array of strings, or NULL on failure
 */

char **strtow(char *str, char *d)
{
	int q, j, k, m, numwords = 0;
	char **s;

	if (str == NULL || str[0] == 0)
	{
		return (NULL);
	}
	if (!d)
		d = " ";
	for (q = 0; str[q] != '\0'; q++)
	{
		if (!is_delim(str[q], d) && (is_delim(str[q + 1], d) || !str[q + 1]))
			numwords++;
	}

	if (numwords == 0)
		return (NULL);
	s = malloc((1 + numwords) * sizeof(char *));
	if (!s)
		return (NULL);
	for (q = 0, j = 0; j < numwords; j++)
	{
		while (is_delim(str[q], d))
			q++;
		k = 0;
		while (!is_delim(str[q + k], d) && str[q + k])
			k++;
		s[j] = malloc((k + 1) * sizeof(char));
		if (!s[j])
		{
			for (k = 0; k < j; k++)
				free(s[k]);
			free(s);
			return (NULL);
		}
		for (m = 0; m < k; m++)
			s[j][m] = str[q++];
		s[j][m] = 0;
	}
	s[j] = NULL;
	return (s);
}

/**
 * **strtow2 - splits a string into words
 * @str: the input string
 * @d: the delimeter
 * Return: a pointer to an array of strings, or NULL on failure
 */
char **strtow2(char *str, char d)
{
	int q, j, k, m, numwords = 0;
	char **s;

	if (str == NULL || str[0] == 0)
		return (NULL);
	for (q = 0; str[q] != '\0'; q++)
		if ((str[q] != d && str[q + 1] == d) ||
				    (str[q] != d && !str[q + 1]) || str[q + 1] == d)
			numwords++;
	if (numwords == 0)
		return (NULL);
	s = malloc((1 + numwords) * sizeof(char *));
	if (!s)
		return (NULL);
	for (q = 0, j = 0; j < numwords; j++)
	{
		while (str[q] == d && str[q] != d)
			q++;
		k = 0;
		while (str[q + k] != d && str[q + k] && str[q + k] != d)
			k++;
		s[j] = malloc((k + 1) * sizeof(char));
		if (!s[j])
		{
			for (k = 0; k < j; k++)
				free(s[k]);
			free(s);
			return (NULL);
		}
		for (m = 0; m < k; m++)
			s[j][m] = str[q++];
		s[j][m] = 0;
	}
	s[j] = NULL;
	return (s);
}
