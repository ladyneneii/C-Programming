#include <stdio.h>
#include <string.h>
#define MAX 30

struct nameType{
    char FName[32];
    char Mi;
    char LName[32];
};

typedef struct{
    struct nameType name[MAX];
    int count;
} listOfNames;

void displayList(listOfNames name);
void deleteList(listOfNames *name, char *lastName);

int main()
{
    listOfNames name1 = {
        {
            {"Kit", 'O', "Connor"},
            {"Joe", 'T', "Locke"},
            {"Alice", 'F', "Oseman"},
            {"Sebastian", 'T', "Croft"},
            {"Charlie", 'o', "Spring"}
        },
        5
    };

    displayList(name1);
    deleteList(&name1, "Oseman");
    printf("\n\nAfter deleting\n\n");
    displayList(name1);

    return 0;
}

void displayList(listOfNames name)
{
    int idx;

    for(idx = 0; idx < name.count; idx++){
        printf("%s, %s %c\n", name.name[idx].LName, name.name[idx].FName, name.name[idx].Mi);
    }
}

void deleteList(listOfNames *name, char *lastName)
{
    int idx;

    for(idx = 0; idx < name->count && strcmp(lastName, name->name[idx].LName) != 0; idx++){}
    for(name->count--; idx < name->count; idx++){
        name->name[idx] = name->name[idx+1];
    }
}
