#include <stdio.h>
#define SIZE 8

typedef struct {
    char Elem[SIZE];
    int top;
} Stack;

void INITIALIZE(Stack *stackptr);
void PUSH(char x, Stack *stackptr);
void displayStack(Stack S);
void POP(Stack *stackptr);

int main()
{
    Stack S;

    INITIALIZE(&S);
    PUSH('y', &S);
    printf("\nAfter pushing:\n");
    displayStack(S);
    POP(&S);
    printf("\nAfter popping:\n");
    displayStack(S);
    int topElem = TOP(S);

    return 0;
}

void INITIALIZE(Stack *stackptr)
{
    stackptr->top = SIZE;
}

void PUSH(char x, Stack *stackptr)
{
    stackptr->top--;
    stackptr->Elem[stackptr->top] = x;
}

void displayStack(Stack S)
{
    int idx;

    for (idx = S.top; idx < SIZE; idx++){
        printf("%c", S.Elem[idx]);
    }
}

void POP(Stack *stackptr)
{
    stackptr->top++;
}
