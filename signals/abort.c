#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <signal.h>

void SIGNAL_HANDLER(int signum){
    if(signum == SIGALRM){
        printf("Inside of SIGALRM\n");
        alarm(2);
    }
    if(signum == SIGINT){ //Interrupt condition
        printf("Inside of SIGINT\n");
        exit(0); //ABORTS
    }
}

int main(){
    
    signal(SIGALRM, SIGNAL_HANDLER);
    signal(SIGINT, SIGNAL_HANDLER);
    alarm(2);
    int i;
    for(i = 0; ; i++){
        printf("Inside of Main %d\n",i);
        pause();
    }
    return 0;
}
