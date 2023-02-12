#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct node{
    char name[20];
    struct node *link;
} nodetype, * nodeptr;

void displayLList(nodeptr ptr);
void swapLLIst(nodeptr *ptr, int pos, int pos2);

int main()
{
    nodeptr head = (nodeptr)malloc(sizeof(nodetype));
    nodeptr second = (nodeptr)malloc(sizeof(nodetype));
    nodeptr third = (nodeptr)malloc(sizeof(nodetype));
    nodeptr fourth = (nodeptr)malloc(sizeof(nodetype));
    nodeptr fifth = (nodeptr)malloc(sizeof(nodetype));

    strcpy(head->name, "Nene");
    strcpy(second->name, "Josh");
    strcpy(third->name, "Shamel");
    strcpy(fourth->name, "Sean");
    strcpy(fifth->name, "Neil");

    head->link = second;
    second->link = third;
    third->link = fourth;
    fourth->link = fifth;
    fifth->link = NULL;

    displayLList(head);
    swapLLIst(&head, 2, 3);
    printf("\n\nAfter swap\n\n");
    displayLList(head);

    return 0;
}

void displayLList(nodeptr ptr)
{
    for( ; ptr != NULL; ptr = ptr->link){
        printf("%s\n", ptr->name);
    }
}

void swapLLIst(nodeptr *ptr, int pos, int pos2)
{
    int idx;
    nodeptr *ptr2 = ptr;

    for(idx = 1; idx < pos; ptr = &(*ptr)->link, idx++){}
    for(idx = 1; idx < pos2; ptr2 = &(*ptr2)->link, idx++){}
    nodeptr nodeAfterPos = (*ptr)->link;
    nodeptr nodeAfterPos2 = (*ptr2)->link;
    nodeptr temp = *ptr;
    *ptr = *ptr2;
    *ptr2 = temp;
    (*ptr)->link = nodeAfterPos;
    (*ptr2)->link = nodeAfterPos2;
}





/*
void swapLLIst(nodeptr *ptr, int pos, int pos2)
{
    int idx;
    nodeptr *ptr2 = ptr;

    for(idx = 1; idx < pos; ptr = &(*ptr)->link, idx++){}
    for(idx = 1; idx < pos2; ptr2 = &(*ptr2)->link, idx++){}
    nodeptr temp = *ptr;
    nodeptr temp2 = *ptr2;
    nodeptr temp3 = temp->link;
    nodeptr temp4 = temp2->link;
    *ptr = temp2;
    *ptr2 = temp;
    (*ptr)->link = temp3;
    (*ptr2)->link = temp4;

}
*/


/*
void insertLLIst(nodeptr *ptr, int pos, int pos2)
{
    nodeptr *ptr2 = ptr;
    int idx; 

    for(idx = 1; idx < pos; ptr = &(*ptr)->link, idx++){}
    for(idx = 1; idx < pos2; ptr2 = &(*ptr2)->link, idx++){}
    nodeptr temp = (*ptr2)->link;
    nodeptr temp2 = *ptr;
    *ptr = *ptr2;
    (*ptr2)->link = temp2;
    *ptr2 = temp;
}
*/