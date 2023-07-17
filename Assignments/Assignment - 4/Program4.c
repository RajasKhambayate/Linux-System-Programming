//Problem : Write a program which accepts directory name from user and copy first 10 bytes from all regular files into newly created file named as Demo.txt
//Usage : "./Name_of_Executable   Name_of_Directory"
#include<stdio.h>
#include<fcntl.h>
#include<unistd.h>
#include<dirent.h>
#include<sys/stat.h>

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
    fd = creat("Demo.txt",0777);
    if(fd == -1)
    {
        printf("Unable to create new file\n");
        return -1;
    }

    struct stat Stat_obj;

    char Buffer[15] = {'\0'};
    char FilePath[50] = {'\0'};
    int iNo = 0;
    int fd_source = 0;
    int iRet = 0;

    while((entry = readdir(dp)) != NULL)
    {
        iNo = snprintf(FilePath,50,"%s/%s",argv[1],entry->d_name);

        stat(FilePath,&Stat_obj);

        if(S_ISREG(Stat_obj.st_mode))
        {
            if(Stat_obj.st_size < 10)
            {
                fd_source = open(FilePath,O_RDONLY);
                if(fd_source == -1)
                {
                    printf("Error occured while opening files\n");
                    return -1;
                }

                iRet = read(fd_source,Buffer,Stat_obj.st_size);
                write(fd,Buffer,iRet);
            }
            else if(Stat_obj.st_size >= 10)
            {
                fd_source = open(FilePath,O_RDONLY);
                if(fd_source == -1)
                {
                    printf("Error occured while opening files\n");
                    return -1;
                }

                iRet = read(fd_source,Buffer,10);
                write(fd,Buffer,iRet);
            }
        }
    }
    if((entry = readdir(dp)) == NULL)
    {
        printf("Data has been successfully wrote into Demo.txt\n");
    }


    close(fd);
    close(fd_source);
    closedir(dp);

    return 0;
}