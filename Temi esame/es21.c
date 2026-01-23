#include <stdio.h>
#include <stdlib.h>

struct el
{
    int val;
    struct el *next;
};

struct el *L;

struct el *crea(struct el *L, int num)
{

    if (L != NULL)
    {
        return L;
    }

    int count = 0;
    int temp = num;
    int *vettore;

    do
    {
        count++;
        temp /= 10;
    } while (temp > 0);

    vettore = (int *)malloc(sizeof(int) * count);
    temp = num;

    for (int i = count - 1; i >= 0; i--)
    {
        vettore[i] = temp % 10;
        temp /= 10;
    }

    struct el *p = L;

    for (int i = count - 1; i >= 0; i--)
    {
        int tmp = vettore[i];
        for (int j = 0; j < tmp; j++)
        {
            struct el *newel = (struct el *)malloc(sizeof(struct el));
            newel->val = tmp;
            newel->next = NULL;

            if (L == NULL)
            {
                L = newel;
                p = L;
            }
            else
            {
                p->next = newel;
                p = newel;
            }
        }
    }

    free(vettore);
    return L;
}

int main()
{
    L = NULL;
    int num;

    printf("Inserisci un numero intero positivo: ");
    scanf("%d", &num);

    struct el *result = crea(L, num);
    while (result != NULL)
    {
        printf("%d", result->val);
        if (result->next != NULL)
        {
            printf(" -> ");
        }
        result = result->next;
    }
    printf("\n");
}