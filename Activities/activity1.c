#include<stdio.h>
#include<math.h>

int findFourth(char val)
{
    if(val & (1 << 3))
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

void displayBit(char val)
{
    for(int i = 7; i >= 0; i--)
    {
        if(val & (1 << i))
        {
            printf("1");
        }
        else
        {
            printf("0");
        }
    }

    printf("\n");
}

// SIR AND MA'AM PENA CODE STYLE
// void displayBit(char val)
// {
//     int bits = sizeof(char) * 8;
//     unsigned int mask = 1 << (bits - 1);

//     while(mask != 0)
//     {
//         printf("%d", (val & mask) ? 1 : 0);
//         mask >>= 1;
//     }

//     printf("\n");
// }

int main()
{
    char nums1 = 8;
    char nums2 = 4;
    char nums3 = 5;

    printf("\nBinary of %d = ", nums1);
    displayBit(nums1);

    printf("Binary of %d = ", nums2);
    displayBit(nums2);

    printf("Binary of %d = ", nums3);
    displayBit(nums3);

    printf("\nfindFourth(%d) = %d\n", nums1, findFourth(nums1)); 
    printf("findFourth(%d) = %d\n", nums2, findFourth(nums2)); 

    return 0;
}