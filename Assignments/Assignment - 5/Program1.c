//Problem : Write a program which writes structure in file .Structure should contains information of student
//Usage : "./Name_of_Executable   Name_of_File   Name_of_Student   Rollno_of_Student   Marks_of_Student   Age_of_Student   City_of_Student"
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<unistd.h>
#include<fcntl.h>

#pragma pack(1)

struct Student
{
    char Name[20];
    int Rollno;
    float Marks;
    int Age;
    char City[10];
};

int main(int argc, char *argv[])
{
    if(argc != 7)
    {
        printf("Invalid arguments\n");
        return -1;
    }

    struct Student Student_obj;

    int fd = 0;

    fd = creat(argv[1],0777);
    if(fd == -1)
    {
        printf("Unable to create the file\n");
        return -1;
    }

    strcpy(Student_obj.Name,argv[2]);
    Student_obj.Rollno = atoi(argv[3]);
    Student_obj.Marks = atof(argv[4]);
    Student_obj.Age = atoi(argv[5]);
    strcpy(Student_obj.City,argv[6]);

    write(fd,&Student_obj,sizeof(Student_obj));

    printf("Information filled successfully in : %s\n",argv[1]);

    return 0;
}