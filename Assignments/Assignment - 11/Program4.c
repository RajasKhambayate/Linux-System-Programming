//This program is used to creates two thread and uses appropriate synchronization technique to avoid sheduling problem .
//Usage : "./Executable_Name"
#include<stdio.h>
#include<pthread.h>

struct DataTransfer
{
    pthread_mutex_t lock;
}DT;

void * ThreadProc1(void *ptr)
{
    pthread_mutex_lock(&DT.lock);
    int iCnt = 0;

    printf("First Thread Starts\n");

    while(iCnt <= 100)
    {
        printf("First Thread -> iCnt : %d\n",iCnt);
        iCnt++;
    }

    printf("First Thread Ends\n\n\n");

    pthread_mutex_unlock(&DT.lock);
}

void * ThreadProc2(void *ptr)
{
    pthread_mutex_lock(&DT.lock);
    int iCnt = 0;

    printf("Second Thread Starts\n");

    while(iCnt <= 100)
    {
        printf("Second Thread -> iCnt : %d\n",iCnt);
        iCnt++;
    }

    printf("Second Thread Ends\n\n\n");

    pthread_mutex_unlock(&DT.lock);
}

int main()
{
    pthread_t Thread_ID1 = 0;
    pthread_t Thread_ID2 = 0;

    int iMutexRet1 = 0;

    int iCreateRet1 = 0;
    int iCreateRet2 = 0;


    iMutexRet1 = pthread_mutex_init(&DT.lock,NULL);
    if(iMutexRet1 != 0)
    {
        printf("Mutex init Failed\n");
        return -1;
    }

    iCreateRet1 = pthread_create(&Thread_ID1 , NULL , ThreadProc1 , NULL);
    iCreateRet2 = pthread_create(&Thread_ID2 , NULL , ThreadProc2 , NULL);

/*
    This Program creates two thread
    which prints number from 1 to 100
    in synchronized format where they
    try to execute after each other
    at schedule time
*/

    if((iCreateRet1 != 0) && (iCreateRet2 != 0))
    {
        printf("Unable to create threads\n");
        return -1;
    }

    pthread_join(Thread_ID1,NULL);
    pthread_join(Thread_ID2,NULL);

    return 0;
}