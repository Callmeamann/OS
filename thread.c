// program in C to create thread

#include<stdio.h>
#include<pthread.h> 
#include<unistd.h>  
#include<stdlib.h>

void* thread_f();
int i,j;

int main(){
    pthread_t thread_a;
    pthread_create(&thread_a,NULL,thread_f,NULL);
    pthread_join(thread_a,NULL); // Wait for thread_a to finish
    // If we don't use pthread_join(), both the threads will run concurrently using Context Switching
    // Content inside main thread
    printf("Inside main thread\n");
    for(j=20 ; j<=25 ; ++j){
        printf("j = %d\n",j);
        sleep(1);
    }
}

void* thread_f(){
    // Content inside thread
    printf("Inside thread\n");
    for(i=0 ; i<=5 ; ++i){
        printf("i = %d\n",i);
        sleep(1);
    }
}