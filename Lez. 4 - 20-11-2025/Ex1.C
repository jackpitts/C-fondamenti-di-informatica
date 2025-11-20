#define DIM_PIT 10
#include <stdio.h>

int main (){

    for (int i = 1; i <= DIM_PIT; i++) {
        for (int j = 1; j <= DIM_PIT; j++) {
            if(((i*j)%5 == 0) && ((i*j)%7 == 0)){
                printf("%d*\t", i*j);
            }
            else {
            printf("%d\t", i*j);
            } 
        }
        printf("\n");
    }
    return 0;
}