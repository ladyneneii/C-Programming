#include <stdio.h>

typedef struct {
    int a, b, c;
} fileType;

int main()
{
    FILE *fptr = fopen("samplefile.bin", "wb+");
    fileType values = {3, 6, 2}, values2;

    if (fptr == NULL){
        printf("Error loading file.\n");
    } else {
        fwrite(&values, sizeof(fileType), 1, fptr);
        rewind(fptr);
        fread(&values2, sizeof(fileType), 1, fptr);
        printf("%d\n", values2.b);
    }

    fclose(fptr);

    fptr = fopen("samplefile.txt", "w+");

    if (fptr == NULL){
        printf("Error loading file.\n");
    } else {
        fwrite(&values2, sizeof(fileType), 1, fptr);
    }

    fclose(fptr);

    return 0;
}
