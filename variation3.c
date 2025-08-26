#include <stdio.h>
#include <stdlib.h>
#define LENGTH 10

typedef struct
{
    int *elemPtr;
    int count;
    int max;
} List;