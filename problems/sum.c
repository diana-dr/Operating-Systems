#include <stdlib.h>
#include <pthread.h>
#include <stdio.h>

long long sum = 0;

void* sum_runner(void* arg)
{
	long long limit = *(long long*) arg;
	for (long long i = 0; i <= limit; i++)
		sum += i;
	
	return NULL;
}	

int main(int argc, char** argv)
{
	if (argc < 2)
	{
		printf("No.\n");
		exit(2);
	}
	long long limit = atoll(argv[1]);
	
	pthread_t id;

	pthread_create(&id, NULL, sum_runner, &limit);
	pthread_join(id, NULL);
	printf("sum = %lld\n", sum);
	
	return 0;
}
