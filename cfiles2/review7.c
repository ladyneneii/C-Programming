#include <stdio.h>

int main()
{
    FILE *fptr = fopen("anotherfile.txt", "w+");
    char message[50] = "I don't like you.", temp;
    int idx;

    if(fptr == NULL){
        printf("Error loading file.\n");
    } else {
        for (idx = 0; message[idx] != '\0'; idx++){
            fwrite(message+idx, sizeof(char), 1, fptr);
        }
        fseek(fptr, sizeof(char) * 8, 1);
        while(fread(&temp, sizeof(char), 1, fptr)){
            printf("%c", temp);
        }
    }

    fclose(fptr);

    return 0;
}