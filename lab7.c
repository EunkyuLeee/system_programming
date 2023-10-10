#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>

int main()
{
	char buf[256];

	getcwd(buf, 256);
	setenv("PATH", buf, 1);
	printf("current PATH env: %s\n", getenv("PATH"));
}
