#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <fcntl.h>

int main()
{

	mkfifo("./myfifo", 0777);
	
	int fifo = open("./myfifo", O_RDWR);
	char buf[1024];
	int size = 0;

	while ((size = read(fifo, buf, sizeof(buf))) > 0)
	{
		write(1, buf, size);
	}
}
