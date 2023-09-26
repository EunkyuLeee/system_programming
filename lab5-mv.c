#include <sys/types.h>
#include <unistd.h>
#include <stdio.h>
#include "error.h"

int main(int argc, char* argv[]){
	
	if (link(argv[1], argv[2]) == -1)
		perror("link");
	
	if (unlink(argv[1]) == -1)
		perror("unlink");

	return 0;
}
// gcc lab5-mv.c -o mv
