#include <dirent.h>
#include <stdio.h>
#include <string.h>

typedef struct dirent Dirent;

int match(char *s1, char *s2);

int main(int argc, char *argv[])
{
	DIR *dir;
	Dirent *dp;

	dir = opendir(argv[1]);
	while ((dp = readdir(dir)) != 0)
	{
		if (match(dp->d_name, argv[2]))
		{
			printf("%ld %s\n", dp->d_ino, dp->d_name);
		}
	}
}

int match(char *s1, char *s2)
{
	int diff = strlen(s1) - strlen(s2);
	if (strlen(s1) > strlen(s2)) return strcmp(&s1[diff], s2) == 0;
	else return 0;
}
