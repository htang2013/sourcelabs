#include<pthread.h>

typedef struct {
    pthread_mutex_t m; /* monitor lock */
    int rwlock;        /* >=0 # readers, <0 =wrtr, 0=none */
    pthread_cond_t readers_ok;  /* start waiting readers  */
    unsigned int waiting_writers;   /*  number of writers */
    pthread_cond_t writers_ok;     /* start waiting writer */
} rwl_t;

void rwl_init( rwl_t *rwlp)
{
      pthread_mutex_init(&rwlp->m, NULL);
      pthread_cond_init(&rwlp->readers_ok, NULL);
      pthread_cond_init(&rwlp->writers_ok, NULL);
      rwlp->rwlock = 0;
      rwlp->waiting_writers = 0;
}

void rwl_rdlock( rwl_t *rwlp)
{
     pthread_mutex_lock(&rwlp->m);
     while(rwlp->rwlock < 0 || rwlp->waiting_writers)
         pthread_cond_wait(&rwlp->readers_ok, &rwlp->m); 
     rwlp -> rwlock ++;
     pthread_mutex_unlock(&rwlp->m);
}

void rwl_wrlock( rwl_t *rwlp)
{
     pthread_mutex_lock(&rwlp -> m);
     while(rwlp->rwlock != 0) {
         rwlp -> waiting_writers ++;
         pthread_cond_wait(&rwlp->writers_ok, &rwlp->m);
         rwlp -> waiting_writers --;
     } 
     rwlp->rwlock = -1;
     pthread_mutex_unlock(&rwlp->m);
}
