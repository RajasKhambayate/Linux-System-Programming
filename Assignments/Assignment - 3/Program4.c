//Problem : Write a program which accept directory name from user and delete all empty files from that directory
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
    int iNo = 0;

    while((entry = readdir(dp)) != NULL)
    {
        if((strcmp(entry->d_name,"..") == 0) || (strcmp(entry->d_name,".") == 0))
        {
            continue;
        }

        iNo = snprintf(FilePath,50,"%s/%s",argv[1],entry->d_name);

        stat(FilePath,&Stat_obj);

        if(Stat_obj.st_size == 0)
        {
            remove(FilePath);
            printf("deleted : %s\n",entry->d_name);
        }
    }

    closedir(dp);

    return 0;
}