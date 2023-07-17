//Problem : Write a program which accepts file name and position from user and read 20 bytes from that position
//Usage : "./Name_of_Executable   Name_of_File   Position"
#include<stdio.h>
#include<stdlib.h>
#include<fcntl.h>
#include<unistd.h>
#include<string.h>

int main(int argc, char *argv[])
{
    if(argc != 3)
    {
        printf("Invalid arguments\n");
        return -1;
    }

    int fd = 0;
    int iRet = 0;

    char Buffer[20];

    fd = open(argv[1],O_RDONLY);
    if(fd == -1)
    {
        printf("Unable to open file\n");
        return -1;
    }

    lseek(fd,atoi(argv[2]),0);

    iRet = read(fd,Buffer,20);

    printf("Data from file is \n");
    write(1,Buffer,iRet);

    close(fd);

    return 0;
}