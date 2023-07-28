//This program that creates static library which contains file name from user and which displays the information of that file .
//Usage = "./Executable_File   FileName"
#include"Helper5.h"

int main()
{
    char File_Name[50] = {'\0'};

    printf("Enter the file name : \n");
    scanf("%s",&File_Name);

    Stat_File(File_Name);

    return 0;
}
/*
To make StatFile.o(convert .c to .o)                      --------------------- gcc -c StaticFile.c -o StaticFile.o
To run Program5.c                                         --------------------- gcc -static Program5.c -o myexe StaticFile.o
To run myexe                                              --------------------- ./myexe
*/