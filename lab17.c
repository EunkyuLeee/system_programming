#include <pthread.h>
#include <stdio.h>

void* thread_code(void* param)
{
	int id = (int)param;
	printf("%d\n", id);
}

int main()
{
	pthread_t thread[10];
	
	for (int i = 0; i < 10; i++)
	{
		pthread_create(&thread[i], 0, thread_code, (void*)i);
	}
	for (int i = 0; i < 10; i++)
	{
		pthread_join(thread[i], 0);
	}
}
