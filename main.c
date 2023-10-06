#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/wait.h>

#define MAX_INPUT_SIZE 100

void execute_commands(char *input);

int main(int argc, char *argv[]) {
    char *input = (char *)malloc(MAX_INPUT_SIZE);
    size_t input_size = MAX_INPUT_SIZE;
    ssize_t line_length;

    if (input == NULL) {
        perror("malloc");
        return EXIT_FAILURE;
    }

    while (1) {
        write(STDOUT_FILENO, "$ ", 2); // Print the shell prompt

        line_length = getline(&input, &input_size, stdin);

        if (line_length == -1) {
            // Handle end of file (Ctrl+D)
            write(STDOUT_FILENO, "\n", 1);
            free(input);
            break;
        }

        input[line_length - 1] = '\0'; // Remove newline character
        execute_commands(input);
    }

    free(input);
    return 0;
}

void execute_commands(char *input) {
    // Tokenize the input to separate the command and its arguments
    char *command = strtok(input, " ");

    if (command == NULL) {
        return; // Empty line, do nothing
    }

    pid_t child_pid = fork();

    if (child_pid == -1) {
        perror("fork");
        exit(EXIT_FAILURE);
    }

    if (child_pid == 0) {
        // Child process
        char *envp[] = { NULL }; // You can populate envp with environment variables if needed

        if (execve(command, NULL, envp) == -1) { // Execute the command
            perror("execve");
            exit(EXIT_FAILURE);
        }
    } else {
        // Parent process
        wait(NULL); // Wait for the child process to finish
    }
}
