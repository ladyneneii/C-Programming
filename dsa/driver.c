// driver.c
#include <stdio.h>
#include "StackLink.h" // change this to StackLink.h and the output is still the same except for FULL() because it's only applicable to array implementation.

void insertBottom(char x, Stack *stackptr);

int main()
{
    Stack S;

    printf("\nPerforming INITIALIZE();\n");
    INITIALIZE(&S);
    printf("\nPerforming PUSH() and display();\n");
    printf("Left to right, top to bottom\n\n");
    PUSH('k', &S);
    PUSH('c', &S);
    PUSH('a', &S);
    PUSH('t', &S);
    PUSH('s', &S);
    display(&S);
    printf("\nPerforming POP();\n");
    POP(&S);
    display(&S);
    printf("\nPerforming TOP();\n");
    printf("%c\n", TOP(&S));
    printf("\nPerforming EMPTY() and PUSH();\n");
    printf("%d\n\n", EMPTY(&S));
    PUSH('1', &S);
    PUSH('2', &S);
    display(&S);
    printf("\nPerforming FULL();\n");
    printf("%d\n", FULL(&S));
    printf("\nPerforming insertBottom();\n");
    insertBottom('z', &S);
    display(&S);

    return 0;
}

void insertBottom(char x, Stack *stackptr)
{
    Stack temp;

    INITIALIZE(&temp);
    if (FULL(stackptr) != 1){
        for ( ; EMPTY(stackptr) != 1; POP(stackptr)){
            PUSH(TOP(stackptr), &temp);
        }
        PUSH(x, stackptr);
        for ( ; EMPTY(&temp) != 1; POP(&temp)){
            PUSH(TOP(&temp), stackptr);
        }
    } else {
        printf("\nStack is already full.\n");
    }
}