#include <stdio.h>
#include <string.h>

int main()
{
    FILE *fpointer = fopen("sampleFile.txt", "r+");
    int ctr, idx;

    if(fpointer == NULL){
        printf("Error opening file.");
    } else {
        char sampleVar[20];

        strcpy(sampleVar, "I love me much");

        fwrite(sampleVar, strlen(sampleVar), 1, fpointer);

        char sampleVar2[4];

        while((ctr = fread(sampleVar2, sizeof(char), 4, fpointer)) != 0){
            for(idx = 0; idx < ctr; idx++){
                printf("%c", *(sampleVar2 + idx));
            }
        }
    }

    fclose(fpointer);


}