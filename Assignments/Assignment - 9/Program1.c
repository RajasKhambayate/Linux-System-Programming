//This program will create a child process which will write all file name from desktop in Desktop_Files.txt
//Usage : "./Executable_Name"
#include<stdio.h>
#include<unistd.h>
#include<fcntl.h>
#include<dirent.h>
#include<string.h>
#include<sys/stat.h>

int main(int argc,char *argv[])
{
    int fd = 0,Child_Pid = 0;
    char FileName[100] = {'\0'};

    struct stat Stat_obj;

    DIR *dp = NULL;
    struct dirent *entry = NULL;

    Child_Pid = fork();
    if(Child_Pid == -1)
    {
        printf("Unable to create child process\n");
        return -1;
    }

    if(Child_Pid == 0)
    {
        int fd = 0,iNo = 0;

        dp = opendir("/home/shreyk/Desktop");
        if(dp == NULL)
        {
            printf("Unable to open directory\n");
            return -1;
        }

        fd = creat("Desktop_Files.txt",0777);
        if(fd == -1)
        {
            printf("Unable to create a file\n");
            return -1;
        }

        iNo = 0;

        while((entry = readdir(dp)) != NULL)
        {
            if(((strcmp(entry->d_name,"..")) == 0) || ((strcmp(entry->d_name,".")) == 0))
            {
                continue;
            }

            iNo = snprintf(FileName,100,"/home/shreyk/Desktop/%s",entry->d_name);

            stat(FileName,&Stat_obj);

            strcat(entry->d_name,"\n");

            if(S_ISREG(Stat_obj.st_mode))
            {
                write(fd,entry->d_name,strlen(entry->d_name));
            }
        }
    }

    return 0;
}