#include <stdio.h>

int main () {

    int num;

    printf("Enter an integer: ");
    scanf("%d", &num);

    if (num % 2 != 0 || (num < 20 || num > 90)) {

        printf("True\n");
        return true;

    } else {

        printf("False\n");
        return false;

    }

    return 0;

}