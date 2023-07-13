//Problem : Write a program which accept file name from user and print all information about that file
//Usage : "./Name_of_Executable   Name_of_File"
#include<stdio.h>
#include<fcntl.h>
#include<sys/stat.h>

int main(int argc,char *argv[])
{
    if(argc != 2)
    {
        printf("Insufficient arguments\n");
        return -1;
    }

    struct stat Stat_obj;

    stat(argv[1],&Stat_obj);

    printf("File name                       : %s\n",argv[1]);
    printf("File size                       : %ld\n",Stat_obj.st_size);
    printf("Number of links                 : %ld\n",Stat_obj.st_nlink);
    printf("Inode number                    : %ld\n",Stat_obj.st_ino);
    printf("File system number              : %ld\n",Stat_obj.st_dev);
    printf("Number of blocks                : %ld\n",Stat_obj.st_blocks);
    printf("Block size                      : %ld\n",Stat_obj.st_blksize);

    return 0;
}