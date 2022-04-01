#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>

int main (){
    int a = 5;
    
    pid_t pid;
    pid = fork();
    
    if(pid == 0){
        a = 10;
        printf("Children Process \n");
    }
    else {
        a = 20;
        printf("Parent Process \n");
    }
    
    printf("a = %d\n", a);
    return 0;
}
