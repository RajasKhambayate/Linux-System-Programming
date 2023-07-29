//This program displays priority of process of itself .
//Usage : "./Executable_name"
#include<stdio.h>
#include<unistd.h>
#include<sys/resource.h>

int main()
{
    int iRet = 0;

    iRet = getpriority(PRIO_PROCESS,0);
    printf("Priority of this process: %d\n",iRet);

    return 0;
}