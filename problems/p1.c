#include <fcntl.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void write_data (FILE * stream)
{
  char * myfifo = "myfifo";
  mkfifo(myfifo, 0666); 
  
  int fd = open(myfifo, O_WRONLY);
  if (ferror (stream))
  {
      fprintf (stderr, "Output to stream failed.\n");
      exit (EXIT_FAILURE);
  }
  long length = 0,r;
  char * b = malloc(sizeof(char)*100);
  char * buffer = malloc(1000000);
  while((r = fread(b,sizeof(char), 100, stream))>0)
  {
	printf("%ld\n",r);
	length += r;
	strcat(buffer,b);
  }
  printf("%ld\n",length);
  write(fd, &length, sizeof(long));
  write(fd, buffer, length);
  close(fd);
}
	
int main(int argc, char *const argv[]) {
	FILE *output;
	char command[512];
	int i;
	char * buffer;
	for(i = 1; i < argc; i++)
	{
		buffer = malloc(strlen(argv[i]) + 5);
     		strcpy(buffer,argv[i]);
		strcat(command,buffer);
		strcat(command," ");
		free(buffer);
	}
	output = popen(command, "r");
	
	if (!output)
	{
		printf("failed");
		return EXIT_FAILURE;
	}
	write_data(output);
	return 0;
}
