#include <stdio.h>
#include <stdlib.h>

struct node {
    char elem;
    struct node *next;
};

void writeFile(struct node *head);

int main()
{
    struct node *head = (struct node*)malloc(sizeof(struct node));

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

    struct node *trav;

    for(trav = head; trav != NULL; trav = trav->next){
        printf("%c", trav->elem);
    }
    printf("\n\n");
    writeFile(head);

    return 0;
}

void writeFile(struct node *head)
{
    FILE *fptr = fopen("practice.bin", "wb+");
    struct node *trav, *get = (struct node *)malloc(sizeof(struct node));

    if (fptr == NULL){
        printf("Error.\n");
    } else {
        /*
        for(trav = head; trav != NULL; trav = trav->next){
            fwrite(trav, sizeof(struct node), 1, fptr);
            rewind(fptr);
            fread(get, sizeof(struct node), 1, fptr);
        }
        */
        for(trav = head; trav != NULL; trav = trav->next){
            fwrite(trav, sizeof(struct node), 1, fptr);
            rewind(fptr);
            fread(get, sizeof(struct node), 1, fptr);
        }

        for(; get != NULL; get = get->next){
                printf("%c", get->elem);
        }
    }
}