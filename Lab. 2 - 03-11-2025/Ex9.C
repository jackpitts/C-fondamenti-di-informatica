#include <stdio.h>

int main () {

    int n1 = 1, n2 = 2;
    for (int i = 0; i < 100; i++) {

        if (((n1 % 3 == 0)||(n1 % 5 == 0)) && ((n2 % 3 == 0)||(n2 % 5 == 0))) {
            printf("%d ", n1);
            printf("%d - ", n2);
        }

            n1 += 2;
            n2 += 2;

    }

    printf("\n");
    return 0;

}