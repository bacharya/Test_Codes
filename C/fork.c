#include "stdio.h"
#include "stdlib.h"
#include "time.h"
#include "limits.h"
#include "unistd.h"
#include "sys/wait.h"

int main(){

    unsigned int i=0;
    int pid, status;
    time_t cur_time1, cur_time2;

    cur_time1 = time(NULL);
    printf("\nParent(%d) Started at: %ld", getpid(),cur_time1);
    while(i<INT_MAX){
        i++;
    }
    pid = fork();
    if(pid == 0){
        /*Child process*/
        i=0;
        cur_time1 = time(NULL);
        printf("\nChild(%d): Started at: %ld", getpid(), cur_time1);
        while(i<INT_MAX){
            i++;
        }
        cur_time2 = time(NULL);
        printf("\nChild(%d): Ended at: %ld, difference:%ld\n", getpid(), cur_time2, (cur_time2-cur_time1));
    } else {
        waitpid(pid, &status, 0);
        if(WIFEXITED(status)){
            printf("\nParent(%d): Child process terminated normally", getpid());
        } else {
            printf("\nParent(%d): Child process terminated abnormally!!!!!",getpid());
        }

        cur_time2 = time(NULL);
        printf("\nParent(%d): Ended at: %ld, difference:%ld\n", getpid(), cur_time2, (cur_time1-cur_time2));
    }

    return 0;

}
