#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>

#define BUFSIZE 512

int main(){
	int file;
	char buf[BUFSIZE];
	ssize_t nread;

	file = open("test.txt", O_RDONLY);
	
	lseek(file, 10, SEEK_SET);
	
	nread = read(file, buf, BUFSIZE);
	write(1, buf, nread);

	lseek(file, -5, SEEK_END);

	nread = read(file, buf, BUFSIZE);
	write(1, buf, nread);

	close(file);
}
