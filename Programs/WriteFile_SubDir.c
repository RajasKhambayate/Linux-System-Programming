//This program writes data from a file on console which is stored in a subdirectory
//Usage : "./Name_of_Executable   Name_of_Directory   Name_of_File Data   Data"
#include<stdio.h>
#include<stdlib.h>
#include<fcntl.h>
#include<unistd.h>
#include<string.h>

#define Block 1024

int main(int argc,char *argv[])
{
    if(argc != 4)
    {
        printf("Insufficient arguments\n");
        return -1;
    }

    int fd = 0;
    int iRet = 0;
    char FilePath[50] = {'\0'};
    char Buffer[Block] = {'\0'};

    strcat(Buffer,argv[3]);

    int iNo = snprintf(FilePath,50,"%s/%s",argv[1],argv[2]);

    fd = open(FilePath,O_WRONLY);
    if(fd == -1)
    {
        printf("Unable to open file\n");
        return -1;
    }

    write(fd,Buffer,iRet);

    printf("Data has been written successfully into the file\n");

    close(fd);

    return 0;
}