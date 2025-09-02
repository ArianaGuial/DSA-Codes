#include <stdio.h>
#include <stdlib.h>
#define MAX 10

typedef struct
{
    int elem[MAX];
    int count;
} Etype, *EPtr;

void initialize(EPtr L)
{
    L->count = 0;
}

void insertPos(EPtr L, int data, int position)
{
    if(L->count == MAX)
    {
        printf("List is full\n");
        return;
    }

    if(position < 0 || position > L->count)
    {
        printf("Invalid position\n");
        return;
    }

    for(int i = L->count; i > position; i--)
    {
        L->elem[i] = L->elem[i - 1];
    }

    L->elem[position] = data;
    L->count++;
}

void deletePos(EPtr L, int position)
{
    if(position < 0 || position >= L->count)
    {
        printf("Invalid position\n");
        return;
    }

    for(int i = position; i < L->count - 1; i++)
    {
        L->elem[i] = L->elem[i + 1];
    }

    L->count--;
}

int locate(EPtr L, int data)
{
    for(int i = 0; i < L->count; i++)
    {
        if(L->elem[i] == data)
        {
            return i;
        }
    }
    return -1;
}

int retrieve(EPtr L, int position)
{
    if(position < 0 || position >= L->count)
    {
        printf("Invalid position\n");
        return -1;
    }
    return L->elem[position];
}

void insertSorted(EPtr L, int data)
{
    if(L->count == MAX)
    {
        printf("List is full\n");
        return;
    }

    int position = 0;

    while(position < L->count && L->elem[position] < data)
    {
        position++;
    }

    insertPos(L, data, position);
}

void display(EPtr L)
{
    printf("List elements: ");

    for(int i = 0; i < L->count; i++)
    {
        printf("%d ", L->elem[i]);
    }
    printf("\n");
}

void makeNULL(EPtr *L)
{
    free(*L);
    *L = NULL;
}

int main()
{
    EPtr L = (EPtr)malloc(sizeof(Etype));
    initialize(L);

    insertPos(L, 1, 0);
    insertPos(L, 3, 1);
    insertPos(L, 2, 2);
    insertPos(L, 5, 3);
    display(L);

    insertPos(L, 4, 2);
    display(L);

    deletePos(L, 1);
    display(L);

    int pos = locate(L, 2);
    printf("Position of 2: %d\n", pos);

    int val = retrieve(L, 2);
    printf("Retrieved value: %d\n", val);

    insertSorted(L, 8);
    display(L);

    makeNULL(&L);
    return 0;
}
