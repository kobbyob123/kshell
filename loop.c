#include <stdio.h>

/*
 * A basic structure of a loop for a terminal 
 * ONLY displays the structure for accepting input(number)
 */

int main(int argc, char * argv[]){
    int flag = 1;
    int num;

    while (flag < 5){
        printf("kobby/osh --> ");
        scanf("%d", &num);
        flag++;
    }

    return (0);
}
