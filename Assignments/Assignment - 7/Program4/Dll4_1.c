//This program loads another shared library named Dll4_2.c
#include"Helper4.h"

void Load_library(int iNo2)
{
    void *ptr2 = NULL;
    void (*vFunc_ptr2)();

    ptr2 = dlopen("library4_2.so",RTLD_LAZY);
    if(ptr2 == NULL)
    {
        printf("Unable to load libraries\n");
        return;
    }

    vFunc_ptr2 = dlsym(ptr2,"Factorial");
    vFunc_ptr2(iNo2);
}