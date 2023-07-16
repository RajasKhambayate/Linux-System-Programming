//Problem : Write a program which create hole of size 1kb at end of file 
//Usage : "./Name_of_Executable   Name_of_File"
#include<stdio.h>
#include<fcntl.h>
#include<unistd.h>
#include<stdlib.h>
#include<sys/stat.h>

int main(int argc,char *argv[])
{
    if(argc != 2)
    {
        printf("Invalid arguments\n");
        return -1;
    }

    int fd = 0;
    int iRet = 0;

    fd = open(argv[1],O_RDWR);
    if(fd == -1)
    {
        printf("Unable to open file\n");
        return -1;
    }

    struct stat Stat_obj;
    fstat(fd,&Stat_obj);


    iRet = ftruncate(fd,Stat_obj.st_size + 1024);//truncate(filename,offset);
    if(iRet == 0)
    {
        printf("Data has been successfully manipulated\n");
    }
    else
    {
        printf("Unable to remove data\n");
        return -1;
    }

    return 0;
}