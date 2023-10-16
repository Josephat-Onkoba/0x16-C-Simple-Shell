#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
int main(void)
{
	size_t n = 0;
	char *buf = NULL;
	char *argv[] = {"/bin/ls", "-l", "/usr/", NULL};

	printf("#cisfun$ ");
	getline(&buf, &n, stdin);

    	if (execve(argv[0], argv, NULL) == -1)
    	{
       		 perror("Error:");
   	 }

	return (0);
}
