#include <stdio.h>
#define MAX 20
#define SIZE 10
#define DELETED '*'
#define EMPTY '!'

typedef struct {
	char elem[MAX];
	int last;
} Dictionary;

typedef struct cell {
	char element;
	int hashValue;
} Data[SIZE];

typedef enum {TRUE, FALSE} Boolean;

void initialize(Dictionary *Dptr);
void display(Dictionary D);
void visualize(Dictionary D);
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
    insert(toBeInserted[0], &D);
    insert(toBeInserted[1], &D);
    insert(toBeInserted[2], &D);
    insert(toBeInserted[3], &D);
    insert(toBeInserted[4], &D);
    insert(toBeInserted[5], &D);
    insert(toBeInserted[6], &D);
    visualize(D);
    delete(toBeInserted[2], &D);
    insert(toBeInserted[7], &D);
    visualize(D);

	return 0;
}

void initialize(Dictionary *Dptr)
{
	int idx, count = MAX/2;

	for (idx = 0; idx < MAX; idx++){
		Dptr->elem[idx] = EMPTY;
	}
    Dptr->last = 9;
}

void visualize(Dictionary D)
{
	printf("%10s | %10s\n", "Prime Data Area", "Synonym Data Area");
	printf("%7s %7s %7s %7s\n", "index", "elem", "index", "elem");
	
	int idx, count = MAX/2;

	for (idx = 0; idx < count; idx++){
		printf("%5d | %5c | %5d | %5c\n", idx, D.elem[idx], idx+10, D.elem[idx+10]);
	}
    printf("last = %d\n", D.last);
}

void display(Dictionary D)
{
	int idx;

	printf("%5s | %5s\n", "index", "elem");
	for (idx = 0; idx < MAX; idx++){
		printf("%d = %c ", idx, D.elem[idx]);
		
	}
}

Boolean member(struct cell info, Dictionary D)
{
	int idx = info.hashValue;

    if (D.elem[idx] == DELETED || D.elem[idx] != EMPTY){
		for (idx = 9; idx <= D.last && D.elem[idx] != info.element; idx++){}
    }

	return (D.elem[idx] == info.element) ? TRUE: FALSE;
}

void insert(struct cell info, Dictionary *Dptr)
{
	if (member(info, *Dptr) == FALSE){
		if (Dptr->elem[info.hashValue] == DELETED || Dptr->elem[info.hashValue] == EMPTY){	
			Dptr->elem[info.hashValue] = info.element;
		} else {
            Dptr->last++;
			Dptr->elem[Dptr->last] = info.element;
		}
	}
}

void delete(struct cell info, Dictionary *Dptr)
{
	if (info.element == Dptr->elem[info.hashValue]){
		Dptr->elem[info.hashValue] = DELETED;
	} else {
		int idx;

		for (idx = 10; idx <= Dptr->last && info.element != Dptr->elem[idx]; idx++){}
		if (idx <= Dptr->last){
			Dptr->elem[idx] = Dptr->elem[Dptr->last];
			Dptr->last--;
		}
	}
}

/*
#define max 10
#define deleted '*'
#define empty '?'

typedef struct {
	int last;
	char elem[max];
} Dictionary;

typedef enum {TRUE, FALSE} Boolean;

insertMember(Dictionary *Dptr, char item)
{
	if (isMember(*Dptr, item) == FALSE){
		int group = Hash(item);

		if (Dptr->elem[group] == deleted || Dptr->elem[group] == empty){
			Dptr->elem[group] = item;
		} else {
			Dptr->last++;
			Dptr->elem[D.last] = item;
		}
	}
}

deleteMember(Dictionary *Dptr, char item)
{
	if (isMember(*Dptr, item) == TRUE){
		int group = Hash(item), idx;

		if (Dptr->elem[group] == item){
			Dptr->elem[group] = deleted;
		} else {
			for (idx = max/2; Dptr->elem[idx] != item; idx++){}
			Dptr->elem[idx] = Dptr->elem[Dptr->last];
			Dptr->last--;
		}
	}
}

isMember(Dictionary D, char item)
{
	Boolean result;
	int group = Hash(item), idx;

	if (D.elem[group] == item){
		result = TRUE;
	} else {
		for (idx = max/2; idx <= D.last && D.elem[idx] != item; idx++){}
		result = idx > D.last ? FALSE : TRUE;
	}
	
	return result;
}
*/