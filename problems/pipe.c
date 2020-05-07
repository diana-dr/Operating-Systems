#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main(int argc, char** argv)
{
	pid_t pid;
	int mypipe[2];
	int ret = pipe(mypipe);
	char buf[20];

	if(ret == -1)
	{
		perror("pipe");
		exit(1);
	}
	
	pid = fork();
	if (pid == 0)
	{
		/* child process */
		printf("Child\n");
		write(mypipe[1], "Hello there!", 12);
	}
	else 
	{
		/* parent process */
		printf("Parent\n");
		read(mypipe[0], buf, 15);
		printf("buff: %s\n", buf);	
	}
}	
