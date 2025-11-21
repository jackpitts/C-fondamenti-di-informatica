int a, b, c, *p;
#include <stdio.h>

int order(int *x, int *y, int *z){

    int tmp;

    if(*x > *y){
        tmp = *x;
        *x = *y;
        *y = tmp;
    }

    if(*x > *z){
        tmp = *x;
        *x = *z;
        *z = tmp;
    }

    if(*y > *z){
        tmp = *y;
        *y = *z;
        *z = tmp;
    }

    return *x,*y,*z;
}

int main(){

    printf("Inserisci tre numeri: ");
    scanf("%d %d %d", &a, &b, &c);

    order(&a, &b, &c);

    printf("Numeri ordinati: %d %d %d\n", a, b, c);

    return 0;
}