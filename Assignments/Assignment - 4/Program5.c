//Problem : Write a program which accepts file name and position from user and read 20 bytes from that position
//Usage : "./Name_of_Executable   Name_of_File   Position"
#include<stdio.h>
#include<fcntl.h>
#include<unistd.h>
#include<stdlib.h>
#include<sys/stat.h>

int main(int argc,char *argv[])
{
    if(argc != 3)
    {
        printf("Invalid arguments\n");
        return -1;
    }

    struct stat Stat_obj;
    stat(argv[1],&Stat_obj);

    if(Stat_obj.st_size < atoi(argv[2]))
    {
        printf("Offset is greater than file size\n");
        return -1;
    }

    int fd = 0;

    fd = open(argv[1],O_RDONLY);
    if(fd == -1)
    {
        printf("Unable to open file\n");
    }

    char Buffer[20] = {'\0'};

    lseek(fd,atoi(argv[2]),SEEK_CUR);

    read(fd,Buffer,20);
    write(1,Buffer,20);

    printf("\n");

    return 0;
}