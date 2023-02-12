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

void displayRecords(ArrayList list);
LinkList getMale(ArrayList *list);
void displayLink(LinkList head);

int main()
{
    ArrayList records = 
    {
        {
            {"Marc", 'C', "Bryan", 'M'},
            {"Reese", 'T', "Besanez", 'F'},
            {"Reene", 'T', "Besanez", 'F'},
            {"Gimari", 'G', "Baynosa", 'F'},
            {"Ernest", 'S', "Curativo", 'M'},
        }, 
        5
    };

    printf("All people in the array:\n");
    displayRecords(records);
    LinkList head = getMale(&records);

    /*
    printf("\nAll people on the linked list:\n");
    displayLink(head);
    printf("\nAll people in the array:\n");
    displayRecords(records);
    */

    return 0;
}

void displayRecords(ArrayList list)
{
    int idx; 

    for (idx = 0; idx < list.count; idx++){
        printf("%s, %s %c\n", list.people[idx].name.LName, list.people[idx].name.FName, list.people[idx].name.MI);
        printf("%c\n", list.people[idx].gender);
    }
}

LinkList getMale(ArrayList *list)
{
    int idx, idx2, rem; 
    
    LinkList head = NULL;
    /*
    LinkList *trav = &head;
    */

    for (idx = 0, rem = list->count; idx < list->count; idx++){
        if (list->people[idx].gender == 'M'){
            /*
            *trav = (LinkList)malloc(sizeof(struct node));
            (*trav)->person = list->people[idx];
            trav = &(*trav)->next;
            */
            list->count--;
            rem--;
            for (idx2 = idx; idx < rem; idx2++){
                list->people[idx2] = list->people[idx2+1];
            }
        } else {
            rem--;
        }
    }
    // *trav = NULL;

    return head;
}

void displayLink(LinkList head)
{
    for ( ; head != NULL; head = head->next){
        printf("%s, %s %c\n", head->person.name.LName, head->person.name.FName, head->person.name.MI);
        printf("%c\n", head->person.gender);
    }
}