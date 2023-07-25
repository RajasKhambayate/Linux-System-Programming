//This file is control point to Dll(Problem_On_Number).c & Dll(Problem_On_Number).h files .
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<dlfcn.h>
#include"Dll_Number.h"

int main()
{
    int iNo = 0;
    int iChoice = 1;
    int iRet = 0;

    void *ptr = NULL;
    void (*vFunc_ptr)();

    ptr = dlopen("library.so",RTLD_LAZY);
    if(ptr == NULL)
    {
        printf("Unable to load library\n");
        return -1;
    }

    while(iChoice != 0)
    {
        printf("\n1 : For checking even number\n");
        printf("2 : For checking odd number\n");
        printf("3 : For checking prime number\n");
        printf("4 : For displaying factors\n");
        printf("5 : For checking perfect number\n");
        printf("6 : For counting factors\n");
        printf("7 : For terminating application\n");

        printf("\nEnter your choice : \n");
        scanf("%d",&iChoice);

        if(iChoice == 1)
        {
            printf("Enter number for checking even : \n");
            scanf("%d",&iNo);

            vFunc_ptr = dlsym(ptr,"ChkEven");

            vFunc_ptr(iNo);
        }
        else if(iChoice == 2)
        {
            printf("Enter number for checking odd : \n");
            scanf("%d",&iNo);

            vFunc_ptr = dlsym(ptr,"ChkOdd");

            vFunc_ptr(iNo);
        }
        else if(iChoice == 3)
        {
            printf("Enter number for checking prime : \n");
            scanf("%d",&iNo);

            vFunc_ptr = dlsym(ptr,"ChkPrime");

            vFunc_ptr(iNo);
        }
        else if(iChoice == 4)
        {
            printf("Enter number to display factors : \n");
            scanf("%d",&iNo);

            vFunc_ptr = dlsym(ptr,"DisplayFactors");

            vFunc_ptr(iNo);
        }
        else if(iChoice == 5)
        {
            printf("Enter number for checking perfect : \n");
            scanf("%d",&iNo);

            vFunc_ptr = dlsym(ptr,"ChkPerfect");

            vFunc_ptr(iNo);
        }
        else if(iChoice == 6)
        {
            printf("Enter number to count factors : \n");
            scanf("%d",&iNo);

            vFunc_ptr = dlsym(ptr,"CountFactors");

            vFunc_ptr(iNo);
        }
        else if(iChoice == 7)
        {
            printf("Thanks for using this program\n");
            break;
        }
        else
        {
            printf("Invalid iChoice\n");
            continue;
        }
    }

    return 0;
}
/*
To make sharedfile.o(convert .c to .a)                      --------------------- gcc -c number.c -o number.o
To make library.so file(Making .so file)                    --------------------- gcc -shared -o library.so number.o
To run client.c                                             --------------------- gcc user.c library.so -Wl,-rpath=$(pwd) -o myexe
To run myexe                                                --------------------- ./myexe
*/