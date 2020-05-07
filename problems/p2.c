#include <fcntl.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char *const argv[]) {
	char * myfifo = "myfifo";
  	mkfifo(myfifo, 0666);
  	int fd = open(myfifo, O_RDONLY);
	long  length;
	read(fd, &length, sizeof(long));
	char * arr1 = malloc(length+1);
	read(fd, arr1, length);
	printf("%s", arr1);
	return 0;
}
