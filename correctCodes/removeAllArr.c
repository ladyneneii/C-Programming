#include <stdio.h>
#include <stdlib.h>

typedef struct {
    char *elem;
    int count;
} ArrList;

typedef struct node {
    char elem;
    struct node *next;
} *LL;

void display(NameType name);

int main()
{
    NameType name = {"-", "-", '-', -1};



    display(name);

    return 0;
}

void display(NameType name)
{
    printf("%s, %s %c %d\n", name.FName, name.LName, name.MI, name.colour);
}