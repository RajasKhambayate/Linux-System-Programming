//Write a program which creates one child process , child process write something in unnamed pipe and parent process read the data from the pipe .
//Usage : "./Executable_name"
#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<fcntl.h>
#include<string.h>

#define Block 1024

int main()
{
    int FD[2],iRet = 0;
    char Arr[] = "Hello Child Process",Buffer[Block];

    pipe(FD);
    iRet = fork();

    if(iRet == 0)
    {
        printf("Child process scheduled for writing into pipe\n");
        close(FD[0]);
        write(FD[1],Arr,strlen(Arr));

        exit(0);
    }
    else
    {
        printf("Parent process scheduled for reading from pipe\n");
        close(FD[1]);
        read(FD[0],Buffer,sizeof(Buffer));

        printf("Data from pipe (Child Process) is : %s\n",Buffer);
    }

    return 0;
}