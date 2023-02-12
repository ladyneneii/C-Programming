
// C program to demonstrate
// example of strrev() function
  

#include <stdio.h>
#include <string.h>
  
int main()
{
    /*
    char st[50], temp[50];
    int idx, idx2;

    scanf("%s", st);
    printf("%s\n", st);
    for (idx = 0; st[idx] != '\0'; idx++){
        temp[idx] = st[idx];
    }
    for (idx2 = 0, idx--; idx > -1; idx--, idx2++){
        st[idx2] = temp[idx];
    }
    st[idx2] = '\0';
    printf("%s\n", st);
    */

    char input[10];
    int idx;

    scanf("%s", input);
    for (idx = 0; input[idx] != '\0' && ((input[idx] > 47 && input[idx] < 58) || (input[idx] > 64 && input[idx] < 71)); idx++){}
    (input[idx] == '\0') ? printf("The inputted string is hexadecimal.") : printf("The inputted string is not hexadecimal.");
  
    return 0;
}