//This program creates daemon process .
//Usage : "./Executable_Name"
#include<stdio.h>
#include<unistd.h>
#include<fcntl.h>

int main()
{
    int Child_Pid = 0;;

    Child_Pid = fork();
    if(Child_Pid == -1)
    {
        printf("Unable to create child process\n");
        return -1;
    }
    else if(Child_Pid != 0)
    {
        printf("Parent Says : Child[Daemon] process has started running...\n");
    }

    if(Child_Pid != 0)
    {
        return 0;
    }

    int fd = creat("Demo.txt",0777);//Here the daemon process will create file named Demo.txt
}