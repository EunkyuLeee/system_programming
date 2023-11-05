#include <sys/wait.h>
#include <signal.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

void int_handler(int sig)
{
	printf("Process %d received signal %d\n", getpid(), sig);
	exit(0);
}

int main()
{
	pid_t c_pid;
	int status;

	signal(SIGINT, int_handler);

	c_pid = fork();

	if (c_pid == 0)
	{
		while(1);
	}
	else
	{
		sleep(1);
		kill(c_pid, SIGINT);
		wait(&status);
		if (WIFEXITED(status))
		{
			printf("Child process exited with status: %d\n", WEXITSTATUS(status));
		}
	}
}
