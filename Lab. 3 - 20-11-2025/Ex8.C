#include <stdio.h>

int sudoku[9][9]= {
{8,2,3,4,5,6,7,1,9},
{4,5,6,7,1,9,8,2,3},
{7,8,9,1,2,3,4,5,6},
{2,3,4,5,6,7,8,9,1},
{5,6,7,8,9,1,2,3,4},
{1,9,8,2,3,4,5,6,7},
{3,4,5,6,7,1,9,8,2},
{6,7,1,9,8,2,3,4,5},
{9,1,2,3,4,5,6,7,8}
};

int main() {

    printf("Matrice Sudoku da verificare:\n\n");
    for (int i = 0; i < 9; i++){
        for (int j = 0; j < 9; j++){
            printf("%d\t", sudoku[i][j]);
        }
        printf("\n\n");
    }
    printf("\n");


    for (int i = 0; i < 9; i++){
        for (int j = 0; j < 9; j++){
            for (int k = 0; k < 9; k++){
                if(sudoku[i][j] == sudoku[i][k] && j != k){
                    printf("Soluzione non accettabile (Riga %d non valida)\n", i+1);
                    return 0;
                }
            }
        }
    }

    for (int i = 0; i < 9; i++){
        for (int j = 0; j < 9; j++){
            for (int k = 0; k < 9; k++){
                if(sudoku[j][i] == sudoku[k][i] && j != k){
                    printf("Soluzione non accettabile (Colonna %d non valida)\n", i+1);
                    return 0;
                }
            }
        }
    }

    for(int boxRow = 0; boxRow < 3; boxRow++){
        for(int boxCol = 0; boxCol < 3; boxCol++){
            for(int i = 0; i < 3; i++){
                for(int j = 0; j < 3; j++){
                    for(int k = 0; k < 3; k++){
                        for(int l = 0; l < 3; l++){
                            if(sudoku[boxRow*3 + i][boxCol*3 + j] == sudoku[boxRow*3 + k][boxCol*3 + l] && (i != k || j != l)){
                                printf("Soluzione non accettabile (Sottomatrice %d,%d non valida)\n", boxRow+1, boxCol+1);
                                return 0;
                            }
                        }
                    }
                }
            }
        }
    }

    printf("Soluzione accettabile\n");
    return 0;
}