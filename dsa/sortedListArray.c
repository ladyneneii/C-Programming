#include <stdio.h>
#define MAX  0xF

typedef struct node {
    char data[MAX];
    int ctr;  //actual elements in the array
}*arrayList;

int changeLetter(arrayList listPtr, char A, char B);
void sortListAscend(arrayList listPtr);
void insertSorted(arrayList listPtr, char elem);
int deleteAll(arrayList listPtr, char elem);

int main()
{
    struct node list = {
        "abaeqcdfbc",
        10
    };

    printf("Original list: %s\n", list.data);
    int total = changeLetter(&list, 'c', 'b');
    printf("Change c to b: %s\n", list.data);
    printf("Total number of changes: %d\n", total);
    sortListAscend(&list);
    printf("Sorted list in ascending order: %s\n", list.data);
    insertSorted(&list, 'n');
    printf("Sorted list after inserting n: %s\n", list.data);
    int deletedItems = deleteAll(&list, 'b');
    printf("Sorted list after deleting b: %s\n", list.data);
    printf("Number of elements deleted: %d", deletedItems);

    return 0;
}

int changeLetter(arrayList listPtr, char A, char B)
{
    int total = 0, idx;

    for (idx = 0; idx < listPtr->ctr; idx++){
        if (listPtr->data[idx] == A){
            listPtr->data[idx] = B;
            total++;
        }
    }

    return total;
}

void sortListAscend(arrayList listPtr)
{
    int x, y, small;
    char temp;

    for (x = 0; x < listPtr->ctr-1; x++){
        small = x;
        for (y = x+1; y < listPtr->ctr; y++){
            if (listPtr->data[small] > listPtr->data[y]){
                small = y;
            }
        }
        if (listPtr->data[x] > listPtr->data[small]){
            temp = listPtr->data[small];
            listPtr->data[small] = listPtr->data[x];
            listPtr->data[x] = temp;
        }
    }
}

void insertSorted(arrayList listPtr, char elem)
{
    int idx, idx2;

    for (idx = 0; idx < listPtr->ctr && listPtr->data[idx] < elem && listPtr->data[idx] != elem; idx++){}
    if (listPtr->data[idx] == elem){
        printf("Element already exists on the list.\n");
    } else if (listPtr->data[idx] > elem){
        listPtr->ctr++;
        for (idx2 = listPtr->ctr-1; idx < idx2; idx2--){
            listPtr->data[idx2] = listPtr->data[idx2-1];
        }
        listPtr->data[idx] = elem;
    } else {
        listPtr->data[idx] = elem;
    }
}

int deleteAll(arrayList listPtr, char elem)
{
    int idx, idx2, del = 0;

    for (idx = listPtr->ctr-1; idx > -1; idx--){
        if (listPtr->data[idx] == elem){
            del++;
            listPtr->ctr--;
            for (idx2 = idx; idx2 < listPtr->ctr; idx2++){
                listPtr->data[idx2] = listPtr->data[idx2+1];
            }
        }
    }
    listPtr->data[idx2] = '\0';

    return del;
}

/* bubble sort
void ascend(int list[], int length)
{
    int x, y, temp, rem = length;
        
    for (x = 0; x < length-1; x++, rem--){
        for (y = 0; y < rem-1; y++){
            if (list[y] > list[y+1]){
                temp = list[y];
                list[y] = list[y+1];
                list[y+1] = temp;
            }
        }
    }
}
*/