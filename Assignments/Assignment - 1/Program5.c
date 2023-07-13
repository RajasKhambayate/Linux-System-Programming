//Problem : Write a program which accept file name from user and number of bytes from user and read that number of bytes from file
//Usage : "./Name_of_Executable   Name_of_File   Name_of_Bytes_to_Read "
#include<stdio.h>
#include<unistd.h>
#include<fcntl.h>
#include<stdlib.h>

int main(int argc,char *argv[])
{
    if(argc != 3)
    {
        printf("Insufficient arguments\n");
        return -1;
    }

    int fd = 0,iRet = 0;
    char *Buffer = NULL;

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

    printf("Data from file is : %s\n",Buffer);

    return 0;
}