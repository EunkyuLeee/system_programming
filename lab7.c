#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>

int main()
{
	char *cwd;
	char buf[256];

	cwd = getcwd(buf, 256);
	setenv("PATH", cwd, 1);
	printf("current PATH env: %s\n", getenv("PATH"));
}
