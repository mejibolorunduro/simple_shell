#include "shell.h"

/**
 * e_puts - prints an input string
 * @str: the string to be printed
 *
 * Return: Nothing
 */
void e_puts(char *str)
{
	int q = 0;

	if (!str)
		return;
	while (str[q] != '\0')
	{
		e_putchar(str[q]);
		q++;
	}
}

/**
 * e_putchar - writes the character c to stderr
 * @c: The character to print
 *
 * Return: On success 1.
 */
int e_putchar(char c)
{
	static int q;
	static char buf[WRITE_BUF_SIZE];

	if (c == BUF_FLUSH || q >= WRITE_BUF_SIZE)
	{
		write(2, buf, q);
		q = 0;
	}
	if (c != BUF_FLUSH)
		buf[q++] = c;
	return (1);
}

/**
 * put_fd - writes the character c to given fd
 * @c: The character to print
 * @fd: The filedescriptor to write to
 *
 * Return: On success 1.
 */
int put_fd(char c, int fd)
{
	static int q;
	static char buf[WRITE_BUF_SIZE];

	if (c == BUF_FLUSH || q >= WRITE_BUF_SIZE)
	{
		write(fd, buf, q);
		q = 0;
	}
	if (c != BUF_FLUSH)
		buf[q++] = c;
	return (1);
}

/**
 * puts_fd - prints an input string
 * @str: the string to be printed
 * @fd: the filedescriptor to write to
 *
 * Return: the number of chars put
 */
int puts_fd(char *str, int fd)
{
	int q = 0;

	if (!str)
		return (0);
	while (*str)
	{
		q += put_fd(*str++, fd);
	}
	return (q);
}
