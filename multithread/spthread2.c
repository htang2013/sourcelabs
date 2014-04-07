#include <stdio.h>
#include <pthread.h>

int tally = 0;

void ThreadProc(void *arguments)
{
    int i;
    for ( i = 1; i<=50; i++)
    {
          tally += 1;
          printf("total update: %d\n", tally);
    }
    
    pthread_exit(NULL);
}

int main()
{
    pthread_t some_thread1, some_thread2;

    if (pthread_create(&some_thread1,  NULL, (void *)ThreadProc, NULL) != 0) {
    	printf("Uh-oh!\n");
    	return -1;
    }

    if (pthread_create(&some_thread2,  NULL, (void *)ThreadProc, NULL) != 0) {
    	printf("Uh-oh!\n");
    	return -1;
    }

    pthread_join(some_thread1, NULL);
    pthread_join(some_thread2, NULL); /* Wait until thread is finished */
    printf("The total is: %d\n", tally);
    return 0;
}
