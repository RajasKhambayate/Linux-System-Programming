//This program is used to create a shared libraries and that library should be loaded at run time by other program , that shared library should load another shared library.
#include"Helper4.h"

int main(int argc,char *argv[])
{
    void *ptr = NULL;
    void (*vFunc_ptr)();

    ptr = dlopen("library4_1.so",RTLD_LAZY);
    if(ptr == NULL)
    {
        printf("Unable to load libraries\n");
        return -1;
    }

    int iNo1 = 0;

    printf("Enter number to check Factorial : \n");
    scanf("%d",&iNo1);
    vFunc_ptr = dlsym(ptr,"Load_library");
    vFunc_ptr(iNo1);

    return 0;
}
/*
To make first Dll4_2.o(convert .c to .o)            --------------------- gcc -c -fPIC Dll4_2.c
To make first library4_2.so file(Making .so file)   --------------------- gcc -shared -o library4_1.so Dll4_1.o

To make Second Dll4_1.o(convert .c to .o)           --------------------- gcc -c -fPIC Dll4_1.c
To make Second library4_1.so file(Making .so file)  --------------------- gcc -shared -o library4_2.so Dll4_2.o

To run Program4.c                                   --------------------- gcc Program4.c library4_1.so library4_2.so -Wl,-rpath=$(pwd) -o myexe
To run myexe                                        --------------------- ./myexe
*/