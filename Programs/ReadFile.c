//This program will read a file using a system call
#include<stdio.h>
#include<unistd.h>
#include<fcntl.h>
#include<stdlib.h>

int main(int argc,char *argv[])
{
    int fd = 0,iRet = 0;
    char *Buffer = NULL;

    if(argc != 3)
    {
        printf("Insufficient arguments\n");
        return -1;
    }

    fd = open(argv[1],O_RDONLY);
    if(fd == -1)
    {
        printf("Unable to open file\n");
        return -1;
    }

    printf("\n");
    Buffer = (char *)malloc(sizeof(atoi(argv[2])));

    iRet = read(fd,Buffer,atoi(argv[2]));
    if(iRet == 0)
    {
        printf("Unable to read data from file\n");
        return -1;
    }

    printf("Data from file is : \n");
    write(1,Buffer,iRet);

    return 0;
}