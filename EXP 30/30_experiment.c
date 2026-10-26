#include <stdio.h>
#include <pthread.h>
void*work(void*x){printf("Thread running.\n");pthread_exit((void*)42);}
int main(void){pthread_t t;void*r;pthread_create(&t,NULL,work,NULL);printf("pthread_equal(self,self): %s\n",pthread_equal(pthread_self(),pthread_self())?"true":"false");pthread_join(t,&r);printf("Thread joined; exit value=%ld\n",(long)r);return 0;}
