#include <sys/types.h>
#include <sys/wait.h>
#include <fcntl.h>
#include <unistd.h>

int main()
{
	int fd, size, i, status, pid;
	char buf[256];

	fd = open("sample.txt", O_RDONLY, 0644);
	size = read(fd, buf, 256);

	for (i = 0; i < size; i++)
	{
		if ((pid = fork()) == 0)
		{
			int wfd;
			wfd = open("output.txt", O_WRONLY | O_CREAT | O_APPEND, 0644);
			write(wfd, buf, i + 1);
			write(wfd, "\n", 1);
			close(wfd);
			break;
		}
		else
		{
			waitpid(pid, &status, 0);
		}
	}
	
}
