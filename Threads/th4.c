//program 7 threads, global vars: 2digits and 3digits
//each thread generates 3 random numbers between 50 and 155
//increment globals
//main thread prints out global vars

#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <unistd.h>
#include <time.h>

pthread_mutex_t mutex= PTHREAD_MUTEX_INITIALIZER;
int 3digits, 2digits;


void* myThread(void *param){
    srand(time(NULL));
    int local_3digits=0, local_2digits=0,n,i;
    for(i=0;i<3;i++){
        n=rand();
        n=n%106+50;
        if(n>99)
            local_3digits++;
        else
            local_2digits++;
    }
    pthread_mutex_lock(&mutex);
    3digits+=local_3digits;
    2digits+=local_2digits;
    pthread_mutex_unlock(&mutex);
    return NULL;
}

int main(int argc, char** argv){
    pthread_t th[7];
    int i;
    for(i=0;i<7;i++)
        pthread_create(&th[i],NULL,myThread,&i);
    for(i=0;i<7;i++)
        pthread_join(th[i], NULL);
        
    printf("two digits numbers:%d\nthree digit numbers:%d\n", 2digits, 3digits);
    pthread_mutex_destroy(&mutex);
    return 0;
}