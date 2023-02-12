#include <stdio.h>

int main()
{
    char multiArr[7][5] = {'a'};

    printf("multiArr = %p\n", multiArr); // A100
    printf("multiArr[0] = %p\n", multiArr[0]); // A100
    printf("multiArr[0][0] = %d\n", multiArr[0][0]); // 97
    printf("&multiArr[0][0] = %p\n", &multiArr[0][0]); // A100
    printf("sizeof(multiArr) = %lu\n", sizeof(multiArr)); // 35 ... 7*5 * 1 (sizeof(char))
    printf("sizeof(multiArr[3]) = %lu\n", sizeof(multiArr[3])); // 5 ... 5 * 1
    printf("sizeof(multiArr[0][0]) = %lu\n", sizeof(multiArr[0][0])); // 1 ... sizeof(char)
    printf("sizeof(&multiArr[0][0]) = %lu\n", sizeof(&multiArr[0][0])); // 8 ... sizeof(char *)
    printf("multiArr + 1 = %p\n", multiArr + 1); // adds 5 because the size of one row is 5
    printf("multiArr[0] + 1 = %p\n", multiArr[0] + 1); // adds 1 because the size of one element is 1

    // multiArr points to the whole 2D array, thus the size is sizeof(char) * number of rows * number of elements in each rown or 1D array
    // multiArr[anyNumber] points to the 1D array, thus the size is sizeof(char) * number of elements in the row or 1D array

    return 0;
}