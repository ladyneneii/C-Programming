#include <stidio.h>

typedef struct {
    char LName[24], MI, FName[24];
} Nametype;

typedef enum {
    student, teacher, parent;
} Membertype;

typedef struct {
    Nametype name;
    int age;
    Membertype member;
    int yearsOfExp;
} RedInfo;

typedef struct {
    Nametype name;
    int age;
    Membertype member;
    char talent[24];
} YellowInfo;

typedef union {
    RedInfo red[10];
    YellowInfo yellow[10];
} Recordtype;

void PopulateRecord(Recordtype *record);

int main()
{
    Recordtype record1;

    PopulateRecord(&record1);

    return 0;
}

void PopulateRecord(Recordtype *record)
{
    record
}