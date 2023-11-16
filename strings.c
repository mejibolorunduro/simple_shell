#include "shell.h"

/**
 * str_cpy - copies a string
 * @dest: the destination
 * @src: the source
 *
 * Return: pointer to destination
 */
char *str_cpy(char *dest, char *src)
{
	int q = 0;

	if (dest == src || src == 0)
		return (dest);
	while (src[q])
	{
		dest[q] = src[q];
		q++;
	}
	dest[q] = 0;
	return (dest);
}

/**
 * str_dup - duplicates a string
 * @str: the string to duplicate
 *
 * Return: pointer to the duplicated string
 */
char *str_dup(const char *str)
{
	int length = 0;
	char *ret;

	if (str == NULL)
		return (NULL);
	while (*str++)
		length++;
	ret = malloc(sizeof(char) * (length + 1));
	if (!ret)
		return (NULL);
	for (length++; length--;)
		ret[length] = *--str;
	return (ret);
}

/**
 * _puts - prints an input string
 * @str: the string to be printed
 *
 * Return: Nothing
 */
void _puts(char *str)
{
	int q = 0;

	if (!str)
		return;
	while (str[q] != '\0')
	{
		_putchar(str[q]);
		q++;
	}
}

/**
 * _putchar - writes the character c to stdout
 * @c: The character to print
 *
 * Return: On success 1.
 * On error, -1 is returned, and errno is set appropriately.
 */
int _putchar(char c)
{
	static int q;
	static char buf[WRITE_BUF_SIZE];

	if (c == BUF_FLUSH || q >= WRITE_BUF_SIZE)
	{
		write(1, buf, q);
		q = 0;
	}
	if (c != BUF_FLUSH)
		buf[q++] = c;
	return (1);
}
