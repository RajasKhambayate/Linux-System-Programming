//Write a program which perfroms IPC using concept of message queue.
//Server for Message queue
//Usage : "./Executable_name_1"
#include<stdlib.h>
#include<stdio.h>
#include<string.h>
#include<unistd.h>
#include<sys/msg.h>

#define MAX_TEXT 1024

struct my_msg_st
{
    int my_msg_type;
    char some_text[MAX_TEXT];
};

int main()
{
    int iCnt = 0,msgid;

    char Buffer[BUFSIZ];

    struct my_msg_st some_data;

    msgid = msgget((key_t)1234,0666 | IPC_CREAT);
    if (msgid == -1)
    {
        printf("failed to create message queue");
        return -1;
    }

    while(iCnt != 1)
    {
        printf("Enter Some Text: ");
        fgets(Buffer,BUFSIZ,stdin);

        some_data.my_msg_type = 1;
        strcpy(some_data.some_text,Buffer);

        if(msgsnd(msgid,(void *)&some_data,MAX_TEXT,0) == -1)
        {
            printf("msgsnd failed\n");
            return -1;
        }

        if(strncmp(Buffer,"Bye",3) == 0)
        {
            iCnt = 1;
        }
    }

    return 0;
}