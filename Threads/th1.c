//random string command line. each string->thread counts vowels and digits.
//two global variables vowels and digits.
//prints global var.

#include <stdio.h>
#include <string.h>
#include <pthread.h>
#include <unistd.h>

pthread_mutex_t mutex= PTHREAD_MUTEX_INITIALIZER;
int global_vowels, global_digits;

void*t1 (void*param){
    int local_vowels=0, local_digits=0, i;
    char *argument=*((char**)param);
    printf("%s\n", argument);
    
    for(i=0; i<strlen(argument); i++){
        if (strchr("aeiouAEIOU", argument[i]) !=NULL)
            local_vowels+=1;
        if (strchr("0123456789", argument[i]) !=NUll)
            local_digits+=1;
    }
    pthread_mutex_lock(&mutex);
    
    global_vowels+=local_vowels;
    global_digits+=local_digits;
    
    pthread_mutex_unlock(&mutex);
}
int main(int argc,char*argv[]){
    pthread_t thr[argc-1];
    int i;
    
    for(i=0;i<argc-1;i++)
        printf("%s\n", argv[i+1]);
    
    for(i=0;i<argc-1;i++){
        pthread_create(&thr[i],NULL,t1,&argv[i+1]);
    }
    
    for (i=0;i<argc-1;i++){
        pthread_join(thr[i], NULL);
    }
    
    printf("vowels:%d\ndigits:%d\n", global_vowels,global_digits);
    pthread_mutex_destroy(&mutex);
    return 0;
}