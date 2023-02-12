#include <stdio.h>
#include <string.h>

int main()
{
    FILE *fp = fopen("sampleFile.txt", "w");
    char sentence[30], readSentence[30];

    printf("Enter a sentence: \n");
    scanf("%s", sentence); // ErnestCurat
    fwrite(sentence, sizeof(char), strlen(sentence) - 3, fp); // only ErnestCurat is written in the file

    fclose(fp);

    fp = fopen("sampleFile.txt", "r");

    fread(readSentence, sizeof(char), strlen(sentence), fp); // what are read beyond ErnestCurat are random characters; in this case, '?'
    printf("%s\n", readSentence);
    printf("%lu\n", strlen(readSentence));
    printf("%c\n", readSentence[11]); // ?

    return 0;
}