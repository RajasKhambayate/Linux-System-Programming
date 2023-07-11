//This program reads a file which stored in a subdirectory
//Usage : "./Name_of_Executable   Name_of_Directory   Name_of_File  Number_of_Bytes_to_Read"
#include<stdio.h>
#include<stdlib.h>
#include<fcntl.h>
#include<unistd.h>
#include<dirent.h>
#include<string.h>
#include<sys/stat.h>

int main(int argc,char *argv[])
{
    if(argc != 4)
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
            char *Buffer = NULL;

            sprintf(FilePath,"%s/%s",argv[1],entry->d_name);

            fd = open(FilePath,O_RDONLY);
            if(fd == -1)
            {
                printf("Unable to open file\n");
                return -1;
            }

            printf("\n");
            Buffer = (char *)malloc(sizeof(atoi(argv[3])));

            iRet = read(fd,Buffer,atoi(argv[3]));
            if(iRet == 0)
            {
                printf("Unable to read data from file\n");
                return -1;
            }

            printf("Data from file is : \n");
            write(1,Buffer,iRet);

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