#include <stdio.h>
#include <stdlib.h>

struct node {
    int num;
    struct node *next;
};

void inputArr(int arr[]);
void displayArr(int arr[]);
struct node *getComposite(int arr[]);
void descendLink(struct node *head);
void displayLink(struct node *head);

int main()
{
    int arr[10];

    inputArr(arr);
    displayArr(arr);
    
    struct node *head = getComposite(arr);
    displayArr(arr);
    printf("\n\n");
    descendLink(head);
    displayLink(head);

    return 0;
}

void inputArr(int arr[])
{
    int idx; 

    printf("\nEnter 10 numbers: \n");
    for (idx = 0; idx < 10; idx++){
        scanf("%d", arr+idx);
    }
}

void displayArr(int arr[])
{
    int idx;
    
    printf("\nContent of the array:\n");
    for (idx = 0; idx < 10; idx++){
        printf("%d ", arr[idx]);
    }
}

struct node *getComposite(int arr[])
{
    int idx, divisor, idx2, length = 10;

    struct node *head = NULL, **trav;
    for (idx = 9, trav = &head; idx > -1; idx--){
        for (divisor = 2; divisor < arr[idx] && arr[idx] % divisor != 0; divisor++){}
        if (divisor == arr[idx]){
            *trav = (struct node *)malloc(sizeof(struct node));
            (*trav)->num = arr[idx];
            trav = &(*trav)->next;
            length--;
            for (idx2 = idx; idx2 < length; idx2++){
                arr[idx2] = arr[idx2+1];
            }
        }
    }
    *trav = NULL;

    return head;
}

void descendLink(struct node *head)
{
    struct node *x, *y, *big;
    int temp;

    for (x = head; x != NULL; x = x->next){
        big = x;
        for (y = x->next; y != NULL; y = y->next){
            if (big->num < y->num){
                big = y;
            }
        }
        if (big->num > x->num){
            temp = big->num;
            big->num = x->num;
            x->num = temp;
        }
    }
}

void displayLink(struct node *head)
{
    for ( ; head != NULL; head = head->next){
        printf("%d ", head->num);
    }
}