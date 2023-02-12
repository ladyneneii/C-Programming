#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int *modes, count, max;
} Mode;

Mode findMode(int numbers[], int count);

int main()
{
    int ctr = -1, *numbers = (int *)malloc(5*sizeof(int));

    do {
        ctr++;
        printf("Enter a number (enter -1 if done):\n");
        scanf("%d", numbers+ctr);
        if (ctr % 4 == 0){
            numbers = (int *)realloc(numbers, (ctr+5)*sizeof(int));
        }
    } while (numbers[ctr] != -1);

    // find mean

    int idx;
    float mean = 0.0;

    for (idx = 0; idx < ctr; idx++){
        mean += numbers[idx];
    }
    mean /= (float)ctr;

    printf("The mean is %f.\n", mean);

    // find median

    int idx2, temp, median, count;

    for (idx = 0; idx < ctr-1; idx++){
        for (idx2 = idx; idx2 > -1 && numbers[idx2] > numbers[idx2+1]; idx2--){
            temp = numbers[idx2];
            numbers[idx2] = numbers[idx2+1];
            numbers[idx2+1] = temp;
        }
    }

    count = ctr;

    if (ctr % 2 == 0){
        ctr /= 2;
        median = (numbers[ctr]+numbers[ctr-1])/2;
    } else {
        ctr /= 2;
        median = numbers[ctr];
    }

    printf("The median is %d.\n", median);

    // find mode

    Mode mode = findMode(numbers, count);

    printf("Mode/s:");
    for (idx = 0; mode.modes[idx] != -1; idx++){
        printf(" %d", mode.modes[idx]);
    }

    return 0;
}

Mode findMode(int numbers[], int count)
{
    Mode mode = {(int *)malloc(count*sizeof(int)), 0, count};
    int idx, idx2, repeat[count];

    for (idx = 0; idx < count; idx++){
        mode.modes[idx] = numbers[idx];
        for (repeat[idx] = idx2 = 0; idx2 < count; idx2++){
            if (numbers[idx2] == mode.modes[idx]){
                repeat[idx]++;
            }
        }
    }

    int big = repeat[0];

    for (idx = 1; idx < count; idx++){
        if(big < repeat[idx]){
            big = repeat[idx];
        }
    }

    for (idx2 = idx = 0; idx < count; idx++){
        if (big == repeat[idx]){
            mode.modes[idx2] = numbers[idx];
            idx2++;
        }
    }
    mode.modes[idx2] = -1;
    mode.count = idx2+1;

    int idx3;

    for (idx = 0; mode.modes[idx] != -1; ){
        for (idx2 = 0; mode.modes[idx2] != -1 && mode.modes[idx2] != mode.modes[idx2+1]; idx2++){}
        if (mode.modes[idx2] != -1){
            for (mode.count--, idx3 = idx2+1; mode.modes[idx3] < count; idx3++){
                mode.modes[idx3] = mode.modes[idx3+1];
            }
        } else {
            idx++;
        }
    }

    return mode;
}