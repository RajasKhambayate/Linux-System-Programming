//Problem : Write a program which is used to demonstrate I/O redirection
//Usage : "./Name_of_Executable   Name_of_Directory"
#include<stdio.h>

int main(int argc,char *argv[])
{
    int iNo1 = 0,iNo2 = 0;
    int iAns = 0;

    printf("Enter First Number : \n");//Output will be put into Output1.txt
    scanf("%d",&iNo1);//Input will be taken from Input1.txt

    printf("Enter Second Number : \n");//Output will be put into Output1.txt
    scanf("%d",&iNo2);//Input will be taken from Input1.txt

    iAns = iNo1 + iNo2;
    printf("Addition is : %d\n",iAns);//Output will be put into Output1.txt

    return 0;
}
/*

How to run this program :: gcc Program1.c -o myexe
                        :: ./myexe < Input1.txt > Output1.txt

*/