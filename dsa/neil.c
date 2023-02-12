#include <stdio.h>
#define MAX  0xF

    typedef struct node {
        char data[MAX];
        int ctr;  //actual elements in the array
     }*arrayList;
     
     void initList(arrayList *list);
     int changeLetter(arrayList *list, char a, char b);
     void insertSorted (arrayList *list, char x);
     int deleteAll (arrayList *list, char x);
     void displayArray(arrayList L);
     
int main() {
   struct node list;
    arrayList L = &list;
    
    int num;
    int del;
    
    initList(&L);
    insertSorted(&L, 'c');
    insertSorted(&L, 'e');
    insertSorted(&L, 'b');
    insertSorted(&L, 'a');
    insertSorted(&L, 'd');
    insertSorted(&L, 'o');
    insertSorted(&L, '1');
    insertSorted(&L, '3');
    displayArray(L);
    printf("Hello world");
    
    // num = changeLetter(&L,'b', 'a');
    
    return 0;
}

void initList(arrayList *list){
    (*list)->ctr = 0;
}
void insertSorted (arrayList *list, char x){
    char temp;
    if ((*list)->ctr == 0){
    (*list)->data[(*list)->ctr] = x;
    (*list)->ctr++;
    }else{
        // start of added code 
        int idx, idx2;

        for (idx = 0; idx < (*list)->ctr && x > (*list)->data[idx]; idx++){}
        (*list)->ctr++;
        if (idx == (*list)->ctr-1){
            (*list)->data[(*list)->ctr-1] = x;
        } else {
            // these lines of code are for shifting data
            for (idx2 = (*list)->ctr-1; idx2 > idx; idx2--){
                (*list)->data[idx2] = (*list)->data[idx2-1];
            } 
            (*list)->data[idx2] = x;
        }
        // end of added code


        /*
        // erased lines of code:

        if((*list)->data[(*list)->ctr-1] > x){ // this line of code will only compare the last data on the list with x, but to sort the list, you need to compare x with multiple data on the list
            temp = (*list)->data[(*list)->ctr-1];
            (*list)->data[(*list)->ctr-1] = x;
            (*list)->data[(*list)->ctr] = temp;
        } 
         (*list)->ctr++;
         */
    }
}
int changeLetter(arrayList *list, char a, char b){
    int i = 0;
    int count = 0;
    while ((*list)->ctr > i){
        if ((*list)->data[i] == a){
            (*list)->data[i] = b;
            count++;
            i++;
        }else{
    i++;
}
}
 return count;
}

void displayArray(arrayList L)
{
    int idx;

    for (idx = 0; idx < L->ctr; idx++){
        printf("%c ", L->data[idx]);
    }
}