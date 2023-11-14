#include <fcntl.h>
#include <unistd.h>

int main()
{
	int fifo, size = 0;
	char buf[1024];

	fifo = open("./myfifo", O_RDWR);
	while ((size = read(0, buf, sizeof(buf))) > 0)
	{
		write(fifo, buf, size);
	}
}
