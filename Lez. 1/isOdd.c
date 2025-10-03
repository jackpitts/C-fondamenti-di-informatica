#include <stdio.h>

int main(){
    int num;
    printf("Inserisci un numero:");
    scanf("%d", &num);
    if ((num % 2 != 0) || (num > 10 && num < 20)) {
        printf("OK");
    } else {
        printf("notOK");
    }
    return 0;
}