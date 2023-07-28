//This program waits till its child process terminates .
//Usage : "./Executable_Name"
#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<sys/wait.h>
#include<sys/types.h>

int main()
{
    int Parent_Pid = getpid();
    printf("Parent process has started running...\n");

    int Status = 0,Child_Pid = 1,WaitPid_Ret = 0;

    if(Child_Pid != 0)
    {
        Child_Pid = fork();
        if(Child_Pid == -1)
        {
            printf("Unable to create child process\n");
            return -1;
        }
        else if(Child_Pid != 0)
        {
            printf("Child process has started running...\n");
        }
    }


    if(Child_Pid != 0)
    {
        WaitPid_Ret = waitpid(Child_Pid,&Status,0);

        while(!WIFEXITED(Status))
        {}

        if(WIFEXITED(Status))
        {
            printf("Child process has terminated\n");
        }

        printf("Parent process is now going to terminated\n");
    }

    return 0;
}