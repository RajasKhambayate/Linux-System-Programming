//This program contains methods such as CompareFiles which are required by Program2.c
#include"Helper2.h"

void CompareFiles(char FirstFile[],char SecondFile[])
{
    struct stat Stat_obj1;
    struct stat Stat_obj2;

    int fd_source = 0;
    int fd_destination = 0;

    fd_source = open(FirstFile,O_RDONLY);
    fd_destination = open(SecondFile,O_RDONLY);
    if((fd_source == -1) || (fd_destination == -1))
    {
        printf("Unable to open files\n");
        return;
    }

    stat(FirstFile,&Stat_obj1);
    stat(SecondFile,&Stat_obj2);

    if(Stat_obj1.st_size != Stat_obj2.st_size)
    {
        printf("Files size are different\n");
        return;
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
}