//Problem : Write a program which accept directory name from user and combine all contents of file from that directory into one file named as AllCombine
//Usage : "./Name_of_Executable   Name_of_Directory"
#include<stdio.h>
#include<fcntl.h>
#include<unistd.h>
#include<dirent.h>
#include<string.h>
#include<stdlib.h>

#define Block 1024

int main(int argc,char *argv[])
{
    if(argc != 2)
    {
        printf("Invalid arguments\n");
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
    fd = creat("AllCombine.txt",0777);
    if(fd == -1)
    {
        printf("Unable to create new file\n");
        return -1;
    }

    char Buffer[Block] = {'\0'};
    char FilePath[50] = {'\0'};

    int iNo = 0;
    int fd_source = 0;
    int iRet = 0;

    while((entry = readdir(dp)) != NULL)
    {
        if((strcmp(entry->d_name,"..") == 0) || (strcmp(entry->d_name,".") == 0))
        {
            continue;
        }

        iNo = snprintf(FilePath,50,"%s/%s",argv[1],entry->d_name);

        iNo = snprintf(Buffer,100,"\n\nFile Name ::::::::::::::::::::::::::::::%s:::::::::::::::::::::::::::::: File Name\n\n",entry->d_name);
        write(fd,Buffer,strlen(Buffer));

        fd_source = open(FilePath,O_RDONLY);
        if(fd_source == -1)
        {
            printf("Unable to open files\n");
            return -1;
        }

        while(iRet = read(fd_source,Buffer,Block) != 0)
        {
            write(fd,Buffer,Block);
        }

        iNo = snprintf(Buffer,100,"\n\nFile End ::::::::::::::::::::::::::::::%s:::::::::::::::::::::::::::::: File End\n\n",entry->d_name);
        write(fd,Buffer,strlen(Buffer));
    }
    if((entry = readdir(dp)) == NULL)
    {
        printf("Data has been successfully wrote into AllCombine\n");
    }

    close(fd);
    close(fd_source);
    closedir(dp);

    return 0;
}