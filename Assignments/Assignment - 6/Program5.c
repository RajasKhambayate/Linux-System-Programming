//Problem : Write a program which accept file name and offset from user , remove all data from that offset
//Usage : "./Name_of_Executable   Name_of_File   No_of_Offset"
#include<stdio.h>
#include<fcntl.h>
#include<unistd.h>
#include<stdlib.h>
#include<sys/stat.h>

int main(int argc,char *argv[])
{
    if(argc != 3)
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

    if(atoi(argv[2]) > Stat_obj.st_size)
    {
        printf("Offset is greater than file size\n");
        return 1;
    }

    iRet = ftruncate(fd,atoi(argv[2]));//truncate(filename,offset);
    if(iRet == 0)
    {
        printf("Data successfully removed\n");
    }
    else
    {
        printf("Unable to remove data\n");
        return -1;
    }

    return 0;
}