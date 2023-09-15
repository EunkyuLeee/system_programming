#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>

#define BUFSIZE 512

int main(){
	int file;
	char buf[BUFSIZE];
	ssize_t nread;

	file = open("test.txt", O_RDWR);
	
	lseek(file, 10, SEEK_SET);
	
	nread = read(file, buf, BUFSIZE);
	write(1, buf, nread);

	lseek(file, -5, SEEK_END);


	while(lseek(file, -2, SEEK_CUR) != -1){
		read(file, buf, 1);
		write(1, buf, 1);
	}

	close(file);
}
