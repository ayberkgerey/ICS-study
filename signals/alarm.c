#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <signal.h>

void raisedAlarm(int signum){
    printf("Alarm Working!\n");
    exit(0);
}

int main(){
    
    alarm(5);
    signal(SIGALRM, raisedAlarm);
    
    while(1){
        printf("Hello World!\n");
        sleep(1);
    }
    
    return 0;
}
