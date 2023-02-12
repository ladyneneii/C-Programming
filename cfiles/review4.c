#include <stdio.h>
#include <stdlib.h>
#define MAX 30

typedef struct term{
    int coe, expo;
    struct term *ptr;
} *polynomial;

typedef struct{
    char str1[MAX];
    char str2[MAX];
    char extras[MAX];
} twostrings;

int polyResult(int X, polynomial poly);
int recString(twostrings strings);

int main()
{
    // Problem A

    polynomial poly = (polynomial)malloc(sizeof(struct term));

    poly->coe = 3;
    poly->expo = 4;
    poly->ptr = (polynomial)malloc(sizeof(struct term));

    poly->ptr->coe = 2;
    poly->ptr->expo = 3;
    poly->ptr->ptr = (polynomial)malloc(sizeof(struct term));

    poly->ptr->ptr->coe = -7;
    poly->ptr->ptr->expo = 1;
    poly->ptr->ptr->ptr = (polynomial)malloc(sizeof(struct term));

    poly->ptr->ptr->ptr->coe = 5;
    poly->ptr->ptr->ptr->expo = 0;
    poly->ptr->ptr->ptr->ptr = NULL;

    printf("%d\n", polyResult(2, poly));

    // Problem B

    twostrings sample = {
        "SKIDOODLE", "SKIDDADLE", ""
    };

    printf("%d\n", recString(sample));

    return 0;
}

int polyResult(int X, polynomial poly)
{
    int result, idx, power;

    for(result = 0; poly != NULL; poly = poly->ptr){
        for(idx = 0, power = 1; idx < poly->expo; idx++){
            power *= X;
        }
        result += power * poly->coe;
    }

    return result;
}

int recString(twostrings strings)
{
    char temp[30];
    int idx, idx2, idx3 = 0;

    for(idx = 0; strings.str1[idx] != '\0'; idx++){
        temp[idx] = strings.str1[idx];
    }
    temp[idx] = '\0';

    for(idx = 0; strings.str2[idx] != '\0'; idx++){
        for(idx2 = 0; temp[idx2] != '\0' && strings.str2[idx] != temp[idx2]; idx2++){}
        if(temp[idx2] != '\0'){
            strings.extras[idx3] = strings.str2[idx];
            idx3++;
        } else {
            temp[idx2] = 0;
        }
    }

    return (strings.extras[0] == '\0') ? 1 : 0;
}