/*
#include <stdio.h>

void bubbleAscend(int sort[])
{
    int y, x, temp;
    
    for(y = 0; y < 10-1; y++){
        for(x = 0; x < 10; x++){
            if(sort[x] > sort[x+1]){
                temp = sort[x];
                sort[x] = sort[x+1];
                sort[x+1] = temp;
            }
        }
    }
}

int main()
{
    int num[10] = {2, 4, 6, 6, 3, 9, 0, 2, 4, 9}, x;

    bubbleAscend(num);

    for(x = 0; x < 10; x++){
        printf("%d ", num[x]);
    }
    
    return 0;
}
*/

/*
#include <stdio.h>

void insertDescend(int sort[])
{
    int big, x, y, temp;

    for(x = 0; x < 10-1; x++){
        big = x;
        for(y = x+1; y < 10; y++){
            if (sort[big] < sort[y]){
                big = y;
            }
        }
        if (sort[x] < sort[big]){
            temp = sort[x];
            sort[x] = sort[big];
            sort[big] = temp;
        }
    }
    
}

int main()
{
    int x, num[10] = {2, 5, 6, 8, 1, 2, 7, 9, 3, 9};

    insertDescend(num);

    for(x = 0; x < 10; x++){
        printf("%d ", num[x]);
    }

    return 0;
}
*/

#include <stdio.h>

void shiftingAscend(int sort[])
{
    int x, y, temp;

    for(x = 0; x < 10-1; x++){
        for(y = x; y > -1 && sort[y] > sort[y+1]; y--){
            temp = sort[y];
            sort[y] = sort[y+1];
            sort[y+1] = temp;
        }
    }
}

int main()
{
    int x, num[10] = {2, 5, 6, 8, 1, 2, 7, 9, 3, 9};

    shiftingAscend(num);

    for(x = 0; x < 10; x++){
        printf("%d ", num[x]);
    }

    return 0;
}
