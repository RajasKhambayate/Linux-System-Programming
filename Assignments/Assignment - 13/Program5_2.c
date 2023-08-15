//Write a program which creates two process as sender and receiver in which sender process send signal to receiver process .
//Usage : "./Executable_name_2   PID_Executable_Program5_1.c"
#include<stdio.h>
#include<signal.h>
#include<unistd.h>
#include<stdlib.h>

int main(int argc,char *argv[])
{
    int PID = atoi(argv[1]);

    kill(PID,SIGUSR1);
    sleep(2);
    kill(PID,SIGKILL);

    return 0;
}