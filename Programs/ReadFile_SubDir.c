//This program reads a file which stored in a subdirectory
//Usage : "./Name_of_Executable   Name_of_Directory   Name_of_File"
#include<stdio.h>
#include<stdlib.h>
#include<fcntl.h>
#include<unistd.h>
#include<string.h>

#define Block 1024

int main(int argc,char *argv[])
{
    if(argc != 3)
    {
        printf("Insufficient arguments\n");
        return -1;
    }

    int fd = 0;
    int iRet = 0;
    int iNo = 0;
    char FilePath[50] = {'\0'};
    char Buffer[Block] = {"\0"};

    iNo = snprintf(FilePath,50,"%s/%s",argv[1],argv[2]);

    fd = open(FilePath,O_RDONLY);
    if(fd == -1)
    {
        printf("Unable to open file\n");
        return -1;
    }

    printf("Data from file is : \n");

    while(iRet = read(fd,Buffer,Block) != 0)
    {
        write(1,Buffer,iRet);
    }

    close(fd);

    return 0;
}