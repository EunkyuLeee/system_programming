#include <unistd.h>

int main()
{
	int fd[2];
	pid_t pid;
	char buffer[256];

	pipe(fd);

	pid = fork();

	if (pid != 0)
	{
		close(fd[0]);
		dup2(fd[1], 1);
		execlp("ps", "ps", "-ef", (char *)0);
	}
	else
	{
		close(fd[1]);
		dup2(fd[0], 0);
		execlp("grep", "grep", "telnet", (char *)0);
	}
	return 0;
}
