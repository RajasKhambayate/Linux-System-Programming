//Write a program which is used to create two processes and both the processes will communicate with each other by shared memory.
//Usage : "./Executable_name"
#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<fcntl.h>
#include<string.h>
#include<sys/stat.h>
#include <sys/shm.h>

int main()
{
    int iRet1 = 0,iRet2 = 0;

    int shmid = 0;
    int shmsize = 0;
    int Key = 0;
    char *ptr = NULL;

    iRet1 = fork();

    if(iRet1 == 0)
    {
        iRet2 = 1;
        shmid = 0;
        shmsize = 100;
        Key = 1234;

        printf("Process 1 : running...\n");

        shmid = shmget(Key,shmsize,IPC_CREAT | 0666);

        printf("Shared memory allocated succesfully...\n");

        ptr = shmat(shmid,NULL,0);

        if(ptr != NULL)
        {
            printf("Shared memory atached succesfully...\n");
        }

        *ptr = 'H';
        ptr++;

        *ptr = 'i';
        ptr++;
    }

    if((iRet1 != 0) && (iRet2 != 0))
    {
        iRet2 = fork();
    }

    if(iRet2 == 0)
    {
        sleep(1);
        iRet1 = 1;
        shmid = 0;
        shmsize = 100;
        Key = 1234;

        printf("Process 2 : running...\n");

        shmid = shmget(Key,shmsize, 0666);

        ptr = shmat(shmid,NULL,0);

        if(ptr != NULL)
        {
            printf("Shared memory atached succesfully...\n");
        }

        printf("Data form shared memory is : \n");
        while(*ptr != '\0')
        {
            printf("%c",*ptr);
            ptr++;
        }
        printf("\n");
    }

    return 0;
}