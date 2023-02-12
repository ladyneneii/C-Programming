#include <stdio.h>
#include <stdlib.h>

struct node {
    char elem;
    struct node *next;
} *head, *trav, receive[10];

int main()
{
    head = (struct node*)malloc(sizeof(struct node));
    head->elem = 'B';
    head->next = (struct node*)malloc(sizeof(struct node));
    head->next->elem = 'I';
    head->next->next = (struct node*)malloc(sizeof(struct node));
    head->next->next->elem = 'T';
    head->next->next->next = (struct node*)malloc(sizeof(struct node));
    head->next->next->next->elem = 'C';
    head->next->next->next->next = (struct node*)malloc(sizeof(struct node));
    head->next->next->next->next->elem = 'H';
    head->next->next->next->next->next = NULL;

    FILE *fptr = fopen("bitch.bin", "wb+");
    int idx;

    if (fptr == NULL){
        printf("Error loading file. \n");
    } else {
        // passing linked list to binary file, then passing linked list in binary file to array implementation in c file.
        for (idx = 0, trav = head; trav != NULL; trav = trav->next, idx++){
            fwrite(trav, sizeof(struct node), 1, fptr); // trav works as a parameter because it is pointing to something; otherwise, it will not work.
            fseek(fptr, sizeof(struct node) * idx, SEEK_SET);
            // rewind(fptr); -- do not use this because the pointer will go back to the very first node always.
            fread(receive+idx, sizeof(struct node), 1, fptr);
        }
        for(idx = 0; idx < 5; idx++){
            printf("%d ",receive[idx].elem);
        }
        printf("\n\n");
    }
    
    fclose(fptr);

    fptr = fopen("bitch2.bin", "wb+");

    if (fptr == NULL){
        printf("Error loading file. \n");
    } else {
        // passing linked list to binary file, then passing linked list in binary file to linked list in c file.
        struct node *getList = (struct node *)calloc(1, sizeof(struct node));

        for(trav = head; trav != NULL; trav = trav->next){
            fwrite(trav, sizeof(struct node), 1, fptr);
            fseek(fptr, sizeof(struct node) * 0, SEEK_SET);
            fread(getList, sizeof(struct node), 1, fptr); // getList only works as a parameter if it is pointing to a struct node.
        }
        for( ; getList != NULL; getList = getList->next){
            printf("%d ", getList->elem);
        }
    }

    fclose(fptr);

    /*
    for(trav = head; trav != NULL; trav = trav->next){
        printf("%d ", trav->elem);
    }
    */

    return 0;
}