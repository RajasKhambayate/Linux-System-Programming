//Problem : Write a program which accept file name and mode from user and then open that file in specified mode
//Usage : "./Name_of_Executable   Name_of_File   Mode_of_Opening_File"
#include<stdio.h>
#include<fcntl.h>
#include<string.h>

int	main(int argc,char *argv[])
{
	if(argc != 3)
	{
		printf("Invalid number of arguments\n");
		return -1;
	}

	int fd = 0;
	int Mode = 0;

	if(strcmp(argv[2],"Read") == 0)
	{
		Mode = O_RDONLY;
	}
	else if(strcmp(argv[2],"Write") == 0)
	{
		Mode = O_WRONLY;
	}
	else if(strcmp(argv[2],"Read&Write") == 0)
	{
		Mode = O_RDWR;
	}
    else
    {
        printf("Invalid Mode\n");
        return -1;
    }

	fd = open(argv[1],Mode);
	if(fd == -1)
	{
		printf("Unable to open the file\n");
		return -1;
	}
	else
	{
		printf("File is successfully opened with FD : %d\n",fd);
	}

	return 0;
}