//Write a program which is used to creates such a process which accept signals from the terminal .
//Usage : "./Executable_name"
#include<stdio.h>
#include<signal.h>
#include<unistd.h>

void sig_handler(int signo)
{
    if(signo == SIGINT)
    {
        printf("received signal : SIGINT\n");
    }

    printf("Received signal is %d\n",signo);
}

int main()
{
    printf("Ready to receive the signal\n");
    signal(SIGINT, sig_handler);

    while(1)
    {
        sleep(1);
    }

    return 0;
}