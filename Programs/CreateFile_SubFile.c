//This program accept directory name and file name from user and create file in that directory
//Usage : "./Name_of_Executable   Name_of_Directory   Name_of_File"
#include<stdio.h>
#include<fcntl.h>
#include<unistd.h>
#include<dirent.h>
#include<stdlib.h>

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

    int fd = 0;
    int iNo = 0;

    char FilePath[50] = {'\0'};

    iNo = snprintf(FilePath,50,"%s/%s",argv[1],argv[2]);

    fd = creat(FilePath,0777);
    if(fd == -1)
    {
        printf("Unable to create the file\n");
        return -1;
    }
    else
    {
        printf("File created successfully with fd : %d\n",fd);
    }

    close(fd);
    closedir(dp);

    return 0;
}