//This program displays properties of a file from its file descriptor which currently is running
//Usage : "./Name_of_Executable   Name_of_File"
#include<stdio.h>
#include<stdlib.h>
#include<fcntl.h>
#include<unistd.h>
#include<sys/stat.h>

int main(int argc, char *argv[])
{
    if(argc != 2)
    {
        printf("Insufficient arguments\n");
        return -1;
    }

    struct stat Fstat_obj;
    int fd = 0;

    fd = open(argv[1],O_RDONLY);
    fstat(fd,&Fstat_obj);

    printf("File name : %s\n",argv[1]);
    printf("File size is : %d\n",Fstat_obj.st_size);
    printf("Number of links : %d\n",Fstat_obj.st_nlink);
    printf("Inode number : %d\n",Fstat_obj.st_ino);
    printf("File system number : %d\n",Fstat_obj.st_dev);
    printf("Number of blocks : %d\n",Fstat_obj.st_blocks);

    return 0;
}
