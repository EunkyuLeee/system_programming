#include <sys/types.h>
#include <sys/stat.h>
#include <stdio.h>
#include <time.h>

int main(){
	const char filename[100] = "./stat.txt";
	struct stat buffer;

	stat(filename, &buffer);
	printf("%ld\n%s%s%s", buffer.st_ino, ctime(&buffer.st_ctime), ctime(&buffer.st_mtime), ctime(&buffer.st_atime));
	
	return 0;
}
