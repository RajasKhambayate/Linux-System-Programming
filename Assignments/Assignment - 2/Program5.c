//Problem : Write a program which accept directory name from user and print name of such a file having largest size
//Usage : "./Name_of_Executable   Name_of_Directory"
#include<stdio.h>
#include<dirent.h>
#include<string.h>
#include<sys/stat.h>

int main(int argc,char *argv[])
{
    if(argc != 2)
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

    struct stat Stat_obj;

    char FilePath[50] = {'\0'};
    char MaxFileName[50];

    int MaxFileSize = 0;
    int iNo = 0;

    while((entry = readdir(dp)) != NULL)
    {
        if((strcmp(entry->d_name,"..") == 0) || (strcmp(entry->d_name,".") == 0))
        {
            continue;
        }

        iNo = snprintf(FilePath,50,"%s/%s",argv[1],entry->d_name);

        stat(FilePath,&Stat_obj);

        if(Stat_obj.st_size > MaxFileSize)
        {
            MaxFileSize = Stat_obj.st_size;
            iNo = snprintf(MaxFileName,30,"%s",entry->d_name);
        }
    }
    if((entry = readdir(dp)) == NULL)
    {
        printf("File named %s has highest size in folder named %s that is : %d\n",MaxFileName,argv[1],MaxFileSize);
    }

    closedir(dp);

    return 0;
}