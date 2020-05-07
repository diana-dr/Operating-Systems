#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/shm.h>
#include <stdio.h>
#define SHMSZ     27
int main(int argc, char** argv)
{
    int shmid;
    key_t key;
    char *shm, *s;
    int res = 0;

    /*
     * We need to get the segment named
     * "5678", created by the server.
     */
    key = 5678;

    /*
     * Locate the segment.
     */
    if ((shmid = shmget(key, SHMSZ, 0666)) < 0) {
        perror("shmget");
        exit(1);
    }

    /*
     * Now we attach the segment to our data space.
     */
    if ((shm = shmat(shmid, NULL, 0)) == (char *) -1) {
        perror("shmat");
        exit(1);
    }

    /*
     * Now read what the server put in the memory.
     */
    for (s = shm; *s != NULL; s++)
    {
	if (strcmp(*s, "a") == 0 || strcmp(*s, "e") == 0 || strcmp(*s, "i") == 		0 || strcmp(*s, "o") == 0 || strcmp(*s, "u") == 0)
		res++;
    }
    printf("%d", res);
    putchar("\n");

    /*
     * Finally, change the first character of the 
     * segment to '*', indicating we have read 
     * the segment.
     */
    *shm = '*';

    exit(0);

	
	return 0;
}
