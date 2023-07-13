//Problem : Write a program which accept file name from user and open that file
//Usage : "./Name_of_Executable   Name_of_File"
#include<stdio.h>
#include<fcntl.h>

int	main(int argc,char *argv[])
{
	if(argc != 2)
	{
		printf("Invalid number of arguments\n");
		return -1;
	}

	int fd = 0;

	fd = open(argv[1],O_RDONLY);
	if(fd == -1)
	{
		printf("Unable to open the file\n");
		return -1;
	}
	else
	{
		printf("File is successfully opened with FD %d\n",fd);
	}

	return 0;
}