#include <stdio.h>
#define MAX 10

typedef struct {
    int elem, next;
} Nodetype;

typedef struct {
    Nodetype data[MAX];
    int avail;
} List;

List createList();
void visualiseList(List cursor);
void displayList(List cursor, int list);
void insertFront(List *cursor, int *list, int item);
int allocIndex(List *cursor);
void deleteFront(List *cursor, int *list);
void freeIndex(List *cursor, int free);

int main()
{
    List cursor_one = createList();
    int mylist1 = -1, yourlist = -1;

    visualiseList(cursor_one);
    displayList(cursor_one, mylist1);
    insertFront(&cursor_one, &mylist1, 5);
    insertFront(&cursor_one, &yourlist, 10);
    insertFront(&cursor_one, &mylist1, 2);
    insertFront(&cursor_one, &yourlist, 54);
    insertFront(&cursor_one, &mylist1, 87);
    visualiseList(cursor_one);
    displayList(cursor_one, mylist1);
    displayList(cursor_one, yourlist);
    deleteFront(&cursor_one, &mylist1);
    deleteFront(&cursor_one, &yourlist);
    visualiseList(cursor_one);
    displayList(cursor_one, mylist1);
    displayList(cursor_one, yourlist);

    return 0;
}

List createList()
{
    List list = {{}, 9};
    int idx;

    for (idx = MAX-1; idx > -1; idx--){
        list.data[idx].elem = -999;
        list.data[idx].next = idx-1;
    }

    return list;
}

void visualiseList(List cursor)
{
    int idx; 

    printf("%15s | %15s | %15s\n", "INDEX", "ELEM", "NEXT");
    for (idx = 0; idx < MAX; idx++){
        printf("%15d | %15d | %15d\n", idx, cursor.data[idx].elem, cursor.data[idx].next);
    }
}

void displayList(List cursor, int list)
{
    int idx;

    printf("\n\n{");
    for (idx = list; idx != -1; idx = cursor.data[idx].next){
        printf("%d ", cursor.data[idx].elem);
    }
    printf("}");
}

void insertFront(List *cursor, int *list, int item)
{
    int availSpace = allocIndex(cursor);

    cursor->data[availSpace].elem = item;
    cursor->data[availSpace].next = *list;
    *list = availSpace;
}

int allocIndex(List *cursor)
{
    int avail = cursor->avail;

    if (avail != -1){
        cursor->avail = cursor->data[avail].next;
    } else {
        printf("No space available.\n");
    }

    return avail;
}

void deleteFront(List *cursor, int *list)
{
    int del = *list;
    
    *list = cursor->data[*list].next;
    freeIndex(cursor, del);
}

void freeIndex(List *cursor, int free)
{
    cursor->data[free].elem = -999;
    cursor->data[free].next = cursor->avail;
    cursor->avail = free;
}