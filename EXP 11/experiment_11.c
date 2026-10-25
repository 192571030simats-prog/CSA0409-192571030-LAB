#include <stdio.h>
#include <pthread.h>

void *work(void *arg) {
    printf("Hello from thread %d\n", *(int *)arg);
    return NULL;
}
int main(void) {
    pthread_t t1, t2;
    int a=1, b=2;
    pthread_create(&t1, NULL, work, &a);
    pthread_create(&t2, NULL, work, &b);
    pthread_join(t1, NULL);
    pthread_join(t2, NULL);
    printf("Main thread finished.\n");
    return 0;
}
