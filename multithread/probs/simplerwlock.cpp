#include<unistd.h>
#include<pthread.h>
#include<stdlib.h>
#include<iostream>

using namespace std;
 
class RwLock
{
    //nreaders = 0 , indicates no. reader/writer exists.
    //nreaders > 0, indicates one or more read lock exists.
    //nreaders=-1, indicates a write lock exists.
    int nreaders;
    
    pthread_mutex_t rw_mutex;
    pthread_cond_t rw_cond;
    public:
    RwLock();
    void getReadLock();
    void getWriteLock();
    void unLock();
    void unrLock();
    void unwLock();
    ~RwLock();
};

RwLock :: RwLock()
{
    nreaders = 0;
    // Initialize mutex and condition variable.
    pthread_mutex_init(&rw_mutex, NULL);    
    pthread_cond_init(&rw_cond, NULL);
}

void RwLock :: getReadLock()
{
    //Obtain Lock.
    pthread_mutex_lock(&rw_mutex);
    // If  a WRITER exists(nreaders = -1)wait for signal from writer.
    while(-1 == nreaders)
    {
        pthread_cond_wait(&rw_cond, &rw_mutex);
    }
    // Increment no. of reader
    nreaders++;
    //Unlock the mutex. 
    pthread_mutex_unlock(&rw_mutex);        
}

void RwLock :: getWriteLock()
{
    //Obtain Lock
    pthread_mutex_lock(&rw_mutex);
    // If nreader is != 0 it means either a reader or writer is present. wait for signal from reader/writer (do it in a loop)
    while(nreaders != 0)
    {
        pthread_cond_wait(&rw_cond, &rw_mutex);
    }
    // Set nreader = -1 indicating a writer is present.
    nreaders = -1;
    // Unlock the mutex.
    pthread_mutex_unlock(&rw_mutex);
}

void RwLock::unrLock()
{
    pthread_mutex_lock(&rw_mutex);
    if (nreaders > 0 )
       nreaders --;
    if (nreaders == 0)
       pthread_cond_broadcast(&rw_cond);
    pthread_mutex_unlock(&rw_mutex);
}

void RwLock::unwLock()
{
    pthread_mutex_lock(&rw_mutex);
    if ( nreaders == -1) {
        nreaders = 0;
        pthread_cond_broadcast(&rw_cond);
    } 
    pthread_mutex_unlock(&rw_mutex);
}

void RwLock :: unLock()
{
    // Obtain Lock.
    pthread_mutex_lock(&rw_mutex);
    if(nreaders > 0)
    {
        // One of the readers is done. decrement readers count.
        nreaders--;
        if(nreaders == 0)
        {
            // Last reader is done.
            pthread_cond_broadcast(&rw_cond);
        }
    }
    else if(nreaders == -1)
    {
        // A writer is done. set nreaders to 0 indicating no reader/writer exists.
        nreaders = 0;
        pthread_cond_broadcast(&rw_cond);
    }
    // Unlock the mutex. 
    pthread_mutex_unlock(&rw_mutex);
}

RwLock :: ~RwLock()
{
    // Destroy condition variable and mutex.
    pthread_mutex_destroy(&rw_mutex);
    pthread_cond_destroy(&rw_cond);
}

RwLock rwlock;

void* reader(void* arg)
{
    cout << "Obtaining read lock." << endl;
    rwlock.getReadLock();
    
    cout << "Obtained read lock." << endl;
    sleep(5);
    cout << "Releasing read lock." << endl;
    rwlock.unrLock();
    cout << "Released read lock." << endl;    
}

void* writer(void* arg)
{
    cout << "Obtaining write lock." << endl;
    rwlock.getWriteLock();
    
    cout << "Obtained write lock." << endl;
    sleep(4);
    cout << "Releasing write lock." << endl;
    rwlock.unwLock();
    cout << "Released write lock." << endl;    
}

int main(int argc, char** argv)
{
    pthread_t r1,r2,r3,w1,w2;
    int res;
    cout << endl;    
    res = pthread_create(&r1, NULL, reader, NULL);
    if(0 != res)
    {
        cout << "Failed to start thread." << endl;
        exit(1);
    }
            
    res = pthread_create(&r2, NULL, reader, NULL);
    if(0 != res)
    {
        cout << "Failed to start thread." << endl;
        exit(1);
    }            
    sleep(1);
    res = pthread_create(&w1, NULL, writer, NULL);
    if(0 != res)
    {
        cout << "Failed to start thread." << endl;
        exit(1);
    }    
    res = pthread_create(&w2, NULL, writer, NULL);
    if(0 != res)
    {
        cout << "Failed to start thread." << endl;
        exit(1);
    }    
    pthread_exit(NULL);        
}
