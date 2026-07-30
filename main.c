#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>
#include <stdlib.h>

int main(){
    int flag = 1;
    char *line = NULL;
    ssize_t len = 0;
    ssize_t read;

    while (flag == 1){
        printf("kobby/ksh --> ");
        
        // 1. get some characters from standard input in an array form
        read = getline(&line, &len, stdin);
        
        if (read < 0){
            exit(EXIT_FAILURE);
        }

        if (read != -1) {
            printf("You entered: %s", line); // Includes newline
            // printf("Exit code: %ld\n", read);
        }

        // 2. split them
        // 3. create a fork
        // 4. run an execve(2) to run the args
        // 5. handle errors
        // 6. look out for exit codes

        // printf("getline code = %ld", gl_ex_code);
    }
    flag = 0;

    free(line);
    return (0);
}
