//Write a program which is used to create a child process , child process and parent process should communicate with each other using signals .
//Usage : "./Executable_name"
#include<stdio.h>
#include<signal.h>
#include<unistd.h>
#include<wait.h>

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
    int iRet = 0,status = 0;

    iRet = fork();

    if(iRet == 0)
    {
        signal(SIGINT,sig_handler);
    }
    else
    {
        kill(iRet,SIGINT);

        wait(&status);
        if(WIFSIGNALED(status))
        {
            psignal(WTERMSIG(status),"Current child process status");
        }
    }

    return 0;
}