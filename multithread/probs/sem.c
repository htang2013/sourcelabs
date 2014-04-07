#include<stdio.h>
#include<unistd.h>
#include<stdlib.h>
#include<string.h>
#include<pthread.h>
#include<semaphore.h>

sem_t binSem;
char buffer[1024];

void *thread_func(void *arg){
     printf("Thread: Wait......");
     sem_wait(&binSem); // keep waiting again
     printf("Thread: Exit.");
     pthread_exit(EXIT_SUCCESS);
}



int main(void){
    
    int result;
    pthread_t myThread;
    void *thread_result;

    // init semaphor
    result  = sem_init(&binSem, 0,1);
    if(result != 0){
        perror("Cant init semaphore");
        exit(EXIT_FAILURE);
    }
    // start thread
    result = pthread_create(&myThread, NULL, thread_func, NULL);

    if(result != 0){
        perror("Thread execution failed");
        exit(EXIT_FAILURE);
    }

    printf("Thread created successfully.\n");
    getchar();

    sem_post(&binSem);
    printf("sem post is done\n");
    getchar();


    result= pthread_join(myThread, &thread_result);
    if(result != 0){
        perror("Thread join failed");
        exit(EXIT_FAILURE);
    }

    printf("Thread joined. Terminating now.\n");

    exit(EXIT_SUCCESS);
}

