//Write a program which is used to creates two process as reader and writer and that process should communicate with each other using FIFO .
//Usage : "./Executable_name_1"
//Server For FIFO
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
    char Buffer[BUFSIZ];

    char *path = "/tmp/Named_pipe";

    printf("Please write data into the pipe : ");
    fgets(Buffer,BUFSIZ,stdin);

    fd = mkfifo(path,0666);
    if(fd == -1)
    {
        printf("Unable to create named pipe\n");
        return -1;
    }

    printf("Server is running and writing the data into named pipe...\n");
    fd = open(path,O_WRONLY);

    write(fd,Buffer,strlen(Buffer));

    close(fd);
    unlink(path);

    printf("Data succesfully written in the pipe\n");

    return 0;
}