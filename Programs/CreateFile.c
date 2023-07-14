//This program accepts filename from user and creates it
//Usage : "./Name_of_Executable   Name_of_File"
#include<stdio.h>
#include<fcntl.h>

int main(int argc, char *argv[])
{
    if(argc != 2)
    {
        printf("Insufficient arguments\n");
        return -1;
    }

    int fd = 0;

    fd = open(argv[1],0777);
    if(fd == -1)
    {
        printf("Unable to create the file\n");
        return -1;
    }
    else
    {
        printf("File created successfully with fd : %d\n",fd);
    }

    close(fd);

    return 0;
}