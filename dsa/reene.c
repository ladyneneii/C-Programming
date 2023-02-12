// Dope or Don't

#include <stdio.h>

int main()
{
    char str[20], temp[21];
    int idx, idx2;

    fgets(str, 20, stdin);
    for (idx = 0; str[idx] != '\0'; idx++){}
    str[--idx] = '\0';
    for (idx--, idx2 = 0; idx >= 0; idx--, idx2++){
        temp[idx] = str[idx2];
    }
    temp[idx2] = '\0';
    for (idx = 0; idx < idx2 && str[idx] == temp[idx]; idx++){}
    if (idx == idx2){
        printf("palindope");
    } else {
        printf("palindon't");
    }

    return 0;
}