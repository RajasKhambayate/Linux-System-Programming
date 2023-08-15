//Write a program which accept user defined signal from terminal .
//Usage : "./Executable_name"
//From another terminal : "kill -SIGUSR1 Executable_name_PID && kill Executable_name_PID"
#include<stdio.h>
#include<signal.h>
#include<unistd.h>

void sig_handler(int signo)
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

int main()
{
    printf("Ready to receive the signal\n");
    signal(SIGUSR1, sig_handler);

    while(1)
    {}

    return 0;
}