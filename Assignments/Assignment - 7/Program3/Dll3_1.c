//This program contains methods such as ChkPrime which are required by Program3.c
#include"Helper3.h"

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