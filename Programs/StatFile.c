//This program performs task of stat command which displays properties of existing file.
#include<stdio.h>
#include<unistd.h>
#include<fcntl.h>
#include<stdlib.h>
#include<string.h>
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

    printf("File name          : %s\n",argv[1]);
    printf("File size          : %d\n",Stat_obj.st_size);
    printf("Number of links    : %d\n",Stat_obj.st_nlink);
    printf("Inode number       : %d\n",Stat_obj.st_ino);
    printf("File system number : %d\n",Stat_obj.st_dev);
    printf("Number of blocks   : %d\n",Stat_obj.st_blocks);
    printf("Block size         : %d\n",Stat_obj.st_blksize);

    return 0;
}