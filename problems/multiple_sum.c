#include <stdlib.h>
#include <pthread.h>
#include <stdio.h>


struct sum_runner_struct {
	long long limit;
	long long answer;
};

void* sum_runner(void* arg)
{
	long long sum = 0;
	struct sum_runner_struct *arg_struct = (struct sum_runner_struct*) arg;
	for (long long i = 0; i <= arg_struct->limit; i++)
		sum += i;
	
	arg_struct->answer = sum;
	return NULL;
}	

int main(int argc, char** argv)
{
	if (argc < 2)
	{
		printf("No.\n");
		exit(2);
	}

	long long num_args = argc - 1;
	struct sum_runner_struct args[num_args];
	pthread_t tids[num_args];
	
	for (int i = 0; i < num_args; i++)
	{
		args[i].limit = atoll(argv[i + 1]);
		
		pthread_create(&tids[i], NULL, sum_runner, &args[i]);
	}

	for (int i = 0; i < num_args; i++)
	{
		pthread_join(tids[i], NULL);
		printf("Sum of %d is %lld\n", tids[i], args[i].answer);
	}
	
	return 0;
}
