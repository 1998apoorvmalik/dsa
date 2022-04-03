#include <stdio.h>
#define MAX_BITS 32

// To run : gcc reverse_num.c -o tmp && ./tmp < test_cases.txt && rm tmp

int findMSBIndex(int num)
{
    if (!num)
        return 0;

    int index = 0;

    while (num >= (1 << index))
    {
        index++;
    }
    return index - 1;
}

int reverseNum(int num, int maxBits)
{
    int reversedNum = 0;
    int nShifts = 0;
    int nBits = findMSBIndex(num);

    printf("%d\n", nBits);

    while (nShifts <= nBits)
    {
        if ((num >> nShifts) & 1)
        {
            reversedNum += 1 << (nBits - nShifts);
        }
        nShifts++;
    }
    return reversedNum << (maxBits - nBits - 1);
}
int main()
{
    // printf("%d\n", reverseNum(4294967293, MAX_BITS));
    printf("%d\n", findMSBIndex(4294967293));
    // int t;
    // scanf("%d", &t);
    // while (t--)
    // {
    //     int num;
    //     scanf("%d", &num);
    //     printf("%d\n", reverseNum(num, 32));
    //     // printf("%d\n", reverseNum(num, N_BITS));
    // }
}