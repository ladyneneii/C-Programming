/*
#include <stdio.h>
#include <string.h>

struct nameType{
    char fname[24];
    char lname[24];
    char mi;
} name;

int main()
{
    FILE *fptr = fopen("sampleFile.txt", "w");
    char buffer[20], getter[20], ch;

    if (fptr == NULL){
        printf("Error loading file.");
    } else {
        strcpy(buffer, "neneenne");
        fwrite(buffer, strlen(buffer), 1, fptr);
        rewind(fptr);
        while((ch=getc(fptr))!=EOF)
        putchar(ch);
    }

    return 0;
}
*/

#include <stdio.h>
#include <string.h>

int main()
{
    FILE *fp;
    fp = fopen("test.txt", "w+");  //write and read mode
    //fprintf(fp, "This is testing for fprintf...\n"); 
    char sentence[50], kween[50];
    strcpy(sentence, "firl stfu");
    fwrite(sentence, strlen(sentence), 1, fp);

    /*
    rewind(fp); //rewind () function moves file pointer position to the beginning of the file.
    char ch;
    while((ch=getc(fp))!=EOF)
    putchar(ch);
    */
    rewind(fp);
    fread(kween, strlen(sentence), 1, fp);
    printf("%s\n", kween);

    fclose(fp);

    return 0;
}  