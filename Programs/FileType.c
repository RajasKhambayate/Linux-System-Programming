//This program performs task of stat command which displays properties of existing file.
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

    struct stat stat_obj;

    stat(argv[1],&stat_obj);

    if(S_ISREG(stat_obj.st_mode))
    {
        printf("Its a regular file\n");
    }
    else if(S_ISDIR(stat_obj.st_mode))
    {
        printf("Its a directory\n");
    }
    else if(S_ISLNK(stat_obj.st_mode))
    {
        printf("Its a symbolic link\n");
    }

    return 0;
}