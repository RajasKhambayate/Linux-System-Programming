//This program yield the processor .
//Usage : "./Executable_name"
#include<stdio.h>
#include<unistd.h>
#include<sched.h>

int main()
{
    int iRet = 0,Child_Pid = 0;

    Child_Pid = 0;

    Child_Pid = fork();

    if(Child_Pid == 0)
    {
        iRet = sched_yield();
        if(iRet == 0)
        {
            printf("Processor yielded successfully\n");
        }
        else
        {
            printf("Unable to yield the processor\n");
            return -1;
        }
    }

    return 0;
}