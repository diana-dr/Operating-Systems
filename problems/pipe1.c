#include <unistd.h>
#include <sys/types.h>
#include <stdio.h>
#include <stdlib.h>

int main()
{
	printf("I am %d\n", (int)getpid());
	pid_t pid = fork();
	
	if(pid == 0)
	{
		printf("child\n");
	}	
	else if (pid > 0)
	{
		printf("parent\n");
	}
	else
	{
		printf("fork failed\n");
	}
	
	//printf("fork returned:%d\n", (int) pid);
	//printf("I am %d\n", (int)getpid()); 
	return 0;
}
