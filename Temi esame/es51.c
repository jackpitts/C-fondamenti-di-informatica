#include <stdio.h>

struct el {
    int n;
    struct el *next;
};
struct el *L1 = NULL;

int dup(struct el *L1, struct el *pos) {
    if (L1 == NULL || pos == NULL) return 0;

    int countFirstHalf = 0;
    struct el *curr = L1;

    while (curr != NULL) {
        if (curr == pos) {
            // siamo arrivati a pos, smettiamo di contare
            break;
        }
        if (curr->n == pos->n) {
            countFirstHalf++;
        }
        curr = curr->next;
    }

    return countFirstHalf;
}