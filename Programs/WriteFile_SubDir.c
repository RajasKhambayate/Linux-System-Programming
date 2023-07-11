//This program writes data from a file on console which is stored in a subdirectory
//Usage : "./Name_of_Executable   Name_of_Directory   Name_of_File"
#include<stdio.h>
#include<stdlib.h>
#include<fcntl.h>
#include<unistd.h>
#include<dirent.h>
#include<string.h>
#include<sys/stat.h>

#define BLOCKSIZE 1024

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
            int fd = 0;
            int iRet = 0;
            char FilePath[50] = {'\0'};
            char Buffer[BLOCKSIZE] = {'\0'};

            int iNo = snprintf(FilePath,50,"%s/%s",argv[1],entry->d_name);

            fd = open(FilePath,O_RDWR);
            if(fd == -1)
            {
                printf("Unable to open file\n");
                return -1;
            }

            while((iRet = read(fd,Buffer,sizeof(Buffer))) != 0)
            {
                write(1,Buffer,iRet);
            }

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