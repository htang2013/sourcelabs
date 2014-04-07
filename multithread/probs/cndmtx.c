#include <stdio.h>
#include <pthread.h>

pthread_mutex_t count_lock = PTHREAD_MUTEX_INITIALIZER;
pthread_cond_t count_nonzero = PTHREAD_COND_INITIALIZER;
unsigned count = 4;

void *decrement_count(void *arg)
{
    while(1) {
        pthread_mutex_lock(&count_lock);
        printf("desc locked\n");    
        while (count == 0){
            printf("desc cond wait\n");
            pthread_cond_wait(&count_nonzero, &count_lock);
        }
        sleep(1);
        count = count - 1;
        printf("desc unlock %d \n", count); 
        pthread_mutex_unlock(&count_lock);
    }
}

void *increment_count(void *arg)
{
    while(1) {
        sleep(1);
        pthread_mutex_lock(&count_lock);
        printf("inc locked\n");
        if (count == 0) {
            printf("inc cond signal\n");
            pthread_cond_signal(&count_nonzero);
        } 
        count = count + 1;
        printf("inc unlock %d \n", count);
        pthread_mutex_unlock(&count_lock);
    }
}


pthread_t threadid[2];

int main( void )
{
    pthread_create( &threadid[0], NULL, &increment_count, NULL );
    pthread_create( &threadid[1], NULL, &decrement_count, NULL );

    /* Let the threads run for 60 seconds. */
    sleep( 10 );
    pthread_join(threadid[0], NULL);
    pthread_join(threadid[1], NULL);
    pthread_mutex_destroy(&count_lock);
    pthread_cond_destroy(&count_nonzero);

    printf("Main program completed\n");
    return 0;
}

