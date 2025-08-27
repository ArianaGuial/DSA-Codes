#include <stdio.h>
#include <stdlib.h>
#define LENGTH 10

typedef int studtype;

typedef struct
{
    studtype *elemPtr;
    int count;
    int max;
} List;

void initialize(List *L) 
{
    L->elemPtr = (studtype *)malloc(sizeof(studtype) * LENGTH);
    L->count = 0;
    L->max = LENGTH;
}

void insertPos(List *L, int data, int position) 
{
    if(position < 0 || position > L->count) 
    {
        printf("Invalid position.\n");
        return;
    }

    if(L->count == L->max) 
    {
        resize(L);
    }

    for(int i = L->count; i > position; i--) 
    {
        L->elemPtr[i] = L->elemPtr[i - 1];
    }

    L->elemPtr[position] = data;
    L->count++;
}

void deletePos(List *L, int position) 
{
    if(position < 0 || position >= L->count) 
    {
        printf("Invalid position.\n");
        return;
    }

    for(int i = position; i < L->count - 1; i++) 
    {
        L->elemPtr[i] = L->elemPtr[i + 1];
    }

    L->count--;
}

int locate(List *L, int data) 
{
    for(int i = 0; i < L->count; i++) 
    {
        if (L->elemPtr[i] == data) 
        {
            return i;
        }
    }
    return -1;
}

int retrieve(List *L, int position) 
{
    if(position < 0 || position >= L->count) 
    {
        printf("Invalid position.\n");
        return -1;
    }
    return L->elemPtr[position];
}

void insertSorted(List *L, int data) 
{
    if(L->count == L->max) 
    {
        resize(L);
    }

    int position = 0;

    while(position < L->count && L->elemPtr[position] < data) 
    {
        position++;
    }

    insertPos(L, data, position);
}

void display(List *L) 
{
    printf("List elements: ");

    for(int i = 0; i < L->count; i++) 
    {
        printf("%d ", L->elemPtr[i]);
    }
    printf("\n");
}

void resize(List *L) 
{
    L->max *= 2;
    studtype *newPtr = (studtype *)realloc(L->elemPtr, sizeof(studtype) * L->max);
   
    if(newPtr == NULL) 
    {
        printf("Memory reallocation failed.\n");
        exit(1);
    }
    L->elemPtr = newPtr;
}

void makeNULL(List *L) 
{
    free(L->elemPtr);
    L->elemPtr = NULL;
    L->count = 0;
    L->max = 0;
}

int main() 
{
    List L;
    initialize(&L);

    insertPos(&L, 1, 0);
    insertPos(&L, 3, 1);
    insertPos(&L, 2, 2);
    insertPos(&L, 5, 3);
    display(&L); 

    insertPos(&L, 4, 2);
    display(&L);

    deletePos(&L, 1);
    display(&L);

    int pos = locate(&L, 2);
    printf("Position of 2: %d\n", pos);

    int val = retrieve(&L, 2);
    printf("Retrieved value: %d\n", val);

    insertSorted(&L, 8);
    display(&L); 

    makeNULL(&L);
    return 0;
}