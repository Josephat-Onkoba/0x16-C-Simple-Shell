#include "main.h"


/**
 * main - The main entry point of the program.
 *
 * Return: Always 0.
 */
int main(void)
{
	char *input = (char *)malloc(MAX_INPUT_SIZE);
	size_t input_size = MAX_INPUT_SIZE;
	ssize_t line_length;

	if (input == NULL)
	{
		perror("malloc");
		return (EXIT_FAILURE);
	}

	while (1)
	{
		write(STDOUT_FILENO, "$ ", 2); /* Print the shell prompt */

		line_length = getline(&input, &input_size, stdin);

		if (line_length == -1)
		{
			/* Handle end of file (Ctrl+D) */
			write(STDOUT_FILENO, "\n", 1);
			free(input);
			break;
		}

		input[line_length - 1] = '\0'; /* Remove newline character */
		execute_commands(input);
	}

	free(input);
	return (0);
}
