#include "main.h"

/**
 * execute_commands - Execute the commands entered by the user.
 * @input: The input string containing the command.
 */
void execute_commands(char *input)
{
	/* Tokenize the input to separate the command and its arguments */
	char *command = strtok(input, " ");
	pid_t child_pid;

	if (command == NULL)
	{
		return; /* Empty line, do nothing */
	}

	child_pid = fork();

	if (child_pid == -1)
	{
		perror("fork");
		exit(EXIT_FAILURE);
	}

	if (child_pid == 0)
	{
		/* Child process */
		char **argv = malloc(sizeof(char *) * 2); /* Command-line arguments */

		argv[0] = command;
		argv[1] = NULL;

		if (execve(command, argv, NULL) == -1)
		{
			perror("execve");
			exit(EXIT_FAILURE);
		}

		free(argv);
	}
	else
	{
		/* Parent process */
		wait(NULL); /* Wait for the child process to finish */
	}
}
