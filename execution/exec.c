#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

int main(int argc, char *argv[]){
    
    printf("exec.c pid = %d \n",getpid());
    char *args[] = {"t1","t2","t3",NULL};
    execv("./exec2",args);
    printf("We are in exec. \n");
    
    return 0;
}
