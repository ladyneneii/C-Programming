#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX 30

typedef struct{
    char Fname[24];
    char Mi;
    char Lname[24];
} nameType;

typedef struct node{
    nameType name;
    struct node *next;
} nodetype, *nameList;

typedef struct{
    nameType students[MAX];
    int count;
} arrayList;

// Linked List
void getNames(nameList ptr);
void getNames2(nameList ptr);
void getNames3(nameList ptr);
void getNames4(nameList ptr);
void displayNames(nameList ptr); 
void changeList(nameList ptr); //change last name: pass by copy, pointer-to-node
void insertName(nameList *ptr, int p); //insert an element: pass by address, pointer-to-pointer-to-node
void ascendLinked(nameList ptr);

// Array Implementation
void outputNames(arrayList R);
void alterList(arrayList *R); //change last name: pass by address 
void insertStudent(arrayList *R, int p); //insert an element: pass by address


int main()
{
    nameList head = (nameList)malloc(sizeof(nodetype));

    getNames(head);
    head->next = (nameList)malloc(sizeof(nodetype));
    getNames2(head->next);
    head->next->next = (nameList)malloc(sizeof(nodetype));
    getNames3(head->next->next);
    head->next->next->next = (nameList)malloc(sizeof(nodetype));
    getNames4(head->next->next->next);
    head->next->next->next->next = NULL;

    displayNames(head);
    changeList(head);
    displayNames(head);

    arrayList L = {{{"Jeffree", 'T', "Star"}, {"James", 'J', "Charles"}, {"Shane", 'L', "Dawson"}, {"Sean", 'T', "Piamonte"}}, 4};

    outputNames(L);
    alterList(&L);
    outputNames(L);

    insertName(&head, 3);
    displayNames(head);

    insertStudent(&L, 5);
    outputNames(L);

    ascendLinked(head);

    return 0;
}

void getNames(nameList ptr)
{
    strcpy(ptr->name.Fname, "Ernest");
    ptr->name.Mi = 'S';
    strcpy(ptr->name.Lname, "Curativo");
}

void getNames2(nameList ptr)
{
    strcpy(ptr->name.Fname, "Neil");
    ptr->name.Mi = 'S';
    strcpy(ptr->name.Lname, "Sagun");
}

void getNames3(nameList ptr)
{
    strcpy(ptr->name.Fname, "Sherly");
    ptr->name.Mi = 'R';
    strcpy(ptr->name.Lname, "Jao");
}

void getNames4(nameList ptr)
{
    strcpy(ptr->name.Fname, "Nicole");
    ptr->name.Mi = 'T';
    strcpy(ptr->name.Lname, "Villarin");
}

/*
void displayNames(nameList ptr)
{
    nameList trav;

    for(trav = ptr; trav != NULL; trav = trav->next){
        printf("%s, %s %c\n", trav->name.Lname, trav->name.Fname, trav->name.Mi);
    }
}
*/

void displayNames(nameList ptr)
{
    for( ; ptr != NULL; ptr = ptr -> next){
        printf("%s, %s %c\n", ptr->name.Lname, ptr->name.Fname, ptr->name.Mi);
    }
    printf("\n");
}

void changeList(nameList ptr)
{
    for( ; ptr != NULL; ptr = ptr -> next){
        if(strcmp(ptr->name.Lname, "Curativo") == 0){
            strcpy(ptr->name.Lname, "Stewart");
        }
    }
}

void outputNames(arrayList R)
{
    int idx;

    for(idx = 0; idx < R.count; idx++){
        printf("%s, %s %c\n", R.students[idx].Lname, R.students[idx].Fname, R.students[idx].Mi);
    }
    printf("\n");
}

void alterList(arrayList *R)
{
    int idx;

    for(idx = 0; idx < R->count; idx++){
        if(strcmp(R->students[idx].Lname, "Charles") == 0){
            strcpy(R->students[idx].Lname, "PDF-File");
        }
    }
}

void insertName(nameList *ptr, int p)
{
    int count;
    nameList temp;

    for(count = 0; count < p; count++, ptr = &(*ptr) -> next){}
    temp = *ptr;
    *ptr = (nameList)malloc(sizeof(nodetype));
    strcpy((*ptr)->name.Fname, "Freddy");
    (*ptr) -> name.Mi = 'D';
    strcpy((*ptr)->name.Lname, "Mercury");
    (*ptr) -> next = temp;
}

void insertStudent(arrayList *R, int p)
{
    int idx; 

    if (R -> count++ < MAX){
        for(idx = R -> count - 1; idx > p - 1; idx--){
            R -> students[idx] = R -> students[idx - 1];
        }
        strcpy(R -> students[p-1].Fname, "Conan");
        R -> students[p-1].Mi = 'G';
        strcpy(R -> students[p-1].Lname, "Gray");
    }
}

void ascendLinked(nameList ptr)
{
    int x, y, temp;

    for(x = 0; x < 10-1; x++){
        for(y = 0; y < 10; y++){
            if(sort[y] > sort[y+1]){
                temp = sort[y];
                sort[y] = sort[y+1];
                sort[y+1] = temp;
            }
        }
    }

    int x;

    nameList temp = ptr -> next;
    for(x = 0; x < 10-1; x++){
        for( ; ptr != NULL; ptr = ptr -> next){
            
            if(strcmp(ptr -> name.Lname, ptr -> next -> name.Lname) > 0){
                ptr -> next = ptr -> next -> next;
                temp -> next = ptr;
                ptr = temp;
                temp = temp -> next -> next;
            }
        }
    }
}