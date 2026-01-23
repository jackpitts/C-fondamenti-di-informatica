#include <stdio.h>

struct el1
{
    int val;
    struct el1 *next;
};

struct el2
{
    int val;
    int delete;
    struct el2 *next;
};
struct el1 *L1 = NULL;
struct el2 *L2 = NULL;

struct el2 *DeleteMark(struct el1 *L1, struct el2 *L2)
{
    while (L2 != NULL)
    {
        if (L1 == NULL)
        {
            L2->delete = 1;
        }
        else
        {
            if (L1->val == L2->val)
            {
                L2->delete = 1;
            }
            else
            {
                L2->delete = 0;
            }
            L1 = L1->next;
        }
        L2 = L2->next;
    }
    return L2;
}

struct el2 *del(struct el2 *L2)
{
    struct el2 *curr = L2;
    struct el2 *prev = NULL;

    while (curr != NULL)
    {
        if (curr->delete == 1)
        {
            struct el2 *tmp = curr;
            if (prev == NULL)
            {
                // cancellare la testa
                L2 = curr->next;
                curr = L2;
            }
            else
            {
                prev->next = curr->next;
                curr = curr->next;
            }
            free(tmp);
        }
        else
        {
            prev = curr;
            curr = curr->next;
        }
    }

    return L2;
}