/*

#include <stdio.h>

int main()
{
    FILE *fp = fopen("prac4.txt", "r+");
    char sample[10];
    int idx, count;

    if(fp == NULL){
        printf("Error loading file.");
    } else {
        while((count = fread(sample, sizeof(char), 5, fp)) != 0){
            for(idx = 0; idx < count; idx++){
                printf("%c", sample[idx]);
            }
        }
    }

    fclose(fp);

    return 0;
}

*/

#include <stdio.h>

int main()
{
    FILE *fpointer = fopen("text5.txt", "w");
    char sample, getter;
    int idx, count = 5;

    if(fpointer == NULL){
        printf("Error creating file.");
    } else {
        for(idx = 0; idx < count; idx++){
            printf("Enter a character: \n");
            scanf(" %c", &sample);
            fwrite(&sample, sizeof(char), 1, fpointer);
        }
    }   
    fclose(fpointer);

    fpointer = fopen("text5.txt", "r");

    for(idx = 0; idx < count; idx++){
        fread(&getter, sizeof(char), 1, fpointer);
        printf("%c", getter);
    }
    fclose(fpointer);

    return 0;
}