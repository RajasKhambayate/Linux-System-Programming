//This program contains methods such as Factorial which are used by Program4.c
#include"Helper4.h"

void Factorial(int iValue)
{
    int iFactorial = 1;

    for(int iCnt = 1;iCnt <= iValue;iCnt++)
    {
        iFactorial = iFactorial * iCnt;
    }

    printf("Factorial of %d is : %d\n",iValue,iFactorial);
}