#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>

int main(){
    int arr[] = {1,2,3,4,5,6};
    int arrSize = sizeof(arr) / sizeof(int);
    int start, end;
    int fd[2];
    int p = pipe(fd);
    int id = fork();
    
    if(pipe(fd) == -1)
        return 1;
    
    id = fork();
    
    if(id == 0){
        start = 0;
        end = arrSize/2;
    }
    else {
        start = arrSize / 2;
        end = arrSize;
    }
    
    int sum = 0, i;
    
    for(i = start; i < end; i++){
        sum += arr[i];
        printf("sum = %d \n",sum);
    }
    
    if(id == 0){
        close(fd[0]);
        read(fd[1],&sum,sizeof(sum));
        close(fd[1]);
    }
    
    else{
        int childProcessNum;
        close(fd[1]);
        read(fd[1],&childProcessNum,sizeof(childProcessNum));
        close(fd[0]);
        int lastSum = sum + childProcessNum;
        printf("Last Summary = %d\n", lastSum);
    }
    
    return 0;
}

/*
 
 Temel olarak processler arası iletişim için kullanılır.

 Tipik olarak, bir pipe parent process ile child process arasında yada tek bir process içerisinde 2 thread arasındaki iletişimi kurmak için kullanılır.

 */
