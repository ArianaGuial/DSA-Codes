#include <stdio.h>
#include <stdbool.h>

#define ARRAY_SIZE 8

typedef enum 
{
    FALSE = 0,
    TRUE = 1
} Boolean;

typedef Boolean Set[ARRAY_SIZE];

void initialize(Set set) 
{
    for (int i = 0; i < ARRAY_SIZE; i++) 
    {
        set[i] = FALSE;
    }
}

void insert(Set set, int element) 
{
    if (element >= 0 && element < ARRAY_SIZE) 
    {
        set[element] = TRUE;
    }
}

void delete(Set set, int element) 
{
    if (element >= 0 && element < ARRAY_SIZE) 
    {
        set[element] = FALSE;
    }
}

bool find(Set set, int element) 
{
    if (element >= 0 && element < ARRAY_SIZE) 
    {
        return set[element];
    }
    return false;
}

void unionSet(Set A, Set B, Set C) 
{
    for (int i = 0; i < ARRAY_SIZE; i++) 
    {
        C[i] = A[i] || B[i];
    }
}

void intersection(Set A, Set B, Set C) 
{
    for (int i = 0; i < ARRAY_SIZE; i++) 
    {
        C[i] = A[i] && B[i];
    }
}

void difference(Set A, Set B, Set C) 
{
    for (int i = 0; i < ARRAY_SIZE; i++) 
    {
        C[i] = A[i] && !B[i];
    }
}

void display(Set set) 
{
    printf("{");
    bool first = true;

    for (int i = 0; i < ARRAY_SIZE; i++) 
    {
        if (set[i]) 
        {
            if (!first)
            {
                printf(", ");
            }

            printf("%d", i);
            first = false;
        }
    }
    printf("}\n");
}

int main() 
{
    Set A, B, C;

    initialize(A);
    insert(A, 0);
    insert(A, 2);
    insert(A, 7);
    printf("\nSet A: ");
    display(A);

    delete(A, 0);
    delete(A, 7);
    printf("Set A after deletions: ");
    display(A);

    insert(A, 0);
    insert(A, 7);
    initialize(B);
    insert(B, 2);
    insert(B, 4);
    insert(B, 5);
    printf("Set B: ");
    display(B);

    unionSet(A, B, C);
    printf("Union of A and B: ");
    display(C);

    intersection(A, B, C);
    printf("Intersection of A and B: ");
    display(C);

    difference(A, B, C);
    printf("Difference A - B: ");
    display(C);

    printf("Find 2 in A: %s\n", find(A, 2) ? "true" : "false");
    printf("Find 5 in A: %s\n", find(A, 5) ? "true" : "false");

    return 0;
}