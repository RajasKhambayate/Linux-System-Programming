//This program is used to create shared library and that library should be loaded at run time by other program .
#include"Helper2.h"

int main(int argc,char *argv[])
{
    if(argc != 3)
    {
        printf("Insufficient arguments\n");
        return -1;
    }

    void *ptr = NULL;
    void (*vFunc_ptr)();

    ptr = dlopen("library2.so",RTLD_LAZY);
    if(ptr == NULL)
    {
        printf("Unable to load library\n");
        return -1;
    }

    vFunc_ptr = dlsym(ptr,"CompareFiles");
    vFunc_ptr(argv[1],argv[2]);

    return 0;
}
/*
To make Dll1.o(convert .c to .o)             --------------------- gcc -c -fPIC Dll2.c
To make library1.so file(Making .so file)    --------------------- gcc -shared -o library2.so Dll2.o
To run Program1.c                            --------------------- gcc Program2.c library2.so -Wl,-rpath=$(pwd) -o myexe
To run myexe                                 --------------------- ./myexe
*/