//This program creates three process as process_1 , process_2 and process_3 .
//Usage : "./Executable_Name"
#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<sys/wait.h>
#include<sys/types.h>

int main()
{
    int Parent_Pid = getpid();
    printf("Main process created with Pid : %d\n",Parent_Pid);

    int Process2 = 0;
    int Process3 = 0;
    int Process4 = 0;

    if(Parent_Pid == getpid())
    {
        Process2 = fork();
        if(Process2 == -1)
        {
            printf("Unable to create process 2\n");
            return -1;
        }
        else if(Parent_Pid == getpid())
        {
            printf("Process 2 created successfully with pid : %d\n",Process2);
        }
    }

    if(Parent_Pid == getpid())
    {
        Process3 = fork();
        if(Process3 == -1)
        {
            printf("Unable to create process 3\n");
            return -1;
        }
        else if(Parent_Pid == getpid())
        {
            printf("Process 3 created successfully with pid : %d\n",Process3);
        }
    }

    if(Parent_Pid == getpid())
    {
        Process4 = fork();
        if(Process4 == -1)
        {
            printf("Unable to create process 4\n");
            return -1;
        }
        else if(Parent_Pid == getpid())
        {
            printf("Process 4 created successfully with pid : %d\n",Process4);
        }
    }

    return 0;
}