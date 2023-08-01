//This program is used predict problem due to lack of synchroniztion .
//Usage : "./Executable_Name"
#include<stdio.h>
#include<pthread.h>

void * ThreadProc1(void *ptr)
{
    int iCnt = 0;

    printf("First Thread Starts\n\n\n");

    while(iCnt <= 100)
    {
        printf("First Thread -> iCnt : %d\n",iCnt);
        iCnt++;
    }

    printf("First Thread Ends\n\n\n");
}

void * ThreadProc2(void *ptr)
{
    int iCnt = 0;

    printf("Second Thread Starts\n\n\n");

    while(iCnt <= 100)
    {
        printf("Second Thread -> iCnt : %d\n",iCnt);
        iCnt++;
    }

    printf("Second Thread Ends\n\n\n");
}

int main()
{
    pthread_t Thread_ID1 = 0;
    pthread_t Thread_ID2 = 0;

    int iCreateRet1 = 0;
    int iCreateRet2 = 0;

    iCreateRet1 = pthread_create(&Thread_ID1 , NULL , ThreadProc1 , NULL);
    iCreateRet2 = pthread_create(&Thread_ID2 , NULL , ThreadProc2 , NULL);

/*
    This Program creates two thread
    which prints number from 1 to 100
    in unsynchronized format where they
    try to execute simultaneously
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