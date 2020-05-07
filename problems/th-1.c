#include <stdio.h>
#include <pthread.h>

int n = 0;
pthread_mutex_t mtx;

void* f(void* a) {
    int i;
    for(i=0; i<10000; i++) {
        pthread_mutex_lock(&mtx);
        n++;
        pthread_mutex_unlock(&mtx);
    }
    return NULL;
}
int main(int argc, char** argv) {
    pthread_t t[100];
    int i;
    pthread_mutex_init(&mtx, NULL);
    for(i=0; i<100; i++) {
        pthread_create(&t[i], NULL, f, NULL);
    }
    for(i=0; i<100; i++) {
        pthread_join(t[i], NULL);
    }
    pthread_mutex_destroy(&mtx);
    printf("%d\n", n);
    return 0;
}
