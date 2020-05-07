#include <pthread.h>
#include <stdio.h>


void* f(void* n)
{
	printf("%d\n", *(int*)n);
	return NULL;
}

int main()
{
	pthread_t t;
	int n = 100;
	pthread_create(&t, NULL, f,(void *) &n);
	pthread_join(t, NULL);
	return 0;
}
