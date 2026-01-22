#define N 21
typedef int riga [N];

riga Ntessere = {2,2,2,4,4,4,4,2,2,2,2,1,1,1,2,4,6,4,10,1,2}; 
riga valore = {1,3,3,3,3,4,2,4,2,1,8,5,1,2,4,6,4,10,1,2,1};

int idonea(char parola[], riga Ntessere) {
    char alfabeto[N] = "ABCDEFGHILMNOPQRSTUVZ";
    int cont[N] = {0};
    int len = 0;

    /* lunghezza e validità caratteri */
    for (int i = 0; parola[i] != '\0'; i++) {
        int trovato = -1;
        len++;

        for (int j = 0; j < N; j++) {
            if (parola[i] == alfabeto[j]) {
                trovato = j;
                break;
            }
        }

        if (trovato == -1)
            return -1;   // carattere non valido

        cont[trovato]++;
    }

    if (len < 2)
        return -1;

    /* verifica tessere disponibili */
    for (int i = 0; i < N; i++) {
        if (cont[i] > Ntessere[i])
            return 0;
    }

    return 1;
}