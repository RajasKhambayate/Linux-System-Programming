//This program is used to create shared library and that library should be loaded at run time by other program .
#include"Helper1.h"

int main()
{
    int iNo1 = 0,iNo2 = 0;
    int iChoice = 1;
    int iRet = 0;

    void *ptr = NULL;
    void (*vFunc_ptr)();

    ptr = dlopen("library1.so",RTLD_LAZY);
    if(ptr == NULL)
    {
        printf("Unable to load library\n");
        return -1;
    }

    while(iChoice != 0)
    {
        printf("\n1 : For Addition of number\n");
        printf("2 : For subtracting of number\n");
        printf("3 : For multiplication of number\n");
        printf("4 : For division of numbers\n");
        printf("5 : For terminating application\n");

        printf("\nEnter your choice : \n");
        scanf("%d",&iChoice);

        if(iChoice == 1)
        {
            printf("Enter first number : \n");
            scanf("%d",&iNo1);

            printf("Enter Second number : \n");
            scanf("%d",&iNo2);

            vFunc_ptr = dlsym(ptr,"Addition");

            vFunc_ptr(iNo1,iNo2);
        }
        else if(iChoice == 2)
        {
            printf("Enter first number : \n");
            scanf("%d",&iNo1);

            printf("Enter Second number : \n");
            scanf("%d",&iNo2);

            vFunc_ptr = dlsym(ptr,"Substraction");

            vFunc_ptr(iNo1,iNo2);
        }
        else if(iChoice == 3)
        {
            printf("Enter first number : \n");
            scanf("%d",&iNo1);

            printf("Enter Second number : \n");
            scanf("%d",&iNo2);

            vFunc_ptr = dlsym(ptr,"Multiplication");

            vFunc_ptr(iNo1,iNo2);
        }
        else if(iChoice == 4)
        {
            printf("Enter numerator number : \n");
            scanf("%d",&iNo1);

            printf("Enter denominator number : \n");
            scanf("%d",&iNo2);

            vFunc_ptr = dlsym(ptr,"Division");

            vFunc_ptr(iNo1,iNo2);
        }
        else if(iChoice == 5)
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
To make Dll1.o(convert .c to .o)             --------------------- gcc -c -fPIC Dll1.c
To make library1.so file(Making .so file)    --------------------- gcc -shared -o library1.so Dll1.o
To run Program1.c                            --------------------- gcc Program1.c library1.so -Wl,-rpath=$(pwd) -o myexe
To run myexe                                 --------------------- ./myexe
*/