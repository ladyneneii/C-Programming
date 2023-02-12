// StackLink.h
#ifndef STACK_H
#define STACK_H
#include <stdlib.h>

typedef struct node {
    char Elem;
    struct node *next;
} *Stack;

void INITIALIZE(Stack *stackptr);
void PUSH(char x, Stack *stackptr);
void POP(Stack *stackptr);
char TOP(Stack *stackptr);
int EMPTY(Stack *stackptr);
int FULL(Stack *stackptr);
void display(Stack *stackptr);

void INITIALIZE(Stack *stackptr)
{
    *stackptr = NULL;
}

void PUSH(char x, Stack *stackptr)
{
    Stack temp = (Stack)malloc(sizeof(struct node));

    temp->Elem = x;
    temp->next = *stackptr;
    *stackptr = temp;
}

void POP(Stack *stackptr)
{
    Stack temp = *stackptr;
    
    *stackptr = (*stackptr)->next;
    free(temp); 
}

char TOP(Stack *stackptr)
{
    return (*stackptr)->Elem;
}

int EMPTY(Stack *stackptr)
{
    return (*stackptr == NULL) ? 1 : 0;
}

int FULL(Stack *stackptr)
{
    printf("\nFULL() is only applicable to array implementation.\n");
    return 0;
}

void display(Stack *stackptr)
{
	Stack temp;

	INITIALIZE(&temp);
	for ( ; EMPTY(stackptr) != 1; POP(stackptr)){
        printf("%c ", TOP(stackptr));
		PUSH(TOP(stackptr), &temp);
	}
	for ( ; EMPTY(&temp) != 1; POP(&temp)){
		PUSH(TOP(&temp), stackptr);
	}
}

#endif