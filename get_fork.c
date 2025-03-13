#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>
#include <stdlib.h>

/**
 * This demonstration explains the system call fork() 
 * Think of a bacteria splitting when fork is called
*/

void multifork(){
    fork();
    fork();
    fork();
    printf("Hello\n");
}

int main(){
    pid_t process_id = fork();

    if (process_id < 0){
        perror("fork failed");
        exit(1);
    }

    else if (process_id == 0){
        printf("Child Process ID = %d \n", process_id);
    }

    else{
        printf("Parent Process ID = %d \n", process_id);
    }

    // comment the whole code and uncomment only the one below
    // multifork(); 

    return(0);
}
