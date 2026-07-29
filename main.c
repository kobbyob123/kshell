#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>
#include <stdlib.h>

int main(){
    int flag = 1;
    int gl_ex_code;

    while (flag == 1){
        printf("kobby/ksh --> \n");
        // 1. get some characters from standard input 
        //    in an array form
        gl_ex_code = getline();
        // 2. split them
        // 3. create a fork
        // 4. run an execve(2) to run the args
        // 5. handle errors
        // 6. look out for exit codes

        printf("getline code = %d", gl_ex_code);
    }
    flag = 0;
    return (0);
}
