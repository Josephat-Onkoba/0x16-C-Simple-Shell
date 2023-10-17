#include "main.h"

/**
 * _getenv - Get the value of an environment variable.
 *
 * @name: The name of the environment variable to retrieve.
 *
 * Return: The value of the environment variable or NULL if not found.
 */
const char *_getenv(const char *name)
{
	char **env = environ;

	while (*env != NULL)
	{
		if (_strncmp(*env, name, _strlen(name)) == 0)
		{
			return (_strchr(*env, '=') + 1);
		}
		env++;
	}
	return (NULL);
}



/**
 * print_environment - Print the current environment variables.
 */
void print_environment(void)
{
	char **env = environ;

	while (*env != NULL)
	{
		write(STDOUT_FILENO, *env, _strlen(*env));
		write(STDOUT_FILENO, "\n", 1);
		env++;
	}
}
