#include <stdio.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

//wait(NULL) will block parent process until any of its children has finished.

int main(){
    int id = fork();
    int n;
    
    if(id == 0)
        n=1;
    else
        n=6;
    
    wait(NULL);
    
    int i;
    for(i = n; i < n+5; i++){
        printf("%d",i);
        fflush(stdout);
    }
    
    if(id != 0)
        printf("\n");
    
    return 0;
}
