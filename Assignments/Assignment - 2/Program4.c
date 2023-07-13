//Problem : Write a program which accept directory name from user and print all file names and its types from that directory
//Usage : "./Name_of_Executable   Name_of_Directory"
#include<stdio.h>
#include<sys/stat.h>
#include<dirent.h>

int main(int argc,char *argv[])
{
    DIR *dp = NULL;
    struct dirent * entry = NULL;

    if(argc != 2)
    {
        printf("Insufficient arguments\n");
        return -1;
    }

    dp = opendir(argv[1]);
    if(dp == NULL)
    {
        printf("Unable to open directory\n");
        return -1;
    }

    struct stat Stat_obj;

    printf("-------------------------------------------------------------------------------------------------\n");
    printf("Entries from the directory file are : \n");
    printf("-------------------------------------------------------------------------------------------------\n");
    printf("\t   Filenames : File Type\n\n");
    while((entry = readdir(dp)) != NULL)
    {
        stat(entry->d_name,&Stat_obj);

        if(S_ISREG(Stat_obj.st_mode))
        {
            printf("%20s : Regular File\n",entry->d_name);
        }
        else if(S_ISDIR(Stat_obj.st_mode))
        {
            printf("%20s : Directory File\n",entry->d_name);
        }
        else if(S_ISLNK(Stat_obj.st_mode))
        {
            printf("%20s : Symbolic Link File\n",entry->d_name);
        }
    }
    printf("-------------------------------------------------------------------------------------------------\n");

    closedir(dp);

    return 0;
}