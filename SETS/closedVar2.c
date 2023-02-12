#include <stdio.h>
#define MAX 20
#define SIZE 10
#define DELETED '*'
#define EMPTY '!'

typedef struct {
	char elem;
	int link;
} Nodetype;

typedef struct {
	Nodetype nodes[MAX];
	int Avail;
} Dictionary;

typedef struct cell {
	char element;
	int hashValue;
} Data[SIZE];

typedef enum {TRUE, FALSE} Boolean;

void initialize(Dictionary *Dptr);
void visualize(Dictionary D);
void display(Dictionary D);
Boolean member(struct cell info, Dictionary D);
void insert(struct cell info, Dictionary *Dptr);
void delete(struct cell info, Dictionary *Dptr);

int main()
{
    Dictionary D;
	Data toBeInserted = {
        {'a', 3}, {'b', 3}, {'c', 3}, {'d', 5}, {'e', 5}, {'f', 5}, {'g', 5}, {'h', 0}
    };

	initialize(&D);
	visualize(D);
    display(D);
    insert(toBeInserted[0], &D);
    insert(toBeInserted[1], &D);
    insert(toBeInserted[2], &D);
    insert(toBeInserted[3], &D);
    insert(toBeInserted[4], &D);
    insert(toBeInserted[5], &D);
    insert(toBeInserted[6], &D);
    visualize(D);
    display(D);
    delete(toBeInserted[2], &D);
    insert(toBeInserted[7], &D);
    visualize(D);
    display(D);

    return 0;
}

void initialize(Dictionary *Dptr)
{
	int idx, count = MAX/2;

	Dptr->Avail = MAX-1;
	for (idx = 0; idx < MAX; idx++){
		Dptr->nodes[idx].elem = EMPTY;
	}
    for (idx = 0; idx < count; idx++){
        Dptr->nodes[idx].link = -1;
    }
	for (idx = MAX-1; idx > count; idx--){
		Dptr->nodes[idx].link = idx-1;
	}
    Dptr->nodes[idx].link = -1;
}

void visualize(Dictionary D)
{
	printf("%15s | %15s\n", "Prime Data Area", "Synonym Data Area");
	printf("%7s %7s %7s %7s %7s %7s\n", "index", "elem", "link", "index", "elem", "link");
	
	int idx, count = MAX/2;

	for (idx = 0; idx < count; idx++){
		printf("%5d | %5c | %5d | %5d | %5c | %5d\n", idx, D.nodes[idx].elem, D.nodes[idx].link, idx+10, D.nodes[idx+10].elem, D.nodes[idx+10].link);
	}
    printf("Avail = %d\n", D.Avail);
}

void display(Dictionary D)
{
	int idx, idx2;

	printf("%5s | %5s\n", "index", "elem");
	for (idx = 0; idx < MAX/2; idx++){
		printf("%5d = ", idx);
        for (idx2 = idx; idx2 != -1; idx2 = D.nodes[idx2].link){
            printf("%c ", D.nodes[idx2].elem);
        }
        printf("\n");
	}
}

Boolean member(struct cell info, Dictionary D)
{
	int idx = info.hashValue;

	if (D.nodes[idx].elem != info.element && (D.nodes[idx].elem == DELETED || D.nodes[idx].elem != EMPTY)){
		for (idx = D.nodes[idx].link; idx != -1 && D.nodes[idx].elem != info.element; idx = D.nodes[idx].link){}
	}

	return (idx == -1 || D.nodes[idx].elem != info.element) ? FALSE: TRUE;
}

void insert(struct cell info, Dictionary *Dptr)
{
	if (member(info, *Dptr) == FALSE){
		int idx = info.hashValue;

		if (Dptr->nodes[idx].elem == EMPTY || Dptr->nodes[idx].elem == DELETED){
			Dptr->nodes[idx].elem = info.element;
			Dptr->nodes[idx].link = -1;
		} else {
			int temp = Dptr->Avail, *trav;

			if (temp != -1){
				Dptr->Avail = Dptr->nodes[temp].link;
				Dptr->nodes[temp].elem = info.element;
				Dptr->nodes[temp].link = Dptr->nodes[idx].link;
				Dptr->nodes[idx].link = temp;
			}
		}
	}
}

void delete(struct cell info, Dictionary *Dptr)
{
	if (member(info, *Dptr) == TRUE){
		int idx = info.hashValue;

		if (Dptr->nodes[idx].elem == info.element){
			Dptr->nodes[idx].elem = DELETED;
		} else {
			int temp, *trav;

			for (trav = &Dptr->nodes[idx].link; Dptr->nodes[*trav].elem != info.element; trav = &Dptr->nodes[*trav].link){}
			temp = *trav;

			*trav = Dptr->nodes[*trav].link;
			Dptr->nodes[temp].link = Dptr->Avail;
			Dptr->Avail = temp;
		}
	}
}
