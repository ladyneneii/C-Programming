#include <stdio.h>
#include <stdlib.h>

typedef struct node{
    char elem;
    struct node *link;
} nodetype, *LIST;

void displayLList(LIST ptr);
void insertLList(int num, char elem, LIST *ptr); //pointer-to-pointer-to-node
void insertListV2(int num, char elem, LIST ptr); //pointer-to-node

int main()
{
    LIST head = (LIST)malloc(sizeof(nodetype));
    
    head->elem = 'B';
    head->link = (LIST)malloc(sizeof(nodetype));
    head->link->elem = 'U';
    head->link->link = (LIST)malloc(sizeof(nodetype));
    head->link->link->elem = 'S';
    head->link->link->link = (LIST)malloc(sizeof(nodetype));
    head->link->link->link->elem = 'S';
    head->link->link->link->link = (LIST)malloc(sizeof(nodetype));
    head->link->link->link->link->elem = 'Y';
    head->link->link->link->link->link = NULL;

    displayLList(head);
    insertLList(3, 'T', &head);
    displayLList(head);
    insertListV2(5, 'L', head);
    displayLList(head);

    return 0;
}

void displayLList(LIST ptr)
{
    for( ; ptr != NULL; ptr = ptr->link){
        printf("%c ", ptr->elem);
    }
    printf("\n");
}

void insertLList(int num, char elem, LIST *ptr)
{
    int pos;
    LIST temp;

    for(pos = 0; pos < num-1; pos++, ptr = &(*ptr)->link){}
    temp = *ptr;
    *ptr = (LIST)malloc(sizeof(nodetype));
    (*ptr)->elem = elem;
    (*ptr)->link = temp;
}

void insertListV2(int num, char elem, LIST ptr)
{
    int pos;
    LIST temp;

    for(pos = 0; pos < num-2; pos++, ptr = ptr->link){}
    temp = ptr->link;
    ptr->link = (LIST)malloc(sizeof(nodetype));
    ptr->link->elem = elem;
    ptr->link->link = temp;
}