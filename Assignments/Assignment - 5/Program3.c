//Problem : Write a program which accept directory name from user and write information of all regular file in and then read the contents from that file
//Usage : "./Name_of_Executable   Name_of_Directory"
#include<stdio.h>
#include<fcntl.h>
#include<unistd.h>
#include<dirent.h>
#include<sys/stat.h>
#include<string.h>

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

    char Buffer[1024] = {'\0'};
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
            fd_source = open(FilePath,O_RDONLY);
            if(fd_source == -1)
            {
                printf("Unable to open files\n");
                return -1;
            }

            stat(FilePath,&Stat_obj);
            iNo = snprintf(Buffer,30,"%20s : %ld\n",entry->d_name,Stat_obj.st_size);

            write(fd,Buffer,strlen(Buffer));
        }
    }
    if((entry = readdir(dp)) == NULL)
    {
        printf("Data has been successfully wrote into Demo.txt\n");
    }

    fd = open("Demo.txt",O_RDONLY);
    if(fd == -1)
    {
        printf("Unable to read destination file\n");
        return -1;
    }

    printf("Data from destination file is : \n");
    while(iRet = read(fd,Buffer,1024) != 0)
    {
        write(1,Buffer,1024);
    }

    printf("\n");

    close(fd);
    close(fd_source);
    closedir(dp);

    return 0;
}