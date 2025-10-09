#include <stdio.h>

int main() {
    int n1, n2, scelta;
    float result;

    do {
        printf("Enter first integer: ");
        scanf("%d", &n1);
        printf("Enter second integer: ");
        scanf("%d", &n2);

        printf("Select operation:\n");
        printf("1. Addition\n2. Subtraction\n3. Multiplication\n4. Division\nChoice: ");
        scanf("%d", &scelta);

        switch (scelta) {
            case 1:
                result = n1 + n2;
                printf("Result: %.2f\n", result);
                break;
            case 2:
                result = n1 - n2;
                printf("Result: %.2f\n", result);
                break;
            case 3:
                result = n1 * n2;
                printf("Result: %.2f\n", result);
                break;
            case 4:
                if (n2 != 0) {
                    result = (float)n1 / n2;
                    printf("Result: %.2f\n", result);
                } else {
                    printf("Error: Division by zero is not allowed.\n");
                }
                break;
            default:
                printf("Invalid operation selected.\n");
        }

        printf("Enter 1 to continue or 0 to exit: ");
        scanf("%d", &scelta);

    } while (scelta != 0);

    printf("Exiting the program.\n");
    return 0;
}