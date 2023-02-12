void appendNonPerish(productList list)
{
    FILE *fptr = fopen("filename.txt", "r");
    int totalProd, idx, idx2;

    if (fptr == NULL){
        printf("Error opening file.\n");
    } else {
        totalProd = fread(list.prod + list.ctr, sizeof(prod), 100, fptr);
        fread(list.prod + list.ctr, sizeof(prod), totalProd, fptr);
    }

    for(idx = list.ctr; list.prod[idx] != '\0'; ){
        if (list.prod[idx].exp == PERISHABLE){
            for(idx2 = idx; list.prod[idx2] != '\0'; idx2++){
                list.prod[idx2] = list.prod[idx2+1];
            }
        } else {
            idx++;
        }
    }
    
}