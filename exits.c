#include "shell.h"

/**
 * strn_cpy - copies a string
 * @dest: the destination string to be copied to
 * @src: the source string
 * @n: the amount of characters to be copied
 * Return: the concatenated string
 */
char *strn_cpy(char *dest, char *src, int n)
{
	int q, j;
	char *s = dest;

	q = 0;
	while (src[q] != '\0' && q < n - 1)
	{
		dest[q] = src[q];
		q++;
	}
	if (q < n)
	{
		j = q;
		while (j < n)
		{
			dest[j] = '\0';
			j++;
		}
	}
	return (s);
}

/**
 * strn_cat - concatenates two strings
 * @dest: the first string
 * @src: the second string
 * @n: the amount of bytes to be maximally used
 * Return: the concatenated string
 */
char *strn_cat(char *dest, char *src, int n)
{
	int q, j;
	char *s = dest;

	q = 0;
	j = 0;
	while (dest[q] != '\0')
		q++;
	while (src[j] != '\0' && j < n)
	{
		dest[q] = src[j];
		q++;
		j++;
	}
	if (j < n)
		dest[q] = '\0';
	return (s);
}

/**
 * str_chr - locates a character in a string
 * @s: the string to be parsed
 * @c: the character to look for
 * Return: (s) a pointer to the memory area s
 */
char *str_chr(char *s, char c)
{
	do {
		if (*s == c)
			return (s);
	} while (*s++ != '\0');

	return (NULL);
}
