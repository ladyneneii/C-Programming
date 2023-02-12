// StackArray.h
#ifndef STACK_H
#define STACK_H
#define SIZE 10

typedef struct {
    char Elem[SIZE];
    int top;
} Stack;

void INITIALIZE(Stack *stackptr);
void PUSH(char x, Stack *stackptr);
void POP(Stack *stackptr);
char TOP(Stack *stackptr);
int EMPTY(Stack *stackptr);
int FULL(Stack *stackptr);
void display(Stack *stackptr);

void INITIALIZE(Stack *stackptr)
{
    stackptr->top = SIZE;
}

void PUSH(char x, Stack *stackptr)
{
    stackptr->top--;
    stackptr->Elem[stackptr->top] = x;
}

void POP(Stack *stackptr)
{
    stackptr->top++;
}

char TOP(Stack *stackptr)
{
    return stackptr->Elem[stackptr->top];
}

int EMPTY(Stack *stackptr)
{
    return (stackptr->top == SIZE) ? 1 : 0;
}

int FULL(Stack *stackptr)
{
    return (stackptr->top == 0) ? 1 : 0;
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