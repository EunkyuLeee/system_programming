#include <signal.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

void sig_handler();

int count = 0;

int main()
{
	signal(SIGINT, sig_handler);
	signal(SIGQUIT, sig_handler);
	for ( ; ; ) pause();
}

void sig_handler(int signo)
{
	if (signo == SIGINT)
	{
		count++;
		printf("\ncount: %d\n", count);
	} else if (signo == SIGQUIT)
	{
		printf("\nterminate program\n");
		exit(1);
	}
}
