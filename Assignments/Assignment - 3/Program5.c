//Problem : Write a program which accept directory name and file name from user and delete that file in that directory
//Usage : "./Name_of_Executable   Name_of_Directory   Name_of_File"
#include<stdio.h>
#include<dirent.h>
#include<string.h>

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

    char FilePath[50] = {'\0'};
    int iNo = 0;

    while((entry = readdir(dp)) != NULL)
    {
        if((strcmp(entry->d_name,"..") == 0) || (strcmp(entry->d_name,".") == 0))
        {
            continue;
        }

        iNo = snprintf(FilePath,50,"%s/%s",argv[1],argv[2]);

        if(strcmp(entry->d_name,argv[2]) == 0)
        {
            remove(FilePath);
            printf("File named '%s' is present in the %s is deleted\n",argv[2],argv[1]);
            break;
        }
    }
    if((entry = readdir(dp)) == NULL)
    {
        printf("File named '%s' isn't present in the %s directory\n",argv[2],argv[1]);
    }

    closedir(dp);

    return 0;
}