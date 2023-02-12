#include <stdio.h>
#include <stdlib.h>

int **checkValidity(int credCards[][16]);

int main()
{
    int credCards[10000][16] = {
        {2, 9, 7, 2, 0, 4, 1, 3, 9, 5, 3, 2, 1, 7, 8, 3},
        {5, 2, 3, 4, 8, 2, 1, 3, 3, 4, 1, 0, 1, 2, 9, 8}, 
        {3, 8, 2, 1, 9, 4, 0, 2, 7, 2, 1, 9, 4, 9, 2, 1},
        -1
    }, x, y, **resultCards;

    resultCards = checkValidity(credCards);

    for (y = x = 0; resultCards[x][y] != -1; x++, y = 0){
        for ( ; y < 16; y++){
            printf("%d ", resultCards[x][y]);
        }
        printf("%c\n", resultCards[x][y]);
    }
    printf("%d", resultCards[x][y]);

    return 0;
}

int **checkValidity(int credCards[][16])
{
    int x, y, sum = 0;
    int **resultCards = (int **)malloc(10000 * sizeof(int *));

    for(x = y = 0; credCards[x][y] != -1; x++, y = sum = 0){
        resultCards[x] = (int *)malloc(17 * sizeof(int));
        for( ; y < 16; y++){
            resultCards[x][y] = credCards[x][y];
            if(y % 2 == 0){
                if(resultCards[x][y] * 2 >= 10){
                    sum += resultCards[x][y] * 2 % 10 + 1;
                } else {
                    sum += resultCards[x][y] * 2;
                }
            } else {
                sum += resultCards[x][y];
            }
        }
        resultCards[x][y] = (sum % 10 == 0) ? 'V' : 'I';
    }
    resultCards[x] = (int *)malloc(17 * sizeof(int));
    resultCards[x][y] = -1;

    return resultCards;
}