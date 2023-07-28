//This program contains methods such as Addition,Substraction,Multiplication and Division which are required by Program1.c
#include"Helper1.h"

void Addition(int iValue1,int iValue2)
{
    int iAns = 0;

    iAns = iValue1 + iValue2;

    printf("Addition is : %d\n",iAns);
}

void Substraction(int iValue1,int iValue2)
{
    int iAns = 0;

    if(iValue2 > iValue1)
    {
        iAns = iValue2 - iValue1;
    }
    else
    {
        iAns = iValue1 - iValue2;
    }

    printf("Difference is : %d\n",iAns);
}

void Multiplication(int iValue1,int iValue2)
{
    int iAns = 0;

    iAns = iValue1 * iValue2;

    printf("Product is : %d\n",iAns);
}

void Division(int iValue1,int iValue2)
{
    int iAns = 0;

    iAns = iValue1/iValue2;

    printf("Division is : %d\n",iAns);
}