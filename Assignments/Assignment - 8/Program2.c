//This program creates three level process hierarchy where process_1 creates process_2 and it internally creates process_3 .
//Usage : "./Executable_Name"
#include<stdio.h>
#include<unistd.h>
#include<sys/wait.h>
#include<sys/types.h>

int main()
{
    printf("Parent process has started running with Parent_Pid[%d] and Pid[%d]\n",getppid(),getpid());

    int Child_Pid = 0,GrandChild_Pid = 0;
    int Status = 0,Status2 = 0,WaitPid_Ret = 0,WaitPid_Ret2 = 0;

    Child_Pid = fork();
    if(Child_Pid == -1)
    {
        printf("Unable to create child process\n");
        return -1;
    }

    if((GrandChild_Pid == 0) && (Child_Pid == 0))
    {
        printf("Child process has been created with Parent_Pid[%d] and Pid[%d]\n",getppid(),getpid());
    }

    if(Child_Pid == 0)
    {
        GrandChild_Pid = fork();
        if(GrandChild_Pid == -1)
        {
            printf("Unable to create grand child process\n");
            return -1;
        }
    }

    if((GrandChild_Pid == 0) && (Child_Pid == 0))
    {
        printf("Grand child process has been created with Parent_Pid[%d] and Pid[%d]\n",getppid(),getpid());
    }

    return 0;
}