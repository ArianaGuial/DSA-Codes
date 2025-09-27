#include<stdio.h>
#include<stdlib.h>
#define MAX 20

// variation 3 : using an enum

typedef enum
{
    true = 1, false = 0
} Boolean;

typedef Boolean Set[MAX];

void setBit(Set s, int index)
{
    if(index >= 0 && index < MAX)
    {
        s[index] = true;
    }
}

void clearBit(Set s, int index)
{
    if(index >= 0 && index < MAX)
    {
        s[index] = false;
    }
}

int testBit(Set s, int index)
{
    if(index >= 0 && index < MAX)
    {
        return s[index];
    }

    return -1;
}

void display(Set s)
{
    for(int i = 0; i < MAX; i++)
    {
        printf("%d ", s[i]);
    }

    printf("\n");
}

int main()
{
    Set s = {false};

    setBit(s, 0);
    setBit(s, 4);
    clearBit(s, 0);

    printf("\nBoolean Set contents: ");
    display(s);

    printf("Test bit 4: %d", testBit(s, 4));
    printf("\nTest bit 0: %d", testBit(s, 0));
    printf("\n");

    return 0;
}