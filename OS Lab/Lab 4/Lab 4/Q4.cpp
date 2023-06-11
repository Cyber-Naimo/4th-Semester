#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

int main()
{
    int n = 4;
    for (int i = 1; i <= n; i++)
	{
        int j = fork();
        if (j == -1) 
		{
            perror("fork");
            exit(0);
        }
        if (j == 0)
		{
            printf("Child process %d started\n", i);
            // do some work here
            printf("Child process %d ended\n", i);
            exit(0);
        }
    }
    int pid, status;
    for (int i = 1; i <= n; i++)
	{
        pid = wait(&status);
        if (pid == -1)
		{
            perror("wait");
            exit(0);
        }
        printf("Child process %d terminated with status %d\n", pid,status;
    }
    return 0;
}
