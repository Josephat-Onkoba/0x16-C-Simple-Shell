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
int main(void);

#endif /* MAIN_H */
