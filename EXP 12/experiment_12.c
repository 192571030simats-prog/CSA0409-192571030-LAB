#include <stdio.h>
#include <pthread.h>
#include <unistd.h>

#define N 5
pthread_mutex_t fork_lock[N];
void *philosopher(void *arg) {
    int id = *(int *)arg;
    int left=id, right=(id+1)%N;
    int first = left < right ? left : right;
    int second = left < right ? right : left;
    printf("Philosopher %d is thinking.\n", id+1);
    pthread_mutex_lock(&fork_lock[first]);
    pthread_mutex_lock(&fork_lock[second]);
    printf("Philosopher %d is eating.\n", id+1);
    usleep(100000);
    pthread_mutex_unlock(&fork_lock[second]);
    pthread_mutex_unlock(&fork_lock[first]);
    return NULL;
}
int main(void) {
    pthread_t t[N]; int id[N], i;
    for(i=0;i<N;i++) pthread_mutex_init(&fork_lock[i],NULL);
    for(i=0;i<N;i++){id[i]=i;pthread_create(&t[i],NULL,philosopher,&id[i]);}
    for(i=0;i<N;i++) pthread_join(t[i],NULL);
    for(i=0;i<N;i++) pthread_mutex_destroy(&fork_lock[i]);
    return 0;
}
