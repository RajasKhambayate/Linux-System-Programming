//Problem : Write a program which accept file name and mode and check whether our process can access that file in accepted or not
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


	if(strcmp(argv[2],"Read") == 0)
	{
        fd = open(argv[1],O_RDONLY);
        if(fd == -1)
        {
            printf("Unable to open the file\n");
            return -1;
        }
        else
        {
            printf("File is successfully opened with FD : %d in read mode\n",fd);
        }
    
    }
	else if(strcmp(argv[2],"Write") == 0)
	{
        fd = open(argv[1],O_WRONLY);
        if(fd == -1)
        {
            printf("Unable to open the file\n");
            return -1;
        }
        else
        {
            printf("File is successfully opened with FD : %d in write mode\n",fd);
        }
	}
	else if(strcmp(argv[2],"ReadandWrite") == 0)
	{
        fd = open(argv[1],O_RDWR);
        if(fd == -1)
        {
            printf("Unable to open the file\n");
            return -1;
        }
        else
        {
            printf("File is successfully opened with FD : %d in read and write mode\n",fd);
        }
	}
    else
    {
        printf("Invalid Mode\n");
        return -1;
    }

    return 0;
}