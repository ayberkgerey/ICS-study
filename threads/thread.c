#include <stdio.h>
#include <unistd.h>
#include <pthread.h>

void *threadFunc(){
    
    for (int i = 0; i<5; i++) {
        printf("Thread Function\n");
        sleep(1);
    }
    return NULL;
}

int main(){
    pthread_t thread;
    int status;
    
    status = pthread_create(&thread,NULL,threadFunc,NULL);
    // status = 0 successful, 1 is unsuccessful
    
    if(!status)
        printf("Thread Created \n");
    else
        printf("Thread is not Created \n");
    
    for (int i = 0; i<5; i++) {
        printf("Compiler thread\n");
        sleep(1);
    }
    
    return 0;
}
