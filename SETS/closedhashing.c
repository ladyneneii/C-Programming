#include <stdio.h>
#include <string.h>
#include <ctype.h>
#define size 33
#define EMPTY "empty"
#define DELETED "deleted"

typedef char LastName[24];
typedef LastName Dictionary[size];
typedef enum {TRUE, FALSE} boolean;

void initialise(Dictionary D);
void display(Dictionary D);
int Hash(LastName ln);
boolean member(Dictionary D, LastName ln);
void insert(Dictionary D, LastName ln);
void delete(Dictionary D, int pos); 

int main()
{
	Dictionary D;

	initialise(D);
	display(D);
	insert(D, "Slay");
    insert(D, "Taylor");
    insert(D, "Swift");
    insert(D, "Grande");
    insert(D, "Gaga");
	printf("After inserting:\n");
	display(D);
	printf("After deleting:\n");
	delete(D, 2);
    delete(D, 3);
    delete(D, 4);
    delete(D, 5);
    delete(D, 6);
    delete(D, 7);
    delete(D, 8);
    delete(D, 9);
    insert(D, "Capricorn");
    insert(D, "Dzaddey");
    insert(D, "Clay");

	display(D);

	return 0;
}

void initialise(Dictionary D)
{
	int idx;

	for (idx = 0; idx < size; idx++){
		strcpy(D[idx], EMPTY);
	}
}

void display(Dictionary D)
{
	int idx;

	for (idx = 0; idx < size; idx++){
		printf("%s\n", D[idx]);
	}
}

int Hash(LastName ln)
{
	return toupper(ln[0]) - 'A';
}

boolean member(Dictionary D, LastName ln)
{
	int group = Hash(ln), idx;

	for (idx = 0; idx < size && strcmp(D[group], ln) != 0 && strcmp(D[group], EMPTY) != 0; idx++, group = (group+1)%size){}

	return (strcmp(D[group], ln) == 0) ? TRUE : FALSE;
}

void insert(Dictionary D, LastName ln)
{
	if (member(D, ln) != TRUE){
		int group;

		for (group = Hash(ln); strcmp(D[group], EMPTY) != 0 && strcmp(D[group], DELETED) != 0; group = (group+1)%size){}
		strcpy(D[group], ln);
	}
}

void delete(Dictionary D, int pos)
{
	strcpy(D[pos], DELETED);
}




