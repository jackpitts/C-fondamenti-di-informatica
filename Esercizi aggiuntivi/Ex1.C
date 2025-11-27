#define DIM_STR 15
#include <stdio.h>

int main () {

    char str[DIM_STR];
    int count_a = 0;
    int count_e = 0;
    int count_i = 0;
    int count_o = 0;
    int count_u = 0;

    printf("Inserisci una stringa: ");
    scanf ("%s", str);
    
    for (int i = 0; i < DIM_STR; i++) {

        switch (str[i]) {

            case 'a':{
                count_a++;
                break;
            }

            case 'e':{
                count_e++;
                break;
            }

            case 'i':{
                count_i++;
                break;
            }

            case 'o':{
                count_o++;
                break;
            }

            case 'u':{
                count_u++;
                break;
            }

        }

    }

    printf("Conteggio vocali:\n");
    printf("a: %d\n", count_a);
    printf("e: %d\n", count_e);
    printf("i: %d\n", count_i);
    printf("o: %d\n", count_o);
    printf("u: %d\n", count_u);

    return 0;

}