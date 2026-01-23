#include <stdio.h>
#include <stdlib.h>

struct el
{
    int val;
    struct el *next;
};

struct el *LIS1, *LIS2;

struct el *trasp()
{

    if (LIS2 != NULL)
    {
        printf("Errore: LIS2 non vuota\n");
        return 0;
    }

    struct el *p = LIS1;
    struct el *coda = NULL;

    while (p != NULL && p->next != NULL)
    {
        if (p->val > p->next->val)
        {
            struct el *nuovo = (struct el *)malloc(sizeof(struct el));
            nuovo->val = p->val;
            nuovo->next = NULL;

            if (LIS2 == NULL)
            {
                LIS2 = nuovo;
                coda = nuovo;
            }
            else
            {
                coda->next = nuovo;
                coda = nuovo;
            }
        }
        p = p->next;
    }
    return LIS2;
}

int main()
{

    LIS1 = (struct el *)malloc(sizeof(struct el));
    LIS1->val = 5;
    LIS1->next = (struct el *)malloc(sizeof(struct el));
    LIS1->next->val = 4;
    LIS1->next->next = (struct el *)malloc(sizeof(struct el));
    LIS1->next->next->val = 3;
    LIS1->next->next->next = (struct el *)malloc(sizeof(struct el));
    LIS1->next->next->next->val = 2;
    LIS1->next->next->next->next = (struct el *)malloc(sizeof(struct el));
    LIS1->next->next->next->next->val = 6;
    LIS1->next->next->next->next->next = (struct el *)malloc(sizeof(struct el));
    LIS1->next->next->next->next->next->val = 1;
    LIS1->next->next->next->next->next->next = (struct el *)malloc(sizeof(struct el));
    LIS1->next->next->next->next->next->next->val = 0;
    LIS1->next->next->next->next->next->next->next = NULL;

    LIS2 = NULL;

    trasp();

    for (struct el *p = LIS2; p != NULL; p = p->next)
    {
        printf("%d ", p->val);
    }

    printf("\n");
}