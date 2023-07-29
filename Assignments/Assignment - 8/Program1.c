//This program waits till its child process terminates .
//Usage : "./Executable_Name"
#include<stdio.h>
#include<unistd.h>
#include<sys/wait.h>

int main()
{
    int iRet = 0;
    int Wait_Pid = 0;
    int Exit_status = 0;

    iRet = fork();

    if(iRet == 0)
    {
        execl("./ChildProcess","NULL",NULL);
    }
    else
    {
        printf("Parent is running with PID : %d\n",getpid());

        Wait_Pid = wait(&Exit_status);

        printf("Childprocess terminated having Pid %d with exit status %d\n",Wait_Pid,Exit_status);
    }

    return 0;
}