#include <stdio.h>
#include <pthread.h>
#include <semaphore.h>
sem_t empty,full,mutex;int item=0;
void*producer(void*x){for(int i=1;i<=3;i++){sem_wait(&empty);sem_wait(&mutex);item=i;printf("Produced: %d\n",item);sem_post(&mutex);sem_post(&full);}return NULL;}
void*consumer(void*x){for(int i=1;i<=3;i++){sem_wait(&full);sem_wait(&mutex);printf("Consumed: %d\n",item);sem_post(&mutex);sem_post(&empty);}return NULL;}
int main(void){pthread_t p,c;sem_init(&empty,0,1);sem_init(&full,0,0);sem_init(&mutex,0,1);pthread_create(&p,0,producer,0);pthread_create(&c,0,consumer,0);pthread_join(p,0);pthread_join(c,0);sem_destroy(&empty);sem_destroy(&full);sem_destroy(&mutex);return 0;}
