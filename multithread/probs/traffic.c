#include<pthread.h>
#include<stdio.h>
#include<semaphore.h>


sem_t gSema;


void *traffic1(void *arg){
    while(1) {
        printf("Traffic 1: Wait...\n");
        sem_wait(&gSema);
        printf("......Traffic 1: Passing...\n");
        sleep(3);
        printf("Traffic 1: End ...\n");
        sem_post(&gSema);
        sleep(1);
    }
}


void *traffic2(void *arg){
    while(1) {
        printf("Traffic 2: Wait...\n");
        sem_wait(&gSema);
        printf("......Traffic 2: Passing...\n");
        sleep(2);
        printf("Traffic 2: End ...\n");
        sem_post(&gSema);
        sleep(1);
    }
}

void *traffic3(void *arg){
    while(1) {
        printf("Traffic 3: Wait...\n");
        sem_wait(&gSema);
        printf("......Traffic 3: Passing...\n");
        sleep(1);
        printf("Traffic 3: End ...\n");
        sem_post(&gSema);
        sleep(1);
    }
}

int main(void)
{
    pthread_t mythread1, mythread2, mythread3;
    void *thread_result;

    sem_init(&gSema, 0, 2);
    pthread_create(&mythread1, NULL, traffic1, NULL);
    pthread_create(&mythread2, NULL, traffic2, NULL);
    pthread_create(&mythread3, NULL, traffic3, NULL);

    getchar();
    
    pthread_join(mythread1, &thread_result);
    pthread_join(mythread2, &thread_result);
    pthread_join(mythread3, &thread_result);

    return 1;
}

