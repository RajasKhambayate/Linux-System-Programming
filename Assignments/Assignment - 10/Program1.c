//This program is used to create simple thread by using pthread library
//Usage : "./Executable_Name"
#include<stdio.h>
#include<pthread.h>

void * ThreadProc(void *ptr)
{
    printf("Inside Thread callback function\n");
}

int main()
{
    pthread_t Thread_ID = 0;
    int iRet = 0;

    iRet = pthread_create(&Thread_ID , NULL , ThreadProc , NULL);

    if(iRet != 0)
    {
        printf("Unable to create thread\n");
        return -1;
    }
    else
    {
        printf("Thread is created with ID : %lu\n",Thread_ID);
    }

    return 0;
}