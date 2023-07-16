//This program opens a file which stored in a subdirectory
//Usage : "./Name_of_Executable   Name_of_Directory   Name_of_File"
#include<stdio.h>
#include<stdlib.h>
#include<fcntl.h>
#include<unistd.h>
#include<string.h>

int main(int argc,char *argv[])
{
    if(argc != 3)
    {
        printf("Insufficient arguments\n");
        return -1;
    }

    int fd = 0;
    char FilePath[50] = {'\0'};

    int iNo = snprintf(FilePath,50,"%s/%s",argv[1],argv[2]);

    fd = open(FilePath,O_RDONLY);
    if(fd == -1)
    {
        printf("Unable to open file\n");
        return -1;
    }
    else
    {
        printf("File is successfully opened with FD %d\n",fd);
    }

    close(fd);

    return 0;
}