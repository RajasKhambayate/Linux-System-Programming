//This program creates two processes , process_1 count number of capital characters from File1 file and process_2 count number of capital characters from File2 file .
//Usage : "./Executable_name   File_Name_1   File_Name_2"
#include<stdio.h>
#include<unistd.h>
#include<stdlib.h>
#include<fcntl.h>
#include<string.h>

#define Block 1024

int main(int argc,char *argv[])
{
    if(argc != 3)
    {
        printf("Invalid arguments\n");
        return -1;
    }

    int Child_Pid1 = 0,Child_Pid2 = 0;
    int fd = 0;
    int iRet = 0;
    int iCnt = 0;
    int iCapital = 0;

    char Buffer[Block] = {'\0'};


    Child_Pid1 = fork();

    if((Child_Pid1 == 0))
    {
        fd = open(argv[1],O_RDONLY);
        if(fd == -1)
        {
            printf("Unable to open first file\n");
            return -1;
        }

        while((iRet = read(fd,Buffer,Block)) != 0)
        {
            for(iCnt = 0;iCnt < iRet;iCnt++)
            {
                if((Buffer[iCnt] >= 'A') && (Buffer[iCnt] <= 'Z'))
                {
                    iCapital++;
                }
            }
        }

        printf("Capital letters in %s are : %d\n",argv[1],iCapital);
        Child_Pid2 = 1;
    }

    if(Child_Pid1 > 0)
    {
        Child_Pid2 = fork();
    }

    if(Child_Pid2 == 0)
    {
        fd = open(argv[2],O_RDONLY);
        if(fd == -1)
        {
            printf("Unable to open Second file\n");
            return -1;
        }

        while((iRet = read(fd,Buffer,Block)) != 0)
        {
            for(iCnt = 0;iCnt < iRet;iCnt++)
            {
                if((Buffer[iCnt] >= 'A') && (Buffer[iCnt] <= 'Z'))
                {
                    iCapital++;
                }
            }
        }

        printf("Capital letters in %s are : %d\n",argv[2],iCapital);
        Child_Pid1 = 1;
    }

    return 0;
}