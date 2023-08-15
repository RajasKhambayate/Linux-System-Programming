//Write a program which creates two process as sender and receiver in which sender process send signal to receiver process .
//Usage : "./Executable_name_1"
#include<stdio.h>
#include<signal.h>
#include<unistd.h>

void sig_handler1(int signo)
{
    if(signo == SIGUSR1)
    {
        printf("received signal : SIGUSR1\n");
    }

    int iCnt = 0;

    while(iCnt != 10)
    {
        printf("%d\n",iCnt);
        iCnt++;
    }

    printf("Received signal is %d\n",signo);
}

void sig_handler2(int signo)
{
    if(signo == SIGABRT)
    {
        printf("received signal : SIGUSR1\n");
    }

    printf("Received signal : %d\n",signo);
}

int main()
{
    printf("Ready to receive the signal\n");
    signal(SIGUSR1,sig_handler1);
    signal(SIGKILL,sig_handler2);
    while(1)
    {}

    return 0;
}