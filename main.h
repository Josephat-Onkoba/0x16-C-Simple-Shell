#ifndef MAIN_H
#define MAIN_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/wait.h>

extern char **environ; /*Declare environ*/

#define MAX_INPUT_SIZE 100

void execute_commands(char *input);
void execute_command_with_args(char *command);
int main(void);

#endif /* MAIN_H */
