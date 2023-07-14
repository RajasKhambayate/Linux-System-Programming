//Problem : Write a program which accept two directory names from user and move all files from source directory to destination directory
//Usage : "./Name_of_Executable   Name_of_Source-Directory   Name_of_Destination-Direcory"
#include<stdio.h>
#include<dirent.h>
#include<string.h>
#include<stdlib.h>
#include<fcntl.h>
#include<unistd.h>
#include<sys/stat.h>

#define Block 1024

int main(int argc,char *argv[])
{
    if(argc != 3)
    {
        printf("Insufficient arguments\n");
        return -1;
    }

    int iNo = 0;
    int fd_source = 0;
    int fd_destination = 0;
    int iRet = 0;

    char FilePath_Source[50] = {'\0'};
    char FilePath_Destination[50] = {'\0'};
    char Buffer[Block] = {'\0'};

    DIR *dp_source = NULL;

    struct dirent * entry = NULL;

    dp_source = opendir(argv[1]);
    if(dp_source == NULL)
    {
        printf("Unable to open directory\n");
        return -1;
    }

    fd_destination = mkdir(argv[2],0777);
    if(fd_destination == -1)
    {
        printf("Unable to open directory\n");
        return -1;
    }

    while((entry = readdir(dp_source)) != NULL)
    {
        if((strcmp(entry->d_name,"..") == 0) || (strcmp(entry->d_name,".") == 0))
        {
            continue;
        }


        iNo = snprintf(FilePath_Source,50,"%s/%s",argv[1],entry->d_name);
        fd_source = open(FilePath_Source,O_RDONLY);
        if(fd_source == -1)
        {
            printf("Error occured while opening a file\n");
            return -1;
        }

        iNo = snprintf(FilePath_Destination,50,"%s/%s",argv[2],entry->d_name);
        fd_destination = creat(FilePath_Destination,0777);
        if(fd_destination == -1)
        {
            printf("Error occured while creating a file\n");
            return -1;
        }

        while((iRet = read(fd_source,Buffer,sizeof(Buffer))) != 0)
        {
            write(fd_destination,Buffer,iRet);
            memset(Buffer,0,sizeof(Buffer));
        }

        continue;
    }

    printf("Files moved successfully\n");

    return 0;
}