//This file is control point to StaticLib(Problem_On_Number).c & StaticLib(Problem_On_Number).h files .
#include<stdio.h>
#include"StaticLib(Problem_On_Number).h"

int main()
{
    int iNo = 0;
    int iChoice = 1;
    int iRet = 0;

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

            ChkEven(iNo);
        }
        else if(iChoice == 2)
        {
            printf("Enter number for checking odd : \n");
            scanf("%d",&iNo);

            ChkOdd(iNo);
        }
        else if(iChoice == 3)
        {
            printf("Enter number for checking prime : \n");
            scanf("%d",&iNo);

            ChkPrime(iNo);
        }
        else if(iChoice == 4)
        {
            printf("Enter number to display factors : \n");
            scanf("%d",&iNo);

            DisplayFactors(iNo);
        }
        else if(iChoice == 5)
        {
            printf("Enter number for checking perfect : \n");
            scanf("%d",&iNo);

            ChkPerfect(iNo);
        }
        else if(iChoice == 6)
        {
            printf("Enter number to count factors : \n");
            scanf("%d",&iNo);

            CountFactors(iNo);
        }
        else if(iChoice == 7)
        {
            printf("Thanks for using this program\n");
            break;
        }
        else
        {
            printf("Inavlid choice\n");
            continue;
        }
    }

    return 0;
}
/*
To make sharedfile.o(convert .c to .a)                      --------------------- gcc -c StaticLib(Problem_On_Number).c -o StaticLib(Problem_On_Number).o
To run client.c                                             --------------------- gcc -static Client.c -o myexe StaticLib(Problem_On_Number).o
To run myexe                                                --------------------- ./myexe
*/