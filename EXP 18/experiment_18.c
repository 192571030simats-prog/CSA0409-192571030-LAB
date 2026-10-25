#include <stdio.h>
#include <pthread.h>
#include <semaphore.h>

#define N 5
sem_t empty, full, mutex;
int buffer[N], in=0, out=0;
void *producer(void *arg) {
    for(int item=1; item<=5; item++){
        sem_wait(&empty); sem_wait(&mutex);
        buffer[in]=item; in=(in+1)%N;
        printf("Produced: %d\n",item);
        sem_post(&mutex); sem_post(&full);
    }
    return NULL;
}
void *consumer(void *arg) {
    for(int i=0;i<5;i++){
        sem_wait(&full); sem_wait(&mutex);
        int item=buffer[out]; out=(out+1)%N;
        printf("Consumed: %d\n",item);
        sem_post(&mutex); sem_post(&empty);
    }
    return NULL;
}
int main(void) {
    pthread_t p,c;
    sem_init(&empty,0,N); sem_init(&full,0,0); sem_init(&mutex,0,1);
    pthread_create(&p,NULL,producer,NULL); pthread_create(&c,NULL,consumer,NULL);
    pthread_join(p,NULL); pthread_join(c,NULL);
    sem_destroy(&empty); sem_destroy(&full); sem_destroy(&mutex);
    return 0;
}
