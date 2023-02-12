/*
#include <stdio.h>

int main()
{
    FILE *fp = fopen("gay.txt", "r");
    int idx, max;
    char x[5];

    if (fp == NULL){
        printf("Error loading file.");
    } else {
        while((max = fread(x, sizeof(char), 4, fp)) != 0){
            for(idx = 0; idx < max; idx++){
                printf("%c", x[idx]);
            }
            printf("\n");
        }
    }

    fclose(fp);

    FILE *fp2 = fopen("prac3.txt", "w");
    char arr[5];
    int ndx;

    if (fp2 == NULL){
        printf("Error creating file.");
    } else {
        for(ndx = 0; ndx < 5; ndx++){
            printf("Enter string: \n");
            scanf("%s", arr);
            fwrite(arr, sizeof(arr), 4, fp);
        }
    }
    fclose(fp2);

    return 0;
}
*/

#include <stdio.h>
#include <string.h>

int main()
{
    FILE *fp = fopen("prac4.txt", "r+");
    char sample[] = "i love dicks", sample2[5];
    int idx, count;

    if(fp == NULL){
        printf("Error loading file.");
    } else {
        /*
        for(idx = 0; idx < strlen(sample); idx++){
            fwrite(sample + idx, sizeof(char), 1, fp);
        }
        */
        
        fwrite(sample, sizeof(char), strlen(sample), fp);

        fread(sample2, sizeof(char), strlen(sample), fp);

        printf("%s", sample2);

        // fwrite(sample, strlen(sample), strlen(sample), fp);
        // causes to write unknown symbols

        /*

        while((count = fread(sample2, sizeof(char), 4, fp)) != 0){
            
            for (idx = 0; idx < count; idx++){
                printf("%c", sample2[idx]);
            }

            printf("%s", sample2);
        }
        */
    }
    fclose(fp);

    return 0;
}