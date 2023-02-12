#include <stdio.h>
#include <stdlib.h>
#define TRUE 1
#define FALSE 2

typedef struct {
    int count, max, *items;
} List;

typedef int Boolean;

List createList(int max);
void insertFront(List *list, int item);
void insertRear(List *list, int item);
Boolean deleteItem (List *list, int item);
Boolean deleteFront (List *list);
Boolean deleteRear (List *list);
void displayList(List list);

int main()
{
    List myList = createList(6);

    insertFront(&myList, 89);
    printf("List after inserting 89 at the front:\n");
    displayList(myList);
    printf("\n\n");

    insertRear(&myList, 69);
    printf("List after inserting 69 at the rear:\n");
    displayList(myList);
    printf("\n\n");

    if (deleteItem(&myList, 5) == 1){
        printf("One item deleted.\n");
    } else {
        printf("No item deleted.\n");
    }
    printf("List after deleting 5:\n");
    displayList(myList);
    printf("\n\n");

    if (deleteFront(&myList) == 1){
        printf("One item deleted.\n");
    } else {
        printf("No item deleted.\n");
    }
    printf("List after deleting the item at the front:\n");
    displayList(myList);
    printf("\n\n");

    if (deleteRear(&myList) == 1){
        printf("One item deleted.\n");
    } else {
        printf("No item deleted.\n");
    }
    printf("List after deleting the item at the rear:\n");
    displayList(myList);
    printf("\n\n");

    return 0;
}

List createList(int max)
{
    List myList = {5, max, (int *)malloc(max * sizeof(int))};
    
    myList.items[0] = 3;
    myList.items[1] = 4;
    myList.items[2] = 5;
    myList.items[3] = 6;
    myList.items[4] = 7;

    return myList;
}

void insertFront(List *list, int item)
{
    int trav;

    if (list->count++ <= list->max){
        for (trav = list->count - 1; trav > 0; trav--){
            list->items[trav] = list->items[trav-1];
        }
        list->items[trav] = item;
    } else {
        list->max = list->count;
        list->items = (int *)realloc(list->items, list->max * sizeof(int));
        for (trav = list->count - 1; trav > 0; trav--){
            list->items[trav] = list->items[trav-1];
        }
        list->items[trav] = item;
    }
}

void displayList(List list)
{
    int idx;
    
    for(idx = 0; idx < list.count; idx++){
        printf("%d ", list.items[idx]);
    }
}

void insertRear(List *list, int item)
{
    if (list->count++ <= list->max){
        list->items[list->count-1] = item;
    } else {
        list->max = list->count;
        list->items = (int *)realloc(list->items, list->max * sizeof(int));
        list->items[list->count-1] = item;
    }
}

Boolean deleteItem (List *list, int item)
{
    int trav;

    for(trav = 0; trav < list->count && list->items[trav] != item; trav++){}
    if (trav < list->count){
        for (list->count--; trav < list->count; trav++){
            list->items[trav] = list->items[trav+1];
        }
        
        return TRUE;
    } else {
        return FALSE;
    }
}

Boolean deleteFront (List *list)
{
    int trav;

    if (list->count == 0){
        return FALSE;
    } else {
        for(trav = 0, list->count--; trav < list->count; trav++){
            list->items[trav] = list->items[trav+1];
        }

        return TRUE;
    }
}

Boolean deleteRear (List *list)
{
    int trav;

    if (list->count == 0){
        return FALSE;
    } else {
        list->count--;

        return TRUE;
    }
}