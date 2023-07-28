//This program contains methods such as ChkPerfect which are required by Program3.c
#include"Helper3.h"

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