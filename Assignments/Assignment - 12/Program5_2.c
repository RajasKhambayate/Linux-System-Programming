//Write a program which perfroms IPC using concept of message queue.
//Client for Message queue
//Usage : "./Executable_name_2"
#include<stdlib.h>
#include<stdio.h>
#include<string.h>
#include<errno.h>
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
    int iCnt = 0,msgid = 0,msg_to_receive = 0;

    struct my_msg_st some_data;

    msgid = msgget((key_t)1234,0666 | IPC_CREAT);

    while(iCnt != 1)
    {
        msgrcv(msgid, (void*)&some_data,BUFSIZ,msg_to_receive,0);

        printf("You wrote: %s",some_data.some_text);

        if(strncmp(some_data.some_text,"Bye",3) == 0)
        {
            iCnt = 1;
        }
    }

    return 0;
}