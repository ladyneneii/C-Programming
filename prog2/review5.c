#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct{
    char FName[32];
    char Mi;
    char LName[32];
} Nametype;

typedef struct node {
    Nametype name;
    struct node *link;
} Celltype, *Cellptr;

Cellptr createList();
void displayList(Cellptr head);
void descend(Cellptr *headptr);
void insertList(Cellptr *headptr, char FName[], char Mi, char LName[]);
void deleteList(Cellptr *headptr, char LName[]);

int main()
{
    Cellptr head = createList();
    displayList(head);
    descend(&head);
    displayList(head);
    insertList(&head, "Charlie", 'D', "Spring");
    displayList(head);
    deleteList(&head, "Finney");
    displayList(head);

    return 0;
}

Cellptr createList()
{
    Cellptr head = (Cellptr)malloc(sizeof(Celltype));

    strcpy(head->name.FName, "Kit");
    head->name.Mi = 'S';
    strcpy(head->name.LName, "Connor");
    head->link = (Cellptr)malloc(sizeof(Celltype));

    strcpy(head->link->name.FName, "Joe");
    head->link->name.Mi = 'W';
    strcpy(head->link->name.LName, "Locke");
    head->link->link = (Cellptr)malloc(sizeof(Celltype));

    strcpy(head->link->link->name.FName, "William");
    head->link->link->name.Mi = 'D';
    strcpy(head->link->link->name.LName, "Gao");
    head->link->link->link = (Cellptr)malloc(sizeof(Celltype));

    strcpy(head->link->link->link->name.FName, "Yasmin");
    head->link->link->link->name.Mi = 'T';
    strcpy(head->link->link->link->name.LName, "Finney");
    head->link->link->link->link = NULL;

    return head;
}

void displayList(Cellptr head)
{
    for ( ; head != NULL; head = head->link){
        printf("%s, %s %c\n", head->name.LName, head->name.FName, head->name.Mi);
    }
    printf("\n\n");
}

void descend(Cellptr *headptr)
{
    Cellptr big, trav;
    Nametype temp;

    for ( ; *headptr != NULL; headptr = &(*headptr)->link){
        big = *headptr;
        for (trav = (*headptr)->link; trav != NULL; trav = trav->link){
            if (strcmp(trav->name.LName, big->name.LName) > 0){
                big = trav;
            }
        }
        if (strcmp(big->name.LName, (*headptr)->name.LName) > 0){
            temp = big->name;
            big->name = (*headptr)->name;
            (*headptr)->name = temp;
        }
    }
}

void insertList(Cellptr *headptr, char FName[], char Mi, char LName[])
{
    Cellptr temp = (Cellptr)malloc(sizeof(Celltype));
    strcpy(temp->name.FName, FName);
    temp->name.Mi = Mi;
    strcpy(temp->name.LName, LName);

    for ( ; *headptr != NULL && strcmp(LName, (*headptr)->name.LName) < 0; headptr = &(*headptr)->link){}
    temp->link = *headptr;
    *headptr = temp;
}

void deleteList(Cellptr *headptr, char LName[])
{
    Cellptr temp;

    for ( ; *headptr != NULL && strcmp((*headptr)->name.LName, LName) != 0; headptr = &(*headptr)->link){}
    temp = *headptr;
    *headptr = (*headptr)->link;
    free(temp);
}