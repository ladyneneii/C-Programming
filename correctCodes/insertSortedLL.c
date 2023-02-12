#include <stdio.h>
#include <stdlib.h>

typedef struct cell {
    char elem;
    struct cell *next;
} *LL;

void insertSorted(LL *headptr, char x);
void display(LL head);

int main()
{
    LL head = NULL;

    insertSorted(&head, 'I');
    insertSorted(&head, 'A');
    insertSorted(&head, 'M');
    insertSorted(&head, 'S');
    insertSorted(&head, 'O');
    insertSorted(&head, 'G');
    insertSorted(&head, 'A');
    insertSorted(&head, 'Y');
    display(head);

    return 0;
}

void insertSorted(LL *headptr, char x)
{
    LL temp = (LL)malloc(sizeof(struct cell));

    temp->elem = x;
    for ( ; *headptr != NULL && (*headptr)->elem < x; headptr = &(*headptr)->next){}
    temp->next = *headptr;
    *headptr = temp;
}

void display(LL head)
{
    for ( ; head != NULL; head = head->next){
        printf("%c ", head->elem);
    }
}