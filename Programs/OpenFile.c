//This program opens a file in read and write mode
//Usage : "./Name_of_Executable   Name_of_File"
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

	fd = open(argv[1],O_RDWR);
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
/*
O_RDWR   - Read and Write mode .
O_RDONLY - Read mode .
O_WRONLY - Write mode .
O_CREAT  - Create mode .
*/
