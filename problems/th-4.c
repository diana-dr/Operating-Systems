#include <stdlib.h>
#include <stdio.h>
#include <pthread.h>
void* f(void* a) {
    printf("%d\n", *(int*)a);
    free(a);
    return NULL;
}
int main(int argc, char** argv) {
    pthread_t t[100];
    int i;
    int* a;
    for(i=0; i<100; i++) {
        a = (int*)malloc(sizeof(int));
        *a = i;
        pthread_create(&t[i], NULL, f, a);
    }
    for(i=0; i<100; i++) {
        pthread_join(t[i], NULL);
    }
    return 0;
}
