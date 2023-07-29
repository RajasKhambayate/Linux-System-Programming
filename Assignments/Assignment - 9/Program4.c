//This program increases priority by 5 of process of itself .
//Usage : "sudo ./Executable_name"
#include<stdio.h>
#include<unistd.h>
#include<sys/resource.h>

int main()
{
    int iRet = 0;

    iRet = getpriority(PRIO_PROCESS,0);
    printf("Priority before nice() : %d\n",iRet);

    iRet = nice(-5);
    printf("Priority after nice() : %d\n",iRet);

    return 0;
}