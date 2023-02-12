#include <stdio.h>
#include <string.h>

struct nameType{
    char LName[24];
    char FName[24];
    char Mi;
};

int main()
{
    char nameOfFile[20];

    printf("Enter name of file: \n");
    scanf("%s", nameOfFile);

    FILE *fpointer = fopen(nameOfFile, "w+");

    if (fpointer == NULL){
        printf("Error loading file.\n");
    } else {
        // create record in the c file
        struct nameType name[20] = {
            {"Locke", "Joe", 'D'},
            {"Lim", "James", 'O'},
            {"Lim", "Kit", 'T'},
            {"Croft", "Sebastian", 'F'},
            {"Lim", "Charlie", 'D'}
        };
        int idx;

        // transfer record into the text file
        for(idx = 0; idx < 5; idx++){
            fwrite(name[idx].LName, strlen(name[idx].LName), 1, fpointer);
            fprintf(fpointer, "\n");
            fwrite(name[idx].FName, strlen(name[idx].FName), 1, fpointer);
            fprintf(fpointer, "\n");
            fwrite(&name[idx].Mi, sizeof(char), 1, fpointer);
            fprintf(fpointer, "\n\n");
        }
        
        fprintf(fpointer, "\n\n\n");

        // change the Lim last name to Yu and transfer the changes into the text file
        for(idx = 0; idx < 5; idx++){
            if(strcmp(name[idx].LName, "Lim") == 0){
                strcpy(name[idx].LName, "Yu");
            }
            fwrite(name[idx].LName, strlen(name[idx].LName), 1, fpointer);
            fprintf(fpointer, "\n");
            fwrite(name[idx].FName, strlen(name[idx].FName), 1, fpointer);
            fprintf(fpointer, "\n");
            fwrite(&name[idx].Mi, sizeof(char), 1, fpointer);
            fprintf(fpointer, "\n\n");
        }

        rewind(fpointer);
        
        // print the content of the text file in the compiler
        char letter;

        while (fread(&letter, sizeof(char), 1, fpointer) > 0){
            printf("%c", letter);
        }
    }

    fclose(fpointer);

    return 0;
}