#include <stdio.h>
#include <pthread.h>

#define N 100
int n = 100;
pthread_rwlock_t rwl = PTHREAD_RWLOCK_INITIALIZER;

void* check(void* a) {
    pthread_rwlock_rdlock(&rwl);
    if(n > 0) {
        printf("There are free seats\n");
    }
    else {
        printf("Sold out\n");
    }
    pthread_rwlock_unlock(&rwl);
    return NULL;
}
void* purchase(void* a) {
    pthread_rwlock_wrlock(&rwl);
    if(n > 0) {
        n--;
        printf("Sold seat %d\n", n+1);
    }
    pthread_rwlock_unlock(&rwl);
    return NULL;
}
int main(int argc, char** argv) {
    pthread_t t[N];
    int i;
    for(i=0; i<N; i++) {
        if(i < N/10) {
            pthread_create(&t[i], NULL, purchase, NULL);
        }
        else {
            pthread_create(&t[i], NULL, check, NULL);
        }
    }
    for(i=0; i<N; i++) {
        pthread_join(t[i], NULL);
    }
    return 0;
}
