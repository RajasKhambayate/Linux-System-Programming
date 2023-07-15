//Problem : Write a program which accept file name and mode and check whether our process can access that file in accepted or not
//Usage : "./Name_of_Executable   Name_of_File   Mode_of_Opening_File"
#include<stdio.h>
#include<string.h>
#include<unistd.h>

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
        fd = access(argv[1],R_OK);
        if(fd == -1)
        {
            printf("File can't be accessed in read mode\n");
            return -1;
        }
        else if(fd == 0)
        {
            printf("File can be accessed in read mode\n");
        }
    }
	else if(strcmp(argv[2],"Write") == 0)
	{
        fd = access(argv[1],W_OK);
        if(fd == -1)
        {
            printf("File can't be accessed in write mode\n");
            return -1;
        }
        else if(fd == 0)
        {
            printf("File can be accessed in write mode\n");
        }
	}
	else if(strcmp(argv[2],"ReadandWrite") == 0)
	{
        fd = access(argv[1],R_OK & W_OK);
        if(fd == -1)
        {
            printf("File can't be accessed in read & write mode\n");
            return -1;
        }
        else if(fd == 0)
        {
            printf("File can be accessed in read & write mode\n");
        }
	}
    else
    {
        printf("Invalid Mode\n");
        return -1;
    }

    return 0;
}