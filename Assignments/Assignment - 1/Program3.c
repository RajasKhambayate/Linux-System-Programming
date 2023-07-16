//Problem : Write a program which accept file name and mode and check whether our process can access that file in accepted or not
//Usage : "./Name_of_Executable   Name_of_File   Mode_of_Opening_File"
#include<stdio.h>
#include<fcntl.h>
#include<unistd.h>
#include<string.h>

int main(int argc , char *argv[])
{
    if(argc != 3)
    {
        printf("Insufficient Arguments\n");
        return -1;
    }

    int mode = 0;

    if(stricmp(argv[2],"read") == 0)
    {
        mode = R_OK;
    }
    if(stricmp(argv[2],"write") == 0)
    {
        mode = W_OK;
    }
    if(stricmp(argv[2],"execute") == 0)
    {
        mode = X_OK;
    }

    if(access(argv[1],mode) < 0)
    {
        printf("Unable to access %s file in %s mode\n",argv[1],argv[2]);
    }
    else
    {
        printf("You can access %s file in %s mode\n",argv[1],argv[2]);
    }

    return 0;
}