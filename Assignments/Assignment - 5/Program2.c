//Problem : Write a program which accept file name from user which contains information of student , we have to read all contents of the file
//Usage : "./Name_of_Executable   Name_of_File"
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
    if(argc != 2)
    {
        printf("Invalid arguments\n");
        return -1;
    }

    struct Student Student_obj;

    int fd = 0;

    fd = open(argv[1],O_RDONLY);
    if(fd == -1)
    {
        printf("Unable to open the file\n");
        return -1;
    }

    read(fd,&Student_obj,sizeof(Student_obj));

    printf("Name        : %s\n",Student_obj.Name);
    printf("Roll number : %d\n",Student_obj.Rollno);
    printf("Marks       : %f\n",Student_obj.Marks);
    printf("Age         : %d\n",Student_obj.Age);
    printf("City        : %s\n",Student_obj.City);

    close(fd);

    return 0;
}