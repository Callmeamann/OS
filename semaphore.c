// Syncronisation using semaphores

#include<stdio.h>
#include<pthread.h>
#include<semaphore.h>
#include<unistd.h>

void* fun1();
void* fun2();

int shared = 1;
sem_t s;

int main(){
    sem_init(&s,0,1);
    // 0 -> semaphore is shared between threads
    // 1 -> initial value of semaphore

    pthread_t t1,t2; // Thread  identifiers created
    pthread_create(&t1,NULL,fun1,NULL);
    pthread_create(&t2,NULL,fun2,NULL); 
    // arguements: thread, attributes, function, arguements to function

    pthread_join(t1,NULL);
    pthread_join(t2,NULL);

    printf("Final value of shared variable : %d\n",shared);
}

void* fun1(){
    int x;
    sem_wait(&s); // Waits on the semaphore. If the semaphore's value is positive, it decrements the value; otherwise, it blocks.
    // Indicating that the critical section is being entered.
    x = shared;
    printf("Thread1 reads the value of shared variable as : %d\n",x);
    x++;
    printf("Local updation done by thread1 : %d\n",x);
    sleep(1); //preempts thread1 by thread2
    shared = x; // Shared variable updation
    printf("Value of Shared variable updated by thread1 : %d\n",shared);
    sem_post(&s); //Increments the semaphore value, indicating that the critical section is released.
}

void* fun2(){
    int y;
    sem_wait(&s);
    y = shared;
    printf("Thread2 reads the value of shared variable as : %d\n",y);
    y--;
    printf("Local updation done by thread2 : %d\n",y);
    sleep(1); //preempts thread2 by thread1
    shared = y;
    printf("Value of Shared variable updated by thread2 : %d\n", shared);
    sem_post(&s);
}

/*
Semaphore Functions:
sem_init(&s, 0, 1);: Initializes a semaphore. The third argument (1 in this case) is the initial value of the semaphore.
sem_wait(&s);: Decrements the value of the semaphore. If the value is already zero, it blocks until the value becomes positive.
sem_post(&s);: Increments the value of the semaphore, signaling that the critical section is released.
Explanation of the Code's Purpose:
The program demonstrates two threads (fun1 and fun2) that read, update, and print the shared variable in a synchronized 
manner using semaphores. The use of semaphores ensures that only one thread can access the critical section (updating shared)
 at a time, preventing race conditions and ensuring proper synchronization between threads. The sleep calls simulate
 the potential for preemption and context-switching between threads. The final value of the shared variable is printed
 after both threads have completed their execution.
*/