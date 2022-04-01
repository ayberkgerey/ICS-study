#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <signal.h>

void incomingSignal(int signum){
    printf("Incoming signal : %d\n",signum);
    exit(1);
}


int main(){
   /* int pid = fork();
    
    if(pid == 0){
        printf("Child Process %d %d \n",getpid(),getppid());
        kill(getpid(), SIGQUIT);
    }
    else{
        printf("Parent Process %d \n", getpid());
        kill(getpid(), SIGQUIT);
    }
    
    sleep(4); //It wont sleep because we kill the process
*/
    
    signal(SIGINT, incomingSignal); // function will work when you make control + c (interrupt)
    printf("pid = %d\n",getpid());
    
    while(1){
        printf("Hello world!\n");
        sleep(1);
    }
    
    return 0;
}
