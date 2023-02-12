#include <stdio.h>
#include <stdlib.h>

typedef struct {
    char FName[24], MI, LName[16];
} nameType;

typedef struct {
    nameType name;
    char gender;
} personType;

typedef struct {
    personType people[10];
    int count;
} ArrayList;

typedef struct node{
    personType person;
    struct node *next;
} *LinkList;

void displayArray(ArrayList list);
LinkList getMale(ArrayList *list);
void displayLink(LinkList head);

int main()
{
    ArrayList list = {
        {
            {"Kit", 'O', "Connor", 'M'},
            {"Sebastian", 'D', "Croft", 'M'},
            {"Alice", 'F', "Oseman", 'F'},
            {"Joe", 'N', "Locke", 'M'},
            {"Yasmin", 'Z', "Finney", 'F'}
        },
        5
    };

    displayArray(list);

    LinkList head = getMale(&list);
    printf("\nArray Implementation:\n");
    displayArray(list);
    printf("\nLinked List Implementation:\n");
    displayLink(head);

    return 0;
}

void displayArray(ArrayList list)
{
    int idx;

    for (idx = 0; idx < list.count; idx++){
        printf("%s, %s %c\n", list.people[idx].name.LName, list.people[idx].name.FName, list.people[idx].name.MI);
        printf("%c\n", list.people[idx].gender);
    }
}

LinkList getMale(ArrayList *list)
{
    LinkList head = NULL;
    int idx, idx2;
    LinkList *trav = &head;

    for (idx = list->count-1; idx > -1; idx--){
        if (list->people[idx].gender == 'M'){
            *trav = (LinkList)malloc(sizeof(struct node));
            (*trav)->person = list->people[idx];
            trav = &(*trav)->next;
            for (idx2 = idx; idx2 < list->count-1; idx2++){
                list->people[idx2] = list->people[idx2+1];
            }
            list->count--;
        }
    }
    *trav = NULL;

    return head;
}

void displayLink(LinkList head)
{
    for ( ; head != NULL; head = head->next){
        printf("%s, %s %c\n", head->person.name.LName, head->person.name.FName, head->person.name.MI);
        printf("%c\n", head->person.gender);
    }
}
