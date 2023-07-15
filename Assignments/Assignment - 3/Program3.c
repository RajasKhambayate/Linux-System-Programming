//Problem : Write a program which accept two directory names from user and move all files from source directory to destination directory
//Usage : "./Name_of_Executable   Name_of_Source-Directory   Name_of_Destination-Direcory"
#include<stdio.h>
#include<dirent.h>
#include<string.h>
#include<fcntl.h>
#include<sys/stat.h>
#include<unistd.h>

int main(int argc,char *argv[])
{
    if(argc != 3)
    {
        printf("Insufficient arguments\n");
        return -1;
    }

    int iNo1 = 0,iNo2 = 0;
    int iRet = 0;
    int fd_destination = 0;

    char FilePath_Source[50] = {'\0'};
    char FilePath_Destination[50] = {'\0'};

    DIR *dp_source = NULL;
    DIR *dp_destination = NULL;

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
        printf("Unable to create destination directory\n");
        return -1;
    }

    char NewFileName[30] = {'\0'};

    while((entry = readdir(dp_source)) != NULL)
    {
        if((strcmp(entry->d_name,"..") == 0) || (strcmp(entry->d_name,".") == 0))
        {
            continue;
        }

        memset(NewFileName,'\0',30 * sizeof(char));

        iNo1 = snprintf(FilePath_Source,50,"%s/%s",argv[1],entry->d_name);

        strcat(NewFileName,entry->d_name);
        iNo2 = snprintf(FilePath_Destination,50,"%s/%s",argv[2],NewFileName);

        iRet = rename(FilePath_Source,FilePath_Destination);
        if(iRet != 0)
        {
            printf("Unable to move file\n");
            return -1;
        }
    }

    printf("Files moved successfully\n");

    close(fd_destination);

    return 0;
}