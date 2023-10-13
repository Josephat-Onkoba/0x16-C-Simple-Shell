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
		execute_command_with_args(command);
	}
	else
	{
		/* Parent process */
		wait(NULL); /* Wait for the child process to finish */
	}
}

/**
 * execute_command_with_args - Execute a command with its arguments.
 * @command: The command to execute.
 */
void execute_command_with_args(char *command)
{
	/* Command-line arguments */
	char **argv = (char **)malloc(sizeof(char *) * 32);
	int arg_count = 0;
	char *arg;

	argv[arg_count++] = command;

	/* Tokenize the rest of the input as arguments */
	arg = strtok(NULL, " ");
	while (arg != NULL && arg_count < 31)
	{
		argv[arg_count++] = arg;
		arg = strtok(NULL, " ");
	}

	argv[arg_count] = NULL; /* Null-terminate the argument array */

	if (execve(command, argv, environ) == -1)
	{
		perror("execve");
		exit(EXIT_FAILURE);
	}

	free(argv);
}
