#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>

#define BUFSIZE 512

int main(int n, char* s[]){
	int rfile, wfile;
	char buf[BUFSIZE];
	ssize_t nread;

	if((rfile = open(s[1], O_RDONLY)) == -1)
		exit(1);
	if((wfile = open(s[2], O_WRONLY | O_CREAT, 0644)) == -1)
		exit(1);
	
	while((nread = read(rfile, buf, BUFSIZE)) > 0)
		write(wfile, buf, nread);

	close(rfile);
	close(wfile);
}
