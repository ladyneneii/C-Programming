#include <stdio.h>
#define MAX 20

typedef struct {
    int elem[MAX];
    int lastNdx;
    int old;
}BST;

void insert(BST *T, int x);
void initialize(BST *T);
void display(BST *T);
void heapify(BST *T);
int deleteMin(BST *T);

int main() {
    BST T;
    initialize(&T);
    insert(&T, 1);
    insert(&T, 2);
    insert(&T, 3);
    display(&T);
    printf("\n");
    heapify(&T);
    display(&T);
    printf("\n");
    deleteMin(&T);

    
    display(&T);
    return 0;
}

void initialize(BST *T) {
    T->lastNdx = -1;
}

void insert(BST *T, int x) {
    T->lastNdx++;
    T->elem[T->lastNdx] = x;
    T->old = T->lastNdx;
}

void display(BST *T) {
    int x;
    int length = T->old;
    for (x = 0; x <= length; x++) {
        printf("%d ", T->elem[x]);
    }
}

void heapify(BST *T) {
    int indexholder, temp;
    int lastParentIndex = (T->lastNdx - 1) / 2;
    int internSort = lastParentIndex;
    int lc = lastParentIndex * 2 + 1;
    int rc = lastParentIndex * 2 + 2;
    while (lastParentIndex >= 0) {
        rc = internSort * 2 + 2;
        lc = internSort * 2 + 1;
       while((rc <= T->lastNdx && T->elem[internSort] > T->elem[rc]) || ((rc <= T->lastNdx) && T->elem[internSort] > T->elem[lc])) {
            if(T->elem[rc] < T->elem[lc]) {
                temp = T->elem[rc];
                T->elem[rc] = T->elem[internSort];
                T->elem[internSort] = temp;
                internSort = rc;
                rc = internSort * 2 + 2;
                lc = internSort * 2 + 1;
            } else {
                temp = T->elem[lc];
                T->elem[lc] = T->elem[internSort];
                T->elem[internSort] = temp;
                internSort = lc;
                rc = internSort * 2 + 2;
                lc = internSort * 2 + 1;
            }
       }
       lastParentIndex--;
       internSort = lastParentIndex;
    }
}

int deleteMin(BST *T) {
    int pi, lc, rc, temp, smallest;
    pi = 0;
    smallest = T->elem[0];
    temp = T->elem[T->lastNdx]; // gets value of last index
    T->elem[T->lastNdx] = T->elem[pi]; // replaces last index with smallest
    T->elem[pi] = temp; // replaces smallest index with new value
    lc = 1;
    rc = 2;
    T->lastNdx--;
    while((rc <= T->lastNdx && T->elem[pi] > T->elem[lc]) || (rc <= T->lastNdx &&  T->elem[pi] > T->elem[rc])) { // compares if pi is bigger than lc and rc
        if (T->elem[lc] <= T->elem[rc]) {
            temp = T->elem[lc];
            T->elem[lc] = T->elem[pi];
            T->elem[pi] = temp;
            pi = lc;
            lc = pi * 2 + 1;
            rc = pi * 2 + 2;
        } else {
            temp = T->elem[rc];
            T->elem[rc] = T->elem[pi];
            T->elem[pi] = temp;
            pi = rc;
            lc = pi * 2 + 1;
            rc = pi * 2 + 2;
        }
    }
    if (lc == 1 && T->elem[0] < T->elem[lc]) {
        temp = T->elem[lc];
        T->elem[lc] = T->elem[0];
        T->elem[0] = temp;
    }
    return smallest;
}
