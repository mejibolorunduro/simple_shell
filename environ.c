#include "shell.h"

/**
 * my_env - prints the current environment
 * @info: Structure containing potential arguments. Used to maintain
 * constant function prototype.
 * Return: Always 0
 */
int my_env(info_t *info)
{
	print_list_str(info->env);
	return (0);
}

/**
 * get_env - gets the value of an environ variable
 * @info: Structure containing potential arguments.
 * @name: env var name
 *
 * Return: the value
 */
char *get_env(info_t *info, const char *name)
{
	list_t *node = info->env;
	char *p;

	while (node)
	{
		p = starts_with(node->str, name);
		if (p && *p)
			return (p);
		node = node->next;
	}
	return (NULL);
}

/**
 * my_setenv - Initialize a new environment variable,
 * or modify an existing one
 * @info: Structure containing potential arguments.
 *  Return: Always 0
 */
int my_setenv(info_t *info)
{
	if (info->argc != 3)
	{
		e_puts("Incorrect number of arguements\n");
		return (1);
	}
	if (set_env(info, info->argv[1], info->argv[2]))
		return (0);
	return (1);
}

/**
 * my_unsetenv - Remove an environment variable
 * @info: Structure containing potential arguments.
 * Return: Always 0
 */
int my_unsetenv(info_t *info)
{
	int q;

	if (info->argc == 1)
	{
		e_puts("Too few arguements.\n");
		return (1);
	}
	for (q = 1; q <= info->argc; q++)
		unset_env(info, info->argv[q]);

	return (0);
}

/**
 * populate_env_list - populates env linked list
 * @info: Structure containing potential arguments.
 * Return: Always 0
 */
int populate_env_list(info_t *info)
{
	list_t *node = NULL;
	size_t q;

	for (q = 0; environ[q]; q++)
		add_node_end(&node, environ[q], 0);
	info->env = node;
	return (0);
}
