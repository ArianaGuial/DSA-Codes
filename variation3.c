#include <stdio.h>
#include <stdlib.h>
#define LENGTH 10

typedef struct
{
    int *elemPtr;
    int count;
    int max;
} List;

List initialize(List L);
List insertPos(List L, int data, int position);
List deletePos(List L, int position);
int locate(List L, int data);
List insertSorted(List L, int data);
void display(List L);
List resize(List L);

List initialize(List L) 
{
    L.elemPtr = (int *)malloc(sizeof(int) * LENGTH);
    if (L.elemPtr == NULL)
    {
        printf("Memory allocation failed.\n");
        exit(1);
    }
    L.count = 0;
    L.max = LENGTH;
    return L;
}

List resize(List L) 
{
    int newMax = L.max * 2;
    int *newArray = (int *)realloc(L.elemPtr, sizeof(int) * newMax);

    if (newArray == NULL) 
    {
        printf("Memory allocation failed.\n");
        exit(1);
    }

    L.elemPtr = newArray;
    L.max = newMax;
    return L;
}

List insertPos(List L, int data, int position) 
{
    if (position < 0 || position > L.count) 
    {
        printf("Invalid position.\n");
        return L;
    }

    if (L.count == L.max) 
    {
        L = resize(L);
    }

    for (int i = L.count; i > position; i--) 
    {
        L.elemPtr[i] = L.elemPtr[i - 1];
    }

    L.elemPtr[position] = data;
    L.count++;
    return L;
}

List deletePos(List L, int position) 
{
    if (position < 0 || position >= L.count) 
    {
        printf("Invalid position.\n");
        return L;
    }

    for (int i = position; i < L.count - 1; i++) 
    {
        L.elemPtr[i] = L.elemPtr[i + 1];
    }

    L.count--;
    return L;
}

int locate(List L, int data) 
{
    for (int i = 0; i < L.count; i++) 
    {
        if (L.elemPtr[i] == data) 
        {
            return i;
        }
    }
    return -1;
}

List insertSorted(List L, int data) 
{
    if (L.count == L.max) 
    {
        L = resize(L);
    }

    int position = 0;
    while (position < L.count && L.elemPtr[position] < data) 
    {
        position++;
    }

    return insertPos(L, data, position);
}

void display(List L) 
{
    printf("List elements: ");

    for(int i = 0; i < L.count; i++) 
    {
        printf("%d ", L.elemPtr[i]);
    }

    printf("\n");
}

int main() 
{
    List L;
    L = initialize(L);

    L = insertPos(L, 1, 0);
    L = insertPos(L, 3, 1);
    L = insertPos(L, 2, 2);
    L = insertPos(L, 5, 3);
    display(L); 

    L = insertPos(L, 4, 2);
    display(L); 

    L = deletePos(L, 1);
    display(L);

    int pos = locate(L, 2);
    printf("Position of 2: %d\n", pos);

    L = insertSorted(L, 8);
    display(L);

    free(L.elemPtr);
    return 0;
}