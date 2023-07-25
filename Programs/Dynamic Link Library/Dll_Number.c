//This file contains the methods of topic "Problem on number" .
#include<stdio.h>
#include"Dll(Problem_On_Number).h"

void ChkEven(int iNo)
{
    if((iNo % 2) == 0)
    {
        printf("%d is a even number\n",iNo);
    }
    else
    {
        printf("%d isn't a even number\n",iNo);
    }
}

void ChkOdd(int iNo)
{
    if((iNo % 2) != 0)
    {
        printf("%d is a odd number\n",iNo);
    }
    else
    {
        printf("%d isn't a odd number\n",iNo);
    }
}

void ChkPrime(int iNo)
{
    int iCnt = 0;

    for(iCnt = 2; iCnt <= (iNo/2); iCnt++)
    {
        if(iNo % iCnt == 0)
        {
            printf("%d isn't a prime number\n",iNo);
        }
    }

    printf("%d is a prime number\n",iNo);
}

void DisplayFactors(int iNo)
{
    int iCnt = 0;

    printf("Factors of %d are : \n",iNo);

    for(iCnt = 1; iCnt <= iNo/2; iCnt++)
    {
        if((iNo % iCnt) == 0)
        {
            printf("%d\n",iCnt);
        }
    }
}

void ChkPerfect(int iNo)
{
    int iCnt = 0;
    int iSum = 0;

    if(iNo < 0)
    {
        iNo = -iNo;
    }
    for(iCnt = (iNo/2);((iCnt >= 1) && (iSum <= iNo));iCnt--)
    {
        if((iNo % iCnt) == 0)
        {
            iSum =  iSum + iCnt;
        }
    }

    if(iSum == iNo)
    {
        printf("%d is a perfect number\n",iNo);
    }
    else
    {
        printf("%d isn't a perfect number\n",iNo);
    }
}

void CountFactors(int iNo)
{
    int iCnt = 0;
    int iFactors = 0;

    for(iCnt = 1;iCnt <= iNo/2;iCnt++)
    {
        if((iNo % iCnt) == 0)
        {
            iFactors++;
        }
    }

    printf("%d has %d factors\n",iNo,iFactors);
}