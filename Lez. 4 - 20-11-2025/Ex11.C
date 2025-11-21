#include <stdio.h>
#include <math.h>

int main () {

    int n;
    int esponente;

    do {
        printf("Inserisci un numero >= 0: ");
        scanf("%d", &n);
    } while (n < 0);

    if (n == 0){
        printf("Zero,\t");
        return 0;
    } else if (n == 1){
        printf("Uno,\t");
        return 0;
    }

    // Trovare esponente
    for(int i = 0; i < n; i++){

        if (pow(10, i) >= n){
            esponente = i;
            break;
        }

    }

    int tempRis;
    int tempRes;
    int tempN = n;
    int tempExp = esponente;

    for (int i = 0; i < esponente; i++){

        tempRis = tempN / pow(10, tempExp - 1);
        tempRes = tempN % (int)pow(10, tempExp - 1);
        tempN = tempRes;

        switch (tempRis)
        {

        case 0:
            printf("Zero,\t");
            break;

        case 1:
            printf("Uno,\t");
            break;
        
        case 2:
            printf("Due,\t");
            break;
        
        case 3:
            printf("Tre,\t");
            break;
        
        case 4:
            printf("Quattro,\t");
            break;
        
        case 5:
            printf("Cinque,\t");
            break;
        
        case 6:
            printf("Sei,\t");
            break;

        case 7:
            printf("Sette,\t");
            break;

        case 8:
            printf("Otto,\t");
            break;

        case 9:
            printf("Nove,\t");
            break;

        default:
            break;
        }

        tempExp--;

    }

    return 0;

}