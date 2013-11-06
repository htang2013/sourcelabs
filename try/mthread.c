#include<pthread.h>
#include<stdio.h>

pthread_mutex_t mutex = PTHREAD_MUTEX_INITIALIZER;
pthread_cond_t cond = PTHREAD_COND_INITIALIZER;

int gCount = 0;


void *threadA(void *arg)
{
   while(1) {
      pthread_mutex_lock(&mutex);
      printf("thread A count is %d\n", gCount);
      if (gCount == 0) { 
           pthread_cond_wait(&cond, &mutex);
      }
      gCount --;
      pthread_mutex_unlock(&mutex);
   }
}

void *threadB(void *arg)
{
   while(1) {
       pthread_mutex_lock(&mutex);
       gCount ++; 
       printf("thread B count is %d\n", gCount);
       sleep(1);
       pthread_cond_signal(&cond); 
       pthread_mutex_unlock(&mutex);
   }
}

int main(void)
{
   pthread_t ta, tb;
   pthread_create(&ta,NULL, threadA, (void *)NULL);
   pthread_create(&tb,NULL, threadB, (void *)NULL);
   pthread_join(ta,NULL);
   pthread_join(tb,NULL);
   pthread_mutex_destroy(&mutex);
   pthread_cond_destroy(&cond);
   return 1;
}
    
