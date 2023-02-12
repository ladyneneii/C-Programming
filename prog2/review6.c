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
Cellptr createList2();
void displayList(Cellptr head);
void connectList(Cellptr *head, Cellptr *head2);

int main()
{
    Cellptr head = createList();
    printf("head content:\n");
    displayList(head);
    Cellptr head2 = createList2();
    printf("head2 content:\n");
    displayList(head2);
    connectList(&head, &head2);
    printf("After connecting: \n");
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

Cellptr createList2()
{
    Cellptr head = (Cellptr)malloc(sizeof(Celltype));

    strcpy(head->name.FName, "Nick");
    head->name.Mi = 'S';
    strcpy(head->name.LName, "Nelson");
    head->link = (Cellptr)malloc(sizeof(Celltype));

    strcpy(head->link->name.FName, "Charlie");
    head->link->name.Mi = 'W';
    strcpy(head->link->name.LName, "Spring");
    head->link->link = (Cellptr)malloc(sizeof(Celltype));

    strcpy(head->link->link->name.FName, "Tao");
    head->link->link->name.Mi = 'D';
    strcpy(head->link->link->name.LName, "Xu");
    head->link->link->link = (Cellptr)malloc(sizeof(Celltype));

    strcpy(head->link->link->link->name.FName, "Elle");
    head->link->link->link->name.Mi = 'T';
    strcpy(head->link->link->link->name.LName, "Ardent");
    head->link->link->link->link = NULL;

    return head;
}

void displayList(Cellptr head)
{
    if (head != NULL){
        for ( ; head != NULL; head = head->link){
            printf("%s, %s %c\n", head->name.LName, head->name.FName, head->name.Mi);
        }
    } else {
        printf("No results found.\n");
    }
    printf("\n\n");
}

void connectList(Cellptr *head, Cellptr *head2)
{
    for ( ; *head != NULL; head = &(*head)->link){}
    *head = *head2;
    // *head2 = NULL;
}