#include <stdio.h>
#include <pthread.h>

int counter=0;
pthread_mutex_t lock;
void *increment(void *arg) {
    for(int i=0;i<100000;i++){
        pthread_mutex_lock(&lock);
        counter++;
        pthread_mutex_unlock(&lock);
    }
    return NULL;
}
int main(void) {
    pthread_t a,b;
    pthread_mutex_init(&lock,NULL);
    pthread_create(&a,NULL,increment,NULL);
    pthread_create(&b,NULL,increment,NULL);
    pthread_join(a,NULL); pthread_join(b,NULL);
    pthread_mutex_destroy(&lock);
    printf("Final counter value: %d\n",counter);
    return 0;
}
