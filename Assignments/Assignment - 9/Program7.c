//This program is used to print home directory and login user name .
//Usage : "./Executable_name"
#include<stdio.h>
#include<unistd.h>
#include<string.h>

extern char **environ;

int main()
{
    char **Environment = environ;
    int iRet = 0;

    for(;*Environment != NULL;Environment++)
    {
        if((iRet = strncmp(*Environment,"LOGNAME",7) == 0) || (iRet = strncmp(*Environment,"HOME",4) == 0))
        {
            printf("%s\n",*Environment);
        }
    }

    return 0;
}