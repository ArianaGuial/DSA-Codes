#include <stdio.h>
#include <stdbool.h>

#define BIT_SIZE (8 * sizeof(unsigned char))

void initialize(unsigned char *set) 
{
    *set = 0;
}

void insert(unsigned char *set, int element) 
{
    if (element >= 0 && element < BIT_SIZE) 
    {
        *set |= (1 << element);
    }
}

void delete(unsigned char *set, int element) 
{
    if (element >= 0 && element < BIT_SIZE) 
    {
        *set &= ~(1 << element);
    }
}

bool find(unsigned char set, int element) 
{
    if (element >= 0 && element < BIT_SIZE) 
    {
        return (set & (1 << element)) != 0;
    }

    return false;
}

unsigned char unionSet(unsigned char A, unsigned char B) 
{
    return A | B;
}

unsigned char intersection(unsigned char A, unsigned char B) 
{
    return A & B;
}

unsigned char difference(unsigned char A, unsigned char B) 
{
    return A & (~B);
}

void display(unsigned char set) 
{
    printf("{");

    bool first = true;

    for (int i = 0; i < BIT_SIZE; i++) 
    {
        if (set & (1 << i)) 
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
    unsigned char A, B, C;

    initialize(&A);
    insert(&A, 1);
    insert(&A, 6);
    printf("\nSet A after inserts: ");
    display(A);

    delete(&A, 6);
    printf("Set A after deleting 6: ");
    display(A); 

    delete(&A, 1);
    printf("Set A after deleting 1: ");
    display(A);

    insert(&A, 1);
    insert(&A, 6);

    B = 200;
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

    printf("Find 6 in A: %s\n", find(A, 6) ? "true" : "false");
    printf("Find 3 in A: %s\n", find(A, 3) ? "true" : "false");

    return 0;
}