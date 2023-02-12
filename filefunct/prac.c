#include <stdio.h>
#define max 5

int main()
{
    FILE *fp;
    char x[max];
    int idx;

    if ((fp = fopen("prac.txt", "w")) == NULL){
        printf("Error creating text file.");
    } else {
        for(idx = 0; idx < max; idx++){
            printf("Enter a character: \n");
            scanf(" %c", x + idx);
        }
        fwrite(x, sizeof(char), max, fp);
    }
    fclose(fp);

    return 0;
}