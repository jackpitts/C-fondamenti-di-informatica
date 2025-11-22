#include <stdio.h>

int main () {

    for (int i = -20; i <= 197; i += 7) {
        
        if ((32 + ((float)i * 9) / 5) - (float)i != 100) {

            printf("%.2f C -> ", (float)i);
            printf("%.2f F\n", (32 + ((float)i * 9) / 5));

        } else {

            printf("Differenza = 100, ");
            printf("%.2f C -> ", (float)i);
            printf("%.2f F\n", (32 + ((float)i * 9) / 5));

        }
    }

}