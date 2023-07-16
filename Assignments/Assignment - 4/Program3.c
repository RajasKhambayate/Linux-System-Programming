//Problem : Write a program which accepts two file names from user and check whether contents of tha two files are equal or not
//Usage : "./Name_of_Executable   Name_of_First-File   Name_of_Second-File"
#include<stdio.h>
#include<fcntl.h>
#include<unistd.h>
#include<string.h>
#include<sys/stat.h>

#define Block 1024

int main(int argc,char *argv[])
{
    if(argc != 3)
    {
        printf("Invalid arguments\n");
        return -1;
    }

    struct stat Stat_obj1;
    struct stat Stat_obj2;

    int fd_source = 0;
    int fd_destination = 0;

    fd_source = open(argv[1],O_RDONLY);
    fd_destination = open(argv[2],O_RDONLY);
    if((fd_source == -1) || (fd_destination == -1))
    {
        printf("Unable to open files\n");
        return -1;
    }

    stat(argv[1],&Stat_obj1);
    stat(argv[2],&Stat_obj2);

    if(Stat_obj1.st_size != Stat_obj2.st_size)
    {
        printf("Files size are different\n");
        return 1;
    }

    int iDiff = 0;
    int iRet = 0;

    char Buffer1[Block] = {'\0'};
    char Buffer2[Block] = {'\0'};

    while(iRet = read(fd_source,Buffer1,Block) != 0)
    {
        read(fd_destination,Buffer2,Block);

        if(memcmp(Buffer1,Buffer2,Block) != 0)
        {
            break;
        }
    }
    if(iRet == 0)
    {
        printf("Files are identical\n");
    }
    else
    {
        printf("Files are not identical\n");
    }

    return 0;
}