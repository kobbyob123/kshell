#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>
#include <stdlib.h>

int main(){
    int flag = 1;

    while (flag == 1){
        printf("kobby/osh --> ");
        // 1. get some characters from standard input 
        //    in an array form
        // 2. split them
        // 3. create a fork
        // 4. run an execve(2) to run the args
        // 5. handle errors
        // 6. look out for exit codes
    }
    return (0);
}
