#include <stdio.h>

void sampleFunct (int (*sampleArr)[5]);

int main()
{
    int multiArr[6][5] = {
        {2, 5, 7},
        {6, 3, 1, 4},
        {9, 4, 2},
        3, 6, 8, 2, 7, 9, 3,
        1
    };

    printf("multiArr[2][0] = %d\n", multiArr[2][0]);
    printf("multiArr[4][3] = %d\n", multiArr[4][3]);
    printf("multiArr[4][2] = %d\n", multiArr[4][2]);
    printf("sizeof(multiArr) = %lu\n", sizeof(multiArr)); 
    printf("sizeof(multiArr[0]) = %lu\n", sizeof(multiArr[0]));
    printf("sizeof(multiArr[3]) = %lu\n\n", sizeof(multiArr[3]));

    printf("multiArr[0] = %p\n", multiArr[0]);
    printf("multiArr[0] + 2 = %p\n\n", multiArr[0] + 2); // 0 + 8

    printf("multiArr[3] = %p\n", multiArr[4]);
    printf("multiArr[3] + 2 = %p\n", multiArr[4] + 2); // 0 + 8, not 60 + 8

    sampleFunct(multiArr);

    printf("multiArr = %p\n", multiArr);

    return 0;
}


void sampleFunct (int (*sampleArr)[5])
{
    printf("\n\n\n\n");
    printf("sampleArr[4][2] = %d\n", sampleArr[4][2]);
    printf("sampleArr[2][0] = %d\n\n\n\n", sampleArr[2][0]);
    printf("sampleArr = %p\n", sampleArr);
    printf("sizeof(sampleArr) = %lu\n", sizeof(sampleArr));
}