#include <stdio.h>

int main()
{
    FILE *fpointer;

    fpointer = fopen("text.txt", "r");

    char singleLine[10];

    while(!feof(fpointer)){
        fgets(singleLine, 10, fpointer);
        puts(singleLine);
    }

    fclose(fpointer);

    FILE *fpointer2;

    fpointer2 = fopen("gay.txt", "w");

    fprintf(fpointer2, "I am so so gay\n");

    fclose(fpointer2);

    return 0;
}