#include <stdio.h>
#include <string.h>

int main()
{
    FILE *fpointer = fopen("heartstopper.txt", "w");
    char variable[50], getter[50], getterInt[50];

    if(fpointer != NULL){
        printf("Enter a sentence: \n");
        scanf("%s", variable); // variable = Iloveme .... strlen(variable) is 7
        // fgets(variable, 50, stdin); variable = Iloveme  ... strlen(variable) is 8
        fwrite(variable, sizeof(char), strlen(variable) - 5, fpointer);
    } else {
        printf("Error loading file.");
    }

    printf("%lu\n", strlen(variable));
    
    fclose(fpointer);

    FILE *fp = fopen("heartstopper.txt", "r");

    if(fp != NULL){
        printf("%lu\n", strlen(variable));
        fread(getter, sizeof(char), strlen(variable), fp); // What are read beyond the last letter are ZEROS.
        printf("%s\n", getter);
        printf("%lu", strlen(getter));
        printf("%c\n%c\n%d\n", getter[10], getter[11], getter[9]);
        printf("lala\n");
    } else {
        printf("Error loading file.");
    }

    fclose(fp);

    fp = fopen("heartstopper.txt", "r");

    if(fp != NULL){
        fread(getterInt, sizeof(int), 1, fp);
        printf("%s\n", getterInt); // prints Theq
    } else {
        printf("Error loading file."); 
    }

    fclose(fp);

    return 0;
}