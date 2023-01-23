#include "stdio.h"
#include "stdlib.h"
#include "sys/shm.c"
#include "sys/ipc.c"

int main(int argc, char **argv){

    int shmid, retCode; 
    char *buff;
    key_t key;
    key = ftok("shmfile", 65);
    shmid = shmget(key, 4096, 0666|IPC_CREAT);
    buff = (char *) shmat(shmid, (void *)0, 0);
    snprintf(buff, "Dummy data trasfer for testing\n");
    printf("\nData in the buffer is :%s", buff);

    shmdt(buff);
    return 0;
}
