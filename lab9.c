#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>

int main()
{
	int pid[2];
	for (int i = 0; i < 2; i++)
	{
		pid[i] = fork();
		if (pid[i] == 0)
		{
			break;
		}
	}
	if (pid[0] == 0)
	{
		execl("/bin/echo", "echo", "This is Child 1", (char *)0);
		exit(1);
	}
	else if (pid[1] == 0)
	{
		execl("/bin/echo", "echo", "This is Child 2", (char *)0);
		exit(2);
	}
	else
	{
		int status;
		printf("Parent: Waiting for children\n");
		wait(&status);
		wait(&status);
		printf("Parent: All Children terminated\n");
	}
}
