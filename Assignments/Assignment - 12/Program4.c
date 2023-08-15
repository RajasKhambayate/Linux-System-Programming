//Write a program which map any file in memory and read the data from that mapped file .
//Usage : "./Executable_name   File_Path"
#include <stdio.h>
#include <sys/mman.h>
#include <stdlib.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>

int main(int argc, char *argv[]){

    if(argc != 2)
    {
        printf("Invalid arguments\n");
        return -1;
    }

    int fd = open(argv[1],O_RDWR);
    if(fd == -1)
    {
        printf("Unable to open file\n");
        return -1;
    }

    struct stat stat_obj;

    fstat(fd,&stat_obj);

    char *ptr = mmap(NULL,stat_obj.st_size,PROT_READ | PROT_WRITE,MAP_SHARED,fd,0);
    if(ptr == MAP_FAILED)
    {
        printf("Mapping Failed\n");
        return 1;
    }
    close(fd);

    write(1,ptr,stat_obj.st_size);

    printf("\n");

    return 0;
}