#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
	FILE *read_fp, *write_fp;
	char buf[256];
	int chars_read;

	memset(buf, '\0', sizeof(buf));
	read_fp = popen("who", "r");
	if (read_fp != NULL)
	{
		chars_read = fread(buf, sizeof(char), sizeof(buf), read_fp);
		pclose(read_fp);
		write_fp = popen("sort", "w");
		if (write_fp != NULL)
		{
			fwrite(buf, sizeof(char), sizeof(buf), write_fp);
			pclose(write_fp);
			exit(0);
		}
		exit(1);
	}
}
