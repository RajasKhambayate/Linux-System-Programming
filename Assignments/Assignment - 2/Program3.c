//Problem : Write a program which accept directory name from user and print all file names from that directory
//Usage : "./Name_of_Executable   Name_of_Directory"
#include<stdio.h>
#include<dirent.h>

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

    printf("-------------------------------------------------------------------------------------------------\n");
    printf("Entries from the directory file are : \n");
    printf("-------------------------------------------------------------------------------------------------\n");
    printf("Filenames :\n\n");
    while((entry = readdir(dp)) != NULL)
    {
        printf("%s\n",entry->d_name);
    }
    printf("-------------------------------------------------------------------------------------------------\n");

    closedir(dp);

    return 0;
}