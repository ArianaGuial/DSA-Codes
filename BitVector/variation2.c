#include<stdio.h>
#include<stdlib.h>
#define MAX 20

// variation 2 : using bit fields inside a struct

typedef struct
{
    unsigned int bits : MAX;
} Set;

void setBit(Set *s, int index)
{
    if(index >= 0 && index < MAX)
    {
        s->bits |= (1 << index);
    }
}

void clearBit(Set *s, int index)
{
    if(index >= 0 && index < MAX)
    {
        s->bits &= ~(1 << index);
    }
}

int testBit(Set s, int index)
{
    if(index >= 0 && index < MAX)
    {
        return(s.bits >> index) & 1;
    }

    return -1;
}

void display(Set s)
{
    for(int i = MAX - 1; i >=0; i--)
    {
        printf("%d ", (s.bits >> i) & 1);
    }

    printf("\n");
}

int main()
{
    Set s = {0};

    setBit(&s, 1);
    setBit(&s, 3);
    clearBit(&s, 1);

    printf("\nBit Field content: ");
    display(s);

    printf("Test bit 3: %d", testBit(s, 3));
    printf("\nTest bit 1: %d", testBit(s, 1));
    printf("\n");

    return 0;
}