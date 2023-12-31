#include <sys/types.h>
#include <sys/wait.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>

int main()
{
	int fd, size, i, status;
	char buf[256];
	int pid[256];

	fd = open("sample.txt", O_RDONLY, 0644);
	size = read(fd, buf, 256);

	for (i = 0; i < size; i++)
	{
		if ((pid[i] = fork()) == 0)
		{
			break;
		}
		sleep(1);
	}
	if (i < size && pid[i] == 0)
	{
		int wfd;
		wfd = open("output.txt", O_WRONLY | O_CREAT | O_APPEND, 0644);
		write(wfd, buf, i + 1);
		write(wfd, "\n", 1);
		close(wfd);
		exit(1);
	}
	else
	{
		for (int j = 0; j < size; j++)
		{
			waitpid(pid[j], &status, 0);
		}
	}
}
