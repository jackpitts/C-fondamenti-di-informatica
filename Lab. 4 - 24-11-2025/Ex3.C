#include <stdio.h>
#define TXTL 20
int gg_mese[12] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

typedef struct {

    int anno;
    int mese;
    int giorno;

} s_data;

typedef struct {

    s_data data;
    char meteo[TXTL];

} s_bollettino;

int anno_bisestile (int anno) {

    if (anno % 4 == 0 && (anno % 100 !=0 || anno % 400 == 0)){
        return 1;
    } else {
        return 0;
    }

}

int verifica_data (s_data data){
    
    if (data.anno >= 2000){

        if (data.mese >= 1 && data.mese <= 12){

            if (data.giorno >= 1 && data.giorno <= gg_mese[data.mese - 1]){

                return 1;

            } else if (data.mese == 2 && anno_bisestile(data.anno) && data.giorno == 29){
                    return 1;
                } else {
                    return 0;
                }
                return 0;
        } else {
            return 0;
        }

    } else {
        return 0;
    }

}

int giorni_da_capodanno (s_data data){

    int giorni = 0;
    for (int i = 0; i < data.mese - 1; i++){
        giorni += gg_mese[i];
    }
    giorni += data.giorno;

    if (data.mese > 2 && anno_bisestile(data.anno)){
        giorni += 1;
    }

    return giorni;
}

void ins_bollettino(s_bollettino *bollettino){

    do {
        printf("Inserisci la data (gg/mm/aaaa): ");
        scanf("%d/%d/%d", &bollettino->data.giorno, &bollettino->data.mese, &bollettino->data.anno);
    } while (!verifica_data(bollettino->data));

    fflush(stdin);

    printf("Inserisci il meteo: ");
    scanf("%s", bollettino->meteo);
}

void stampa_bollettino(s_bollettino bollettino){

    printf("Data: %02d/%02d/%04d\n", bollettino.data.giorno, bollettino.data.mese, bollettino.data.anno);
    printf("Meteo: %s\n", bollettino.meteo);
    int anno_bis = anno_bisestile(bollettino.data.anno);
    if (anno_bis){
        printf("L'anno %d è bisestile.\n", bollettino.data.anno);
    } else {
        printf("L'anno %d non è bisestile.\n", bollettino.data.anno);
    }
    int giorni = giorni_da_capodanno(bollettino.data);
    printf("Giorni trascorsi da capodanno: %d\n", giorni);

}

int main () {

    s_bollettino bollettino;

    ins_bollettino(&bollettino);
    stampa_bollettino(bollettino);

}
