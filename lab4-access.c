#include <sys/types.h>
#include <fcntl.h>
#include <unistd.h>
#include <sys/stat.h>
#include <error.h>
#include <stdio.h>

int main(int argc, char *argv[]){

	int fd;
	char buf[20];

	if (argc != 2)
		printf("usage: a.out <pathname>\n");

	if (access(argv[1], F_OK) < 0){
		fd = open(argv[1], O_CREAT | O_WRONLY, 0644);
		write(fd, "hello world", 11);
	}
	else{
		fd = open(argv[1], O_RDONLY, 0644);
		read(fd, buf, 20);
		write(1, buf, 20);
	}
	return 0;
}
