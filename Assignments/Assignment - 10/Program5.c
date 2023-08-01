//This program is used to get thread id from inside its thread function .
//Usage : "./Executable_Name"
#include<stdio.h>
#include<pthread.h>

void * ThreadProc(void *ptr)
{
    pthread_t *Thread_id = (pthread_t *)ptr;

    printf("From thread method -> Thread Id : %ld\n",*Thread_id);
}

int main()
{
    pthread_t Thread_ID = 0;

    int iRet = 0;

    pthread_t *parameter = &Thread_ID;

    iRet = pthread_create(&Thread_ID , NULL , ThreadProc , (pthread_t *)parameter);

    if(iRet != 0)
    {
        printf("Unable to create thread\n");
        return -1;
    }

    pthread_join(Thread_ID,NULL);

    return 0;
}