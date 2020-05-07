#include <pthread.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

pthread_cond_t lock = PTHREAD_COND_INITIALIZER;

void* print_it(void* arg)
{
	int i;
	printf("here1\n");
	pthread_t tid = pthread_self();
	for (i = 0; i < 20; i++)
	{
		printf("thread: %lu printed: %d\n", tid, *(int*) arg);
		usleep(500000);
	}
	return NULL;
}

void *assign_it(void* arg)
{
	pthread_t tid = pthread_self();
	printf("here2\n");
	int i;
	for (i = 0; i < 10; i++)
	{
		printf("thread: %lu assigned: %d\n", tid, *(int*) arg);
		*(int*) arg = random() % 10;
		sleep(1);
	}
	return NULL;
}

int main()
{
	int err;
	int *a;
	a = (int*)malloc(sizeof(int));
	pthread_t ntid[5];
	srandom(time(NULL));
	
	int i;
	for (i = 0; i < 3; i++)
	{
		err = pthread_create(&ntid[i], NULL, assign_it, a);
		if (err != 0)
			printf("exit1\n");
	}
	for (i = 3; i < 5; i++)
	{
		err = pthread_create(&ntid[i], NULL, print_it, a);
		if (err != 0)
			printf("exit2\n");
	}
	for(i = 0; i < 3; i++)
		pthread_join(ntid[i], NULL);
	for (i = 3; i < 5; i++)
		pthread_join(ntid[i], NULL);
	
	return 0;
}
