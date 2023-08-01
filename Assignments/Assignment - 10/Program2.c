//This program is used to create two threads , first thread will print no from 1 to 500 and second thread will print no from 500 to 1 .
//Usage : "./Executable_Name"
#include<stdio.h>
#include<pthread.h>

void * ThreadProc1(void *ptr)
{
    int i1 = 0;
    while(i1 <= 500)
    {
        printf("First Thread with i1 = %d\n",i1);
        i1++;
    }
}

void * ThreadProc2(void *ptr)
{
    int i2 = 500;
    while(i2 > 0)
    {
        printf("Second Thread with i2 = %d\n",i2);
        i2--;
    }
}

int main()
{
    pthread_t Thread_ID1 = 0;
    pthread_t Thread_ID2 = 0;

    int iRet1 = 0;
    int iRet2 = 0;

    iRet1 = pthread_create(&Thread_ID1 , NULL , ThreadProc1 , NULL);
    iRet2 = pthread_create(&Thread_ID2 , NULL , ThreadProc2 , NULL);

    if(iRet1 != 0)
    {
        printf("Unable to create thread\n");
        return -1;
    }
    else
    {
        printf("First thread is created with ID : %lu\n",Thread_ID1);
    }

    if(iRet2 != 0)
    {
        printf("Unable to create thread\n");
        return -1;
    }
    else
    {
        printf("Second thread is created with ID : %lu\n",Thread_ID2);
    }

    pthread_join(Thread_ID1,NULL);
    pthread_join(Thread_ID2,NULL);

    return 0;
}