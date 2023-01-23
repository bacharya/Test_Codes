#include "stdio.h"
#include "stdlib.h"
#include "string.h"
#include "errno.h"
#include "unistd.h"
#include "sys/types.h"
#include "sys/socket.h"
#include "sys/wait.h"


int main(){

    int sv[2], len1,len2, counter1=0,counter2=0;
    char buff[100] = {0};
    char *data1 = "This is test data to be sent(PARENT)";
    char *data2 = "This is test data to be sent(CHILD)";
    len1 = strlen(data1)+1;
    len2 = strlen(data2)+1;

    if(socketpair(AF_UNIX, SOCK_STREAM, 0, sv) == -1){
    
        printf("\nFailed to create socket-pair");
        exit(1);
    }
    if(!fork()){
        /*child*/
        for(;;){
            counter2++;
            read(sv[1], buff, len1);
            printf("CHILD: data read from buffer is:\n %s\n",buff);
            memset(buff, 0, len1);
            strncpy(buff, data2, len2);
            write(sv[1], buff, len2);
            printf("CHILD: data write to buffer is:\n %s\n",buff);
            printf("CHILD: rw-count: %d\n\n",counter2);
            sleep(1);
        }
    } else {
        /*Parent*/
        for(;;){
            counter1++;
            memset(buff, 0, len2);
            strncpy(buff, data1, len1);
            write(sv[0], buff, len1);
            printf("PARENT: data write to buffer is:\n %s\n",buff);
            read(sv[0], buff, len2);
            printf("PARENT: data read from buffer is:\n %s\n",buff);
            printf("PARENT: rw-count: %d\n\n",counter1);
            wait(NULL);
            sleep(1);
        }
    }
}
