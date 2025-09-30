#include <stdio.h>
#include <stdbool.h>

#define BIT_SIZE 8 

typedef struct 
{
    unsigned int field : BIT_SIZE;  
} Set;

void initialize(Set *set) 
{
    set->field = 0;
}

void insert(Set *set, int element) 
{
    if (element >= 0 && element < BIT_SIZE) 
    {
        set->field |= (1 << element);
    }
}

void delete(Set *set, int element) 
{
    if (element >= 0 && element < BIT_SIZE) 
    {
        set->field &= ~(1 << element);
    }
}

bool find(Set set, int element) 
{
    if (element >= 0 && element < BIT_SIZE) 
    {
        return (set.field & (1 << element)) != 0;
    }
    return false;
}

Set unionSet(Set A, Set B) 
{
    Set C;
    C.field = A.field | B.field;
    return C;
}

Set intersection(Set A, Set B)
{
    Set C;
    C.field = A.field & B.field;
    return C;
}

Set difference(Set A, Set B) 
{
    Set C;
    C.field = A.field & (~B.field);
    return C;
}

void display(Set set) 
{
    printf("{");
    bool first = true;

    for (int i = 0; i < BIT_SIZE; i++) 
    {
        if (set.field & (1 << i)) 
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

    initialize(&A);
    insert(&A, 0);
    insert(&A, 4);
    insert(&A, 5);
    printf("\nSet A: ");
    display(A);

    delete(&A, 5);
    delete(&A, 4);
    printf("Set A after deletions: ");
    display(A);

    insert(&A, 4);
    insert(&A, 5);
    B.field = 36;
    printf("Set B: ");
    display(B);

    C = unionSet(A, B);
    printf("Union of A and B: ");
    display(C); 

    C = intersection(A, B);
    printf("Intersection of A and B: ");
    display(C);

    C = difference(A, B);
    printf("Difference A - B: ");
    display(C); 

    printf("Find 5 in A: %s\n", find(A, 5) ? "true" : "false");
    printf("Find 2 in A: %s\n", find(A, 2) ? "true" : "false");

    return 0;
}