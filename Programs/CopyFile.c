//This program performs task of cp command which make a copy of existing file.
#include<stdio.h>
#include<unistd.h>
#include<fcntl.h>
#include<stdlib.h>
#include<string.h>

#define BLOCKSIZE 1024

int main(int argc,char *argv[])
{
    if(argc != 3)
    {
        printf("Insufficient arguments");
        return -1;
    }

    int fdSource = 0,fdDest = 0,iRet = 0;
    char Buffer[BLOCKSIZE] = {'\0'};

    fdSource = open(argv[1],O_RDONLY);
    if(fdSource == -1)
    {
        printf("Unable to open source file\n");
        return -1;
    }

    fdDest = creat(argv[2],0777);
    if(fdDest == -1)
    {
        printf("Unable to create destination file\n");
        close(fdSource);
        return -1;
    }

    while((iRet = read(fdSource,Buffer,sizeof(Buffer))) != 0)
    {
        write(fdDest,Buffer,iRet);
        memset(Buffer,0,sizeof(Buffer));
    }

    return 0;
}