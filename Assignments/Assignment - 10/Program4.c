//This program is used to create single thread and it accept one value from user and it return some value to the caller thread .
//Usage : "./Executable_Name"
#include<stdio.h>
#include<pthread.h>

struct DataTransfer
{
    int iRet;
}DT;

void * ThreadProc(void *ptr)
{
    int *iValue = (int *)ptr;

    printf("Paramter from main thread : %d\n",*iValue);

    DT.iRet = 21;
}

int main()
{
    pthread_t Thread_ID = 0;

    int iRet = 0;
    int iNo = 11;

    int *parameter = &iNo;

    iRet = pthread_create(&Thread_ID , NULL , ThreadProc , (int *)parameter);

    if(iRet != 0)
    {
        printf("Unable to create thread\n");
        return -1;
    }
    else
    {
        printf("Thread is created with ID : %lu\n",Thread_ID);
    }

    pthread_join(Thread_ID,NULL);

    printf("Data from thread function is : %d\n",DT.iRet);

    return 0;
}