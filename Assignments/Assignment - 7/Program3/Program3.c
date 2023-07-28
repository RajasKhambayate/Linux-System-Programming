//This program is used to create 2 shared libraries and that libraries should be loaded at run time by other program .
#include"Helper3.h"

int main(int argc,char *argv[])
{
    void *ptr1 = NULL;
    void *ptr2 = NULL;
    void (*vFunc_ptr)();

    ptr1 = dlopen("library3_1.so",RTLD_LAZY);
    ptr2 = dlopen("library3_2.so",RTLD_LAZY);
    if((ptr1 == NULL) || (ptr2 == NULL))
    {
        printf("Unable to load libraries\n");
        return -1;
    }

    int iNo1 = 0;

    printf("Enter number to check prime : \n");
    scanf("%d",&iNo1);
    vFunc_ptr = dlsym(ptr1,"ChkPrime");
    vFunc_ptr(iNo1);

    printf("Enter number to check perfect : \n");
    scanf("%d",&iNo1);
    vFunc_ptr = dlsym(ptr2,"ChkPerfect");
    vFunc_ptr(iNo1);

    return 0;
}
/*
To make first Dll3_1.o(convert .c to .o)          --------------------- gcc -c -fPIC Dll3_1.c
To make first library1.so file(Making .so file)   --------------------- gcc -shared -o library3_1.so Dll3_1.o

To make Second Dll3_2.o(convert .c to .o)         --------------------- gcc -c -fPIC Dll3_2.c
To make Second library2.so file(Making .so file)  --------------------- gcc -shared -o library3_2.so Dll3_2.o

To run Program3.c                                 --------------------- gcc Program3.c library3_1.so library3_2.so -Wl,-rpath=$(pwd) -o myexe
To run myexe                                      --------------------- ./myexe
*/