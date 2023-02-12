#include <stdio.h>
#include <stdlib.h>
#define max 10

typedef struct node {
    struct {
        char elem;
        int link;
    } nodes[max];
    int avail;
} *VS;

typedef int List;

void initialise(VS vsptr);
void insertSorted(VS vsptr, List *list, char x);
void display(VS vsptr, List list);

int main()
{
    VS vsptr = (VS)malloc(sizeof(struct node));
    List list = -1;
    
    initialise(vsptr);
    insertSorted(vsptr, &list, 'I');
    insertSorted(vsptr, &list, 'A');
    insertSorted(vsptr, &list, 'M');
    insertSorted(vsptr, &list, 'S');
    insertSorted(vsptr, &list, 'O');
    insertSorted(vsptr, &list, 'G');
    insertSorted(vsptr, &list, 'A');
    insertSorted(vsptr, &list, 'Y');
    display(vsptr, list);

    return 0;
}

void initialise(VS vsptr)
{
	int idx;

	for (idx = max-1; idx > -1; idx--){
		vsptr->nodes[idx].link = idx-1;
	}
	vsptr->avail = max-1;
}

void insertSorted(VS vsptr, List *list, char x)
{
    int freendx;

    if (vsptr->avail != -1){
        freendx = vsptr->avail;
        vsptr->avail = vsptr->nodes[freendx].link;
        vsptr->nodes[freendx].elem = x;
        for ( ; *list != -1 && vsptr->nodes[*list].elem < x; list = &vsptr->nodes[*list].link){}
        vsptr->nodes[freendx].link = *list;
        *list = freendx;
    }
}

void display(VS vsptr, List list)
{
    for ( ; list != -1; list = vsptr->nodes[list].link){
        printf("%c ", vsptr->nodes[list].elem);
    }
}