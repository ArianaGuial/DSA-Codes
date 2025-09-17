#include<stdio.h>
#include<stdlib.h>
#define MAX 4

typedef struct
{
    int elem;
    int next;
} Cell, HeapSpace[MAX];

typedef struct
{
    HeapSpace H;
    int avail;
} VHeap;

typedef int List;

void initialize(VHeap *V)
{
    V->avail = 0;

    for(int i = 0; i < MAX -1; i++)
    {
        V->H[i].next = i + 1;
    }

    V->H[MAX - 1].next = -1;
}

int allocSpace(VHeap* V)
{
    if(V->avail == -1)
    {
        return -1;
    }

    int index = V->avail;
    V->avail = V->H[index].next;

    return index;
}

void deallocSpace(VHeap *V, int index)
{
    V->H[index].next = V->avail;
    V->avail = index;
}

void insertFirst(int* L, VHeap* V, int elem)
{
    int index = allocSpace(V);

    if(index == -1)
    {
        printf("No space available\n");
        return;
    }

    V->H[index].elem = elem;
    V->H[index].next = *L;
    *L = index;
}

void insertLast(int* L, VHeap* V, int elem)
{
    int index = allocSpace(V);

    if(index == -1)
    {
        printf("No space available\n");
        return;
    }

    V->H[index].elem = elem;
    V->H[index].next = -1;

    if(*L == -1)
    {
        *L = index;
    }
    else
    {
        int trav = *L;

        while(V->H[trav].next != -1)
        {
            trav = V->H[trav].next;
        }

        V->H[trav].next = index;
    }
}

void insertSorted(int* L, VHeap* V, int elem)
{
    int index = allocSpace(V);

    if(index == -1)
    {
        printf("No space available\n");
        return;
    }

    V->H[index].elem = elem;

    if(*L == -1 || V->H[*L].elem >= elem)
    {
        V->H[index].next = *L;
        *L = index;
    }
    else
    {
        int prev = *L;
        int curr = V->H[prev].next;

        while(curr != -1 && V->H[curr].elem < elem)
        {
            prev = curr;
            curr = V->H[curr].next;
        }

        V->H[index].next = curr;
        V->H[prev].next = index;
    }
}

void delete(List *L, VHeap *V, int elem)
{
    int prev = -1;
    int curr = *L;

    while(curr != -1 && V->H[curr].elem != elem)
    {
        prev = curr;
        curr = V->H[curr].next;
    }

    if(curr == -1)
    {
        printf("Element %d not found\n", elem);
        return;
    }

    if(prev == -1)
    {
        *L = V->H[curr].next;
    }
    else
    {
        V->H[prev].next = V->H[curr].next;
    }

    deallocSpace(V, curr);
    printf("DELETED %d\n", elem);
}

void deleteAll(List *L, VHeap *V, int elem)
{
    int prev = -1;
    int curr = *L;

    while(curr != -1)
    {
        if(V->H[curr].elem == elem)
        {
            int toDelete = curr;
            curr = V->H[curr].next;

            if(prev == -1)
            {
                *L = curr;
            }
            else
            {
                V->H[prev].next = curr;
            }

            deallocSpace(V, toDelete);
            printf("DELETED %d\n", elem);
        }
        else
        {
            prev = curr;
            curr = V->H[curr].next;
        }
    }
}

void display(int L, VHeap V)
{
    if(L == -1)
    {
        printf("List is empty\n");
        return;
    }

    printf("\nList contents: \n");

    int curr = L;

    while(curr != -1)
    {
        printf("%d ", V.H[curr].elem);
        curr = V.H[curr].next;
    }

    printf("\n");
}

int main()
{
    VHeap V;
    List L = -1;

    initialize(&V);

    insertFirst(&L, &V, 3);
    insertFirst(&L, &V, 2);
    insertFirst(&L, &V, 1);
    display(L, V);

    insertLast(&L, &V, 4);
    display(L, V);
    
    delete(&L, &V, 3);
    display(L, V);

    insertSorted(&L, &V, 2);
    display(L, V);

    deleteAll(&L, &V, 3);
    display(L, V);

    return 0;
}