//This program displays properties of a file from its file descriptor which is stored in a subdirectory
//Usage : "./Name_of_Executable   Name_of_Directory   Name_of_File"
#include<stdio.h>
#include<stdlib.h>
#include<fcntl.h>
#include<unistd.h>
#include<dirent.h>
#include<string.h>
#include<sys/stat.h>

int main(int argc,char *argv[])
{
    if(argc != 3)
    {
        printf("Insufficient arguments\n");
        return -1;
    }

    DIR *dp = NULL;
    struct dirent * entry = NULL;

    dp = opendir(argv[1]);
    if(dp == NULL)
    {
        printf("Unable to open directory\n");
        return -1;
    }

    while((entry = readdir(dp)) != NULL)
    {
        if(strcmp(argv[2],entry->d_name) == 0)
        {
            char FilePath[50] = {'\0'};

            int iNo = snprintf(FilePath,50,"%s/%s",argv[1],entry->d_name);

            struct stat Fstat_obj;
            int fd = 0;

            fd = open(FilePath,O_RDONLY);

            fstat(fd,&Fstat_obj);

            printf("File name          : %s\n",entry->d_name);
            printf("File size          : %ld\n",Fstat_obj.st_size);
            printf("Number of links    : %ld\n",Fstat_obj.st_nlink);
            printf("Inode number       : %ld\n",Fstat_obj.st_ino);
            printf("File system number : %ld\n",Fstat_obj.st_dev);
            printf("Number of blocks   : %ld\n",Fstat_obj.st_blocks);
            printf("Block size         : %ld\n",Fstat_obj.st_blksize);

            close(fd);

            break;
        }
        else
        {
            continue;
        }
    }
    if((entry = readdir(dp)) == NULL)
    {
        printf("File with name '%s' doesn't exist in directory named %s\n",argv[2],argv[1]);
    }

    closedir(dp);

    return 0;
}