#include <stdio.h>
#include <string.h>
#define SIZE 0xFA

typedef struct{
   int year;
   int month;
   int day;
}date;

typedef struct{
   char brand[20];
   char name[20];
   char servingSize[16];
}ProdName;

typedef enum{
   PERISHABLE, // 0 
   NONPERISHABLE // 1
}expiration;

typedef union{
    date expDate;
    char comment[6]; /* "N/A" */
}expInfo;

typedef struct{
   ProdName PName;
   float price;
   expiration exp;
   expInfo info;
}products;

typedef struct{
    products prod[SIZE];
    int ctr; /*holds actual number of products*/ 
}productList;

void appendList(productList *currentProducts, char filename[]);
int removeList(productList *currentProducts, char brandname[]);

int main()
{
    productList currentProducts = {
        {
            {"bitch", "nameOne", "servingsizeOne", 50.0, PERISHABLE, 2020, 3, 5}, 
            {"naur", "nameTwo", "servingsizeTwo", 70.0, NONPERISHABLE, 2022, 5, 15},
            {"yuhh", "nameThree", "servingsizeOne", 20.0, PERISHABLE, 2022, 11, 19},
            {"bitch", "nameFour", "servingsizeFour", 70.0, NONPERISHABLE, 2012, 5, 25},
            {"bitch", "nameFive", "servingsizeFive", 100.0, NONPERISHABLE, 2008, 1, 12},
        },
        5
    };

    productList newProducts = {
        {
            {"bitch", "nameSix", "servingsizeSix", 50.0, PERISHABLE, 2020, 3, 5}, 
            {"naur", "nameSeven", "servingsizeSeven", 70.0, NONPERISHABLE, 2022, 5, 15},
            {"yuhh", "nameEight", "servingsizeEight", 20.0, PERISHABLE, 2022, 11, 19},
            {"bitch", "nameNine", "servingsizeNine", 70.0, NONPERISHABLE, 2012, 5, 25},
            {"bitch", "nameTen", "servingsizeTen", 100.0, NONPERISHABLE, 2008, 1, 12},
        },
        5
    };

    FILE *fptr = fopen("newproducts.dat", "wb");

    if (fptr == NULL){
        printf("Error loading file.\n");
    } else {
        fwrite(&newProducts, sizeof(productList), 1, fptr);
    }
    fclose(fptr);
    appendList(&currentProducts, "newproducts.dat");

    // display all the products including the ones transferred from the binary file
    int idx;
    
    printf("All the products including the new non-perishable products from the file:\n");
    for(idx = 0; idx < currentProducts.ctr; idx++){
        printf("%s %s %d\n", currentProducts.prod[idx].PName.brand, currentProducts.prod[idx].PName.name, currentProducts.prod[idx].exp);
    }
    printf("\n\n");

    int total;

    total = removeList(&currentProducts, "naur");
    printf("Total number of products removed: %d\n", total);

    // display all the products without the removed ones
    printf("All the products without the specified brand:\n");
    for(idx = 0; idx < currentProducts.ctr; idx++){
        printf("%s %s %d\n", currentProducts.prod[idx].PName.brand, currentProducts.prod[idx].PName.name, currentProducts.prod[idx].exp);
    }
    printf("\n\n");

    fptr = fopen("removedProducts.dat", "r");
    products removedprod[SIZE];

    if (fptr == NULL){
        printf("Error loading file.\n");
    } else {
        fread(removedprod, sizeof(products), total, fptr);
        // display the content in removedProducts.dat
        printf("All the products removed: \n");
        for(idx = 0; idx < total; idx++){
            printf("%s %s %d\n", removedprod[idx].PName.brand, removedprod[idx].PName.name, removedprod[idx].exp);
        }
        printf("\n\n");
    }

    fclose(fptr);

    return 0;
}

void appendList(productList *currentProducts, char filename[])
{
    FILE *fptr = fopen(filename, "rb");
    productList tempList;
    int idx;

    if (fptr == NULL){
        printf("Error loading file.\n");
    } else {
        fread(&tempList, sizeof(productList), 1, fptr);
        for (idx = 0; idx < tempList.ctr; idx++){
            if (tempList.prod[idx].exp == NONPERISHABLE){
                currentProducts->prod[currentProducts->ctr] = tempList.prod[idx];
                currentProducts->ctr++;
            }
        }
    }
    fclose(fptr);
}

int removeList(productList *currentProducts, char brandname[])
{
    int total = 0, idx, idx2;

    FILE *fptr = fopen("removedProducts.dat", "ab");

    if(fptr == NULL){
        printf("Error loading file.\n"); 
    } else {
        for(idx = currentProducts->ctr - 1; idx >= 0; idx--){
            if (strcmp(currentProducts->prod[idx].PName.brand, brandname) == 0){
                fwrite(currentProducts->prod+idx, sizeof(products), 1, fptr);
                currentProducts->ctr--;
                for(idx2 = idx; idx2 < currentProducts->ctr; idx2++){
                    currentProducts->prod[idx2] = currentProducts->prod[idx2+1];
                }
                total++;
            }
        }
    }
    fclose(fptr);

    return total;
}