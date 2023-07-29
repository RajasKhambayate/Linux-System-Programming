//This program display environment of our process .
//Usage : "./Executable_name"
#include<stdio.h>
#include<unistd.h>

extern char **environ;

int main()
{
    char **Environment = environ;

    printf("Environment of running process is : \n");

    for(;*Environment != NULL;Environment++)
    {
        printf("%s\n\n\n",*Environment);
    }

    return 0;
}