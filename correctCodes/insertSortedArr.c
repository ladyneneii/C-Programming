#include <stdio.h>
#include <stdlib.h>
#define size 10

typedef struct cell {
    char *elem;
    int count;
} *Arr;

void insertSorted(Arr listptr, char x);
void display(Arr listptr);

int main()
{
    Arr list = (Arr)malloc(sizeof(struct cell));

    list->elem = (char *)malloc(size*sizeof(char));
    list->count = 0; 

    insertSorted(list, 'I');
    insertSorted(list, 'A');
    insertSorted(list, 'M');
    insertSorted(list, 'S');
    insertSorted(list, 'O');
    insertSorted(list, 'G');
    insertSorted(list, 'A');
    insertSorted(list, 'Y');
    display(list);

    return 0;
}

void insertSorted(Arr listptr, char x)
{
    int idx, idx2;

    for (idx = 0; idx < listptr->count && listptr->elem[idx] < x; idx++){}
    for (idx2 = listptr->count; idx2 > idx; idx2--){
        listptr->elem[idx2] = listptr->elem[idx2-1];
    }
    listptr->elem[idx] = x;
    listptr->count++;
}

void display(Arr listptr)
{
    int idx;
    
    for (idx = 0; idx < listptr->count; idx++){
        printf("%c ", listptr->elem[idx]);
    }
}