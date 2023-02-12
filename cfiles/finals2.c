#include <stdio.h>

int magicSquareOrNot(int magic[][4]);

int main()
{
    int magic[4][4] = {
        {6, 3, 10, 15},
        {9, 16, 5, 4},
        {7, 2, 11, 14},
        {12, 13, 8, 1}
    };

    printf("%d\n", magicSquareOrNot(magic));

    return 0;
}

int magicSquareOrNot(int magic[][4])
{
    int idx, sum, rowIndex, temp[10], tempIndex;

    for(tempIndex = rowIndex = 0; rowIndex < 4; rowIndex++, tempIndex++){
        for(idx = sum = 0; idx < 4; idx++){
            sum += magic[rowIndex][idx];
        }
        temp[tempIndex] = sum;
        if (tempIndex > 0){
            if (temp[tempIndex] != temp[tempIndex - 1]){
                return 0;
            }
        }
    }

    for(idx = 0; idx < 4; idx++, tempIndex++){
        for(rowIndex = sum = 0; rowIndex < 4; rowIndex++){
            sum += magic[rowIndex][idx];
        }
        temp[tempIndex] = sum;
        if (temp[tempIndex] != temp[tempIndex - 1]){
            return 0;
        }
    }

    return 1;
}