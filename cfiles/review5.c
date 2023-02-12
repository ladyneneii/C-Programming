// Online C compiler to run C program online
#include <stdio.h>
#include <stdlib.h>
typedef struct number{
    int num;
    struct number* nextnum;
}numNode,*numList;

void moveAtoB(numList *A, numList B);

int main() {
    numNode *A;
    A = (numList)malloc(sizeof(numNode));
    A->num = 1;
    A->nextnum = (numList)malloc(sizeof(numNode));
    A->nextnum->num = 2;
    A->nextnum->nextnum = (numList)malloc(sizeof(numNode));
    A->nextnum->nextnum->num = 3;
    A->nextnum->nextnum->nextnum = (numList)malloc(sizeof(numNode));
    A->nextnum->nextnum->nextnum->num = 4;
    A->nextnum->nextnum->nextnum->nextnum = (numList)malloc(sizeof(numNode));
    A->nextnum->nextnum->nextnum->nextnum->num = 5;
    A->nextnum->nextnum->nextnum->nextnum->nextnum = NULL;
    numNode *B = (numList)malloc(sizeof(numNode));
    B->num = 6;
    B->nextnum = (numList)malloc(sizeof(numNode));
    B->nextnum->num = 7;
    B->nextnum->nextnum = (numList)malloc(sizeof(numNode));
    B->nextnum->nextnum->num = 8;
    B->nextnum->nextnum->nextnum = (numList)malloc(sizeof(numNode));
    B->nextnum->nextnum->nextnum->num = 9;
    B->nextnum->nextnum->nextnum->nextnum = NULL;

    moveAtoB(&A, B);

    return 0;
}
void moveAtoB(numList *A, numList B)
{
    numList* trav, x;
    for(trav = &B->nextnum->nextnum->nextnum->nextnum; *A != NULL;){
        *trav = *A;
        *A = NULL;
    }
    
    for(x = B; x != NULL; x = x->nextnum){
        printf("%d ", x->num);
    }

}