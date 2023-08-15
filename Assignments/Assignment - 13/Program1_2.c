//Write a program which is used to creates two process as reader and writer and that process should communicate with each other using FIFO .
//Usage : "./Executable_name_2"
//Client For FIFO
#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<fcntl.h>
#include<string.h>
#include<sys/stat.h>

#define Block 1024

int main()
{
    int fd = 0;

    char *path = "/tmp/Named_pipe";

    char Buffer[Block];

    printf("Client is running and reading data from named pipe...\n");
    fd = open(path,O_RDONLY);
    if(fd == -1)
    {
        printf("Unable to open named pipe\n");
        return -1;
    }

    read(fd,Buffer,Block);

    printf("Data from pipe is : %s",Buffer);

    return 0;
}