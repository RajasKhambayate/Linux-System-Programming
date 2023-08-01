//This program is used to create 4 threads and our main method thread waits till all the thread terminates .
//Usage : "./Executable_Name"
#include<stdio.h>
#include<pthread.h>

void * ThreadProc1(void *ptr)
{
    printf("Inside Thread No : 1\n");
}

void * ThreadProc2(void *ptr)
{
    printf("Inside Thread No : 2\n");
}

void * ThreadProc3(void *ptr)
{
    printf("Inside Thread No : 3\n");
}

void * ThreadProc4(void *ptr)
{
    printf("Inside Thread No : 4\n");
}


int main()
{
    pthread_t Thread_ID1 = 0;
    pthread_t Thread_ID2 = 0;
    pthread_t Thread_ID3 = 0;
    pthread_t Thread_ID4 = 0;

    int iRet1 = 0;
    int iRet2 = 0;
    int iRet3 = 0;
    int iRet4 = 0;

    iRet1 = pthread_create(&Thread_ID1 , NULL , ThreadProc1 , NULL);
    iRet2 = pthread_create(&Thread_ID2 , NULL , ThreadProc2 , NULL);
    iRet3 = pthread_create(&Thread_ID3 , NULL , ThreadProc3 , NULL);
    iRet4 = pthread_create(&Thread_ID4 , NULL , ThreadProc4 , NULL);

    if((iRet1 != 0) && (iRet2 != 0) && (iRet3 != 0) && (iRet4 != 0))
    {
        printf("Unable to create thread\n");
        return -1;
    }

    pthread_join(Thread_ID1,NULL);
    pthread_join(Thread_ID2,NULL);
    pthread_join(Thread_ID3,NULL);
    pthread_join(Thread_ID4,NULL);

    printf("Main thread terminated successfully\n");

    return 0;
}