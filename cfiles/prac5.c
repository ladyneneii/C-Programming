#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct{
    char LName[32];
    char Mi;
    char FName[32];
} Nametype;

typedef struct{
    Nametype name;
    int age;
    char course[32];
} Infotype;

typedef struct node{
    Infotype student;
    struct node *link;
} Linktype, * Linkptr;

typedef struct cell{
    char elem;
    struct cell *next;
} Celltype, * Cellptr;

Cellptr createCell();
void displayCell(Cellptr ptr);
void swapCell(Cellptr *ptr);
void swapCell2(Cellptr *ptr, char letter, int num);

int main()
{
    Cellptr head = createCell();

    displayCell(head);
    printf("\n\n\n");
    swapCell(&head);
    displayCell(head);
    printf("\n\n\n");
    swapCell2(&head, 'T', 4);
    displayCell(head);
}

Cellptr createCell()
{
    Cellptr head = (Cellptr)malloc(sizeof(Celltype));
    head->elem = 'B';
    head->next = (Cellptr)malloc(sizeof(Celltype));
    head->next->elem = 'T';
    head->next->next = (Cellptr)malloc(sizeof(Celltype));
    head->next->next->elem = 'C';
    head->next->next->next = (Cellptr)malloc(sizeof(Celltype));
    head->next->next->next->elem = 'H';
    head->next->next->next->next = (Cellptr)malloc(sizeof(Celltype));
    head->next->next->next->next->elem = 'I';
    head->next->next->next->next->next = NULL;

    return head;
}

void displayCell(Cellptr ptr)
{
    for( ; ptr != NULL; ptr = ptr->next){
        printf("%c ", ptr->elem);
    }
}

void swapCell(Cellptr *ptr)
{
    Cellptr temp;

    for( ; (*ptr)->elem != 'H'; ptr = &(*ptr)->next){}
    temp = *ptr;
    *ptr = (*ptr)->next;
    (*ptr)->next = temp;
    temp->next = NULL;
}

void swapCell2(Cellptr *ptr, char letter, int num)
{
    int idx;
    Cellptr *ptr2 = ptr, temp, temp2, temp3;

    for( ; (*ptr)->elem != letter; ptr = &(*ptr)->next){}
    for(idx = 1; idx < num; ptr2 = &(*ptr2)->next, idx++){}
    temp = (*ptr)->next;
    temp2 = (*ptr2)->next;
    temp3 = *ptr;
    *ptr = *ptr2;
    *ptr2 = temp3;
    (*ptr)->next = temp;
    (*ptr2)->next = temp2;
}

