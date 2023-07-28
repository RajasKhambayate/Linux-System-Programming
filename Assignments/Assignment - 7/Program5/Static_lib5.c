//This program contains the methods required by Program5.c
#include"Helper5.h"
#include<sys/stat.h>

void Stat_File(char FileName[])
{
    struct stat Stat_obj;

    stat(FileName,&Stat_obj);

    printf("File name          : %s\n",FileName);
    printf("File size          : %d\n",Stat_obj.st_size);
    printf("Number of links    : %d\n",Stat_obj.st_nlink);
    printf("Inode number       : %d\n",Stat_obj.st_ino);
    printf("File system number : %d\n",Stat_obj.st_dev);
}