#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>

int main(void)
{
	int status;
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
		printf("Parent: Waiting for children\n");
		waitpid(pid[0], &status, 0);
		if (WIFEXITED(status))
		{
			printf("Parent: First Child: %d\n", WEXITSTATUS(status));
		}
		waitpid(pid[1], &status, 0);
		if (WIFEXITED(status))
		{
			printf("Parent: Second Child: %d\n", WEXITSTATUS(status));
		}
		printf("Parent: All Children terminated\n");
	}
}
