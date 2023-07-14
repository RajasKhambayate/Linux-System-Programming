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
/*
0777
0  -  Octal

////////////User////////////////
Owner -- 4  +  2  +  1 = 7
Group -- 4  +  2  +  1 = 7
Other -- 4  +  2  +  1 = 7

/////////Operations//////////
Read         4
Wrie         2
Execute      1
*/