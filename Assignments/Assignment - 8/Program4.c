//This program get terminated after its 2 child processes .
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
    int Status2 = 0,Child_Pid2 = 1,WaitPid_Ret2 = 0;

    if((Child_Pid != 0) && (Child_Pid2 != 0))
    {
        Child_Pid = fork();
        if(Child_Pid == -1)
        {
            printf("Unable to create child process\n");
            return -1;
        }
        else if((Child_Pid != 0) && (Child_Pid2 != 0))
        {
            printf("First Child process has started running...\n");
        }

        Child_Pid2 = fork();
        if(Child_Pid2 == -1)
        {
            printf("Unable to create child process\n");
            return -1;
        }
        else if((Child_Pid != 0) && (Child_Pid2 != 0))
        {
            printf("Second Child process has started running...\n");
        }
    }


    if((Child_Pid != 0) && (Child_Pid2 != 0))
    {
        WaitPid_Ret = waitpid(Child_Pid,&Status,0);
        WaitPid_Ret2 = waitpid(Child_Pid2,&Status2,0);

        while(!WIFEXITED(Status))
        {}
        while(!WIFEXITED(Status2))
        {}

        if(WIFEXITED(Status))
        {
            printf("First Child process has terminated\n");
        }
        if(WIFEXITED(Status2))
        {
            printf("Second Child process has terminated\n");
        }

        printf("Parent process is now going to terminated\n");
    }

    return 0;
}