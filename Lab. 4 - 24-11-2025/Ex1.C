#include <stdio.h>

int conversione(float);

int main () {

    float num;
    printf("Inserisci una temperatura in gradi Fahrenheit: ");
    scanf("%f", &num);

    float res = conversione(num);
    printf("La temperatura in gradi Celsius è: %.2f\n", res);

}

int conversione (float num){
    num = (num - 32) * 5.0 / 9.0;
    return num;
}