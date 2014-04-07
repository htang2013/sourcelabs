#include<unistd.h>
#include<pthread.h>
#include<stdlib.h>
#include<stdio.h>

struct RwLock
{
    //nreaders = 0 , indicates no. reader/writer exists.
    //nreaders > 0, indicates one or more read lock exists.
    //nreaders=-1, indicates a write lock exists.
    int nreaders;
    
    pthread_mutex_t rw_mutex;
    pthread_cond_t rw_cond;
};

void initRwLock(struct RwLock *rwp)
{
    
    rwp->nreaders = 0;
    // Initialize mutex and condition variable.
    pthread_mutex_init(&rwp->rw_mutex, NULL);    
    pthread_cond_init(&rwp->rw_cond, NULL);
}
void getReadLock(struct RwLock *rwp)
{
    //Obtain Lock.
    pthread_mutex_lock(&rwp->rw_mutex);
    // If  a WRITER exists(nreaders = -1)wait for signal from writer.
    while(-1 == rwp->nreaders)
    {
        pthread_cond_wait(&rwp->rw_cond, &rwp->rw_mutex);
    }
    // Increment no. of reader
    rwp->nreaders++;
    //Unlock the mutex. 
    pthread_mutex_unlock(&rwp->rw_mutex);        
}
void getWriteLock(struct RwLock *rwp)
{
    //Obtain Lock
    pthread_mutex_lock(&rwp->rw_mutex);
    // If nreader is != 0 it means either a reader or writer is present. wait for signal from reader/writer (do it in a loop)
    while(0 != rwp->nreaders)
    {
        pthread_cond_wait(&rwp->rw_cond, &rwp->rw_mutex);
    }
    // Set nreader = -1 indicating a writer is present.
    rwp->nreaders = -1;
    // Unlock the mutex.
    pthread_mutex_unlock(&rwp->rw_mutex);
}
void unLock(struct RwLock *rwp)
{
    // Obtain Lock.
    pthread_mutex_lock(&rwp->rw_mutex);
    if( rwp->nreaders > 0)
    {
        // One of the readers is done. decrement readers count.
        rwp->nreaders--;
        if(rwp->nreaders == 0)
        {
            // Last reader is done.
            pthread_cond_broadcast(&rwp->rw_cond);
        }
    }
    else if(rwp->nreaders == -1)
    {
        // A writer is done. set nreaders to 0 indicating no reader/writer exists.
        rwp->nreaders = 0;
        pthread_cond_broadcast(&rwp->rw_cond);
    }
    // Unlock the mutex. 
    pthread_mutex_unlock(&rwp->rw_mutex);
}
void destroyRwLock(struct RwLock *rwp)
{
    // Destroy condition variable and mutex.
    pthread_mutex_destroy(&rwp->rw_mutex);
    pthread_cond_destroy(&rwp->rw_cond);
}

struct RwLock rwlock;

void* reader(void* arg)
{
    printf("Obtaining read lock.\n");
    getReadLock(&rwlock);
    
    printf("Obtained read lock.\n");
    sleep(5);

    printf("Releasing read lock.\n");
    unLock(&rwlock);
    printf("Released read lock.\n");
}

void* writer(void* arg)
{
    printf("Obtaining write lock.\n");
    getWriteLock(&rwlock);
    
    printf("Obtained write lock.\n");
    sleep(4);
    printf("Releasing write lock.\n");
    unLock(&rwlock);
    printf("Released write lock.\n");
}
int main(int argc, char** argv)
{
    pthread_t r1,r2,r3,w1,w2;
    int res;
    res = pthread_create(&r1, NULL, reader, NULL);
    if(0 != res)
    {
        printf("Failed to start thread.\n");
        exit(1);
    }
            
    res = pthread_create(&r2, NULL, reader, NULL);
    if(0 != res)
    {
        printf("Failed to start thread.\n");
        exit(1);
    }            
    sleep(1);
    res = pthread_create(&w1, NULL, writer, NULL);
    if(0 != res)
    {
        printf("Failed to start thread.\n");
        exit(1);
    }    
    res = pthread_create(&w2, NULL, writer, NULL);
    if(0 != res)
    {
        printf("Failed to start thread.\n");
        exit(1);
    }    
    pthread_exit(NULL);        
}
