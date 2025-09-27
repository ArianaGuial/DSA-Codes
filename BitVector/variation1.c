#include <stdio.h>
#include <stdlib.h>
#define MAX 20

// variation 1 : using a char element to hold an int value

typedef char BitVector[MAX];

void setBit(BitVector bv, int index) 
{
    if (index >= 0 && index < MAX) 
    {
        bv[index] = 1;
    }
}

void clearBit(BitVector bv, int index) 
{
    if (index >= 0 && index < MAX) 
    {
        bv[index] = 0;
    }
}

int testBit(BitVector bv, int index) 
{
    if (index >= 0 && index < MAX) 
    {
        return bv[index];
    }

    return -1;
}

void display(BitVector bv) 
{
    for (int i = 0; i < MAX; i++) 
    {
        printf("%d ", bv[i]);
    }

    printf("\n");
}

int main() 
{
    BitVector bv = {0};

    setBit(bv, 1);
    setBit(bv, 3);
    clearBit(bv, 1);

    printf("\nBit Field contents: ");
    display(bv);

    printf("Test bit 3: %d", testBit(bv, 3));
    printf("\nTest bit 1: %d", testBit(bv, 1));
    printf("\n");

    return 0;
}