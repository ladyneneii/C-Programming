typedef struct cell {
    int elem;
    struct cell *LC, *RC;
} ctype, *BST;

int isMember(int num, BST S)
{
    for ( ; S != NULL && S->elem != num; S = (num > S->elem) ? S->RC : S->LC){}

    return (S == NULL) ? 0 : 1;
}