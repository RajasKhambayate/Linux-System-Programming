//This program contains prototypes of methods which are used by Program2.c and Dll2.c
#include<unistd.h>
#include<fcntl.h>
#include<sys/stat.h>
#include<stdlib.h>
#include<stdio.h>
#include<string.h>
#include<dlfcn.h>

#define Block 1024

void CompareFiles(char[],char[]);