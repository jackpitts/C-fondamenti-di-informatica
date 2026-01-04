#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// restituisce 1 se c è una lettera minuscola, 0 altrimenti
int f(char c) { 
    return c >= 'a' && c <= 'z'; 
}

// restituisce il puntatore al primo carattere non minuscolo dopo la sequenza iniziale di minuscole
char *g(char *s) { 
    while (f(*s)) 
        s++; 
    return s; 
}

// restituisce il puntatore al primo carattere minuscolo dopo la sequenza di caratteri non minuscoli
char *ig(char *s) { 
    while (!f(*s) && *s != '\0') 
        s++; 
    return s; 
}

// ritorna il puntatore al risultato dopo i-th "passaggi" ig(g(...))
char *h(char *s, int i) { 
    for (; i > 0; i--) 
        s = ig(g(s)); 
    return s; 
}

int main() {
    char T[50] = "prova01----la-trovo";
    char S[50] = "a#id-matr-9,7,6:-closed!!!cd4stringa";

    printf("%s\n", ig(g(T)));
    printf("-\n");
    printf("%s\n", h(S, 5));

    return 0;
}