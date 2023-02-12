#include <stdio.h>
#include <stdlib.h>

typedef struct node {
    int item;
    struct node *link;
} LL;

int main()
{
    LL *head = (LL *)malloc(sizeof(LL));

    head->item = 5;
    head->link = (LL *)malloc(sizeof(LL));
    head->link->item = 7;
    head->link->link = (LL *)malloc(sizeof(LL));
    head->link->link->item = 6;
    head->link->link->link = NULL;


    return 0;
}