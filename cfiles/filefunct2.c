#include <stdio.h>
#include <string.h>

int main()
{
    FILE *pointer = fopen("anotherFile.txt", "w+");
    char phrase[20], getphrase[20];

    strcpy(phrase, "slay");
    fwrite(phrase, strlen(phrase), 1, pointer);
    fseek(pointer, sizeof(char)*2, SEEK_SET);
    fread(getphrase, strlen(phrase), 1, pointer);
    printf("%s\n", getphrase);

    return 0;
}