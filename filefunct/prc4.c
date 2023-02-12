#include <stdio.h>
#include <string.h>

int main()
{
    char sample[19], getter[50], getter2[50];

    printf("Enter a sentence: \n");
    fgets(sample, 19, stdin);
    printf("%s\n", sample);

    FILE *fp = fopen("text6.txt", "w");

    if(fp == NULL){
        printf("Error laoding file.");
    } else {
        fwrite(sample, sizeof(char), strlen(sample), fp);
    }

    fclose(fp);

    fp = fopen("text6.txt", "r");

    if(fp == NULL){
        printf("Error laoding file.");
    } else {
        fread(getter, sizeof(char), 10, fp);
        printf("%s\n", getter);
    }

    fclose(fp);


    fclose(fp);

    fp = fopen("text6.txt", "r");

    if(fp == NULL){
        printf("Error laoding file.");
    } else {
        fgets(getter2, 10, fp);
        // printf("%s\n", getter2);
        puts(getter2);
    }

    fclose(fp);

    // For some reason all this cant be performed in one instance of fopen. It has to be three.

    return 0;
}