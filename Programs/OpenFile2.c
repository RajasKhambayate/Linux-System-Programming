//This program opens a file in write mode only
#include<stdio.h>
#include<fcntl.h>

int	main(int argc,char *argv[])
{
	int fd = 0;

	if(argc != 2)
	{
		printf("Invalid number of arguments\n");
		return -1;
	}

	fd = open(argv[1],O_WRONLY);
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