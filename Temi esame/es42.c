#include <stdio.h>
#include <stdlib.h>

struct el {
    int val;
    struct el *next;
};

int trasp(struct el *LIS1, struct el **LIS2) {
    if (*LIS2 != NULL) {
        return 0;
    }

    struct el *curr1 = LIS1;
    struct el *tail = NULL;  // Puntatore alla coda di LIS2
    
    while (curr1 != NULL && curr1->next != NULL) {
        if (curr1->val > curr1->next->val) {
            struct el *nuovo = (struct el *) malloc(sizeof(struct el));
            nuovo->val = curr1->val;
            nuovo->next = NULL;
            
            if (*LIS2 == NULL) {
                *LIS2 = nuovo;
                tail = nuovo;
            } else {
                tail->next = nuovo;
                tail = nuovo;
            }
        }
        curr1 = curr1->next;
    }
    return 1;
}

int main() {
    struct el *LIS2 = NULL;
    
    struct el *n1 = (struct el *) malloc(sizeof(struct el));
    n1->val = 12;
    n1->next = (struct el *) malloc(sizeof(struct el));
    n1->next->val = 7;
    n1->next->next = (struct el *) malloc(sizeof(struct el));
    n1->next->next->val = -5;
    n1->next->next->next = (struct el *) malloc(sizeof(struct el));
    n1->next->next->next->val = 5;
    n1->next->next->next->next = NULL;

    trasp(n1, &LIS2);
    
    struct el *curr = LIS2;
    while (curr != NULL) {
        printf("%d ", curr->val);
        curr = curr->next;
    }
    printf("\n");
    
    return 0;
}
