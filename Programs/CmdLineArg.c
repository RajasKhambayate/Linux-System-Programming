//This program shows the use of command line arguments
#include<stdio.h>

int	main(int argc,char *argv[])
{
	printf("argc = %d\n",argc);
	printf("Name of application : %s\n",argv[0]);

	if(argc == 1)
	{
		printf("Please enter your first name as command line argument\n");
		return -1;
	}
	else
	{
		printf("Welcome to Marvellous : %s\n", argv[1]);//if we mention %s it will display filename whereas when we we mwention %d it will display address of argv[0]
		return 0;
	}
}