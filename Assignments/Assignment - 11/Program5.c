//This program creates two threads by using pthread API , where one thread count number of capital characters from a file and other thread count number of small characters from same file .
//Usage : "./Executable_Name   File_Name"
#include<stdio.h>
#include<pthread.h>
#include<stdlib.h>
#include<unistd.h>
#include<fcntl.h>
#include<string.h>

struct DataTransfer
{
    pthread_mutex_t lock;
    char FileName[50];
    int iRet;
}DT;

void * ThreadProc1(void *ptr)
{
    pthread_mutex_lock(&DT.lock);

    char Buffer[1024];
    int iCnt = 0,iRet = 0,i = 0,fd = 0;

    fd = open(DT.FileName,O_RDONLY);
    if(fd == -1)
    {
        return NULL;
    }

    while((iRet = read(fd,Buffer,sizeof(Buffer))) != 0)
    {
        for(i = 0;i < iRet;i++)
        {
            if((Buffer[i] >= 'A') && (Buffer[i] <= 'Z'))
            {
                iCnt++;
            }
        }
    }
    printf("Capital character count is = %d\n",iCnt);

    pthread_mutex_unlock(&DT.lock);
}

void * ThreadProc2(void *ptr)
{
    char Buffer[1024];
    int iCnt = 0,iRet = 0,i = 0,fd = 0;

    fd = open(DT.FileName,O_RDONLY);
    if(fd == -1)
    {
        return NULL;
    }

    while((iRet = read(fd,Buffer,sizeof(Buffer))) != 0)
    {
        for(i = 0;i < iRet;i++)
        {
            if((Buffer[i] >= 'a') && (Buffer[i] <= 'z'))
            {
                iCnt++;
            }
        }
    }
    printf("Small character count is = %d\n",iCnt);

    pthread_mutex_unlock(&DT.lock);
}

int main(int argc,char *argv[])
{
    if(argc != 2)
    {
        printf("Invalid arguments\n");
        return -1;
    }

    strcpy(DT.FileName,argv[1]);

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

    if((iCreateRet1 != 0) && (iCreateRet2 != 0))
    {
        printf("Unable to create threads\n");
        return -1;
    }

    pthread_join(Thread_ID1,NULL);
    pthread_join(Thread_ID2,NULL);

    return 0;
}