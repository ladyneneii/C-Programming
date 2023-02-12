#include <stdio.h>

int main()
{
    int num, idx, idx2, row;

    scanf("%d", &num);
    for (idx = 1, row = 1; idx <= num;){
        for (idx2 = 0; idx <= num && idx2 < row; idx++, idx2++){
           printf("%d", idx);
        }
        printf("\n");
        row++;
    }

    return 0;
}