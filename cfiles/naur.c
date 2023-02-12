/*

#include <stdio.h>

int main()
{
    int a[2][3] = {2, 3, 5, 8, 2, 0};

    printf("a = %p\n", a);
    printf("a[0] = %p\n", a[0]);
    printf("&a[0][0] = %p\n", &a[0][0]);

    printf("a[0] + 2 = %p\n", a[0] + 2);
    printf("a[0] + 3 = %p\n", a[0] + 3);

    printf("a + 2 = %p\n", a + 2); 

    printf("sizeof(a[0]) = %lu\n", sizeof(a[0]));
    printf("sizeof(a) = %lu\n", sizeof(a));

    printf("a[1] = %p\n", a[1]);
    printf("a[1] + 3 = %p\n\n\n\n", a[1] + 3);

    printf("a[0][1] = %d\n", a[0][1]);
    a[0] += 1;
    printf("a[0][1] = %d\n", a[0][1]);

    return 0;
}

*/

#include <stdio.h>
#include <ctype.h>
#include <string.h>

void displayGreeting(char greet[])
{
    // strrev(greet+3);
    printf("%s\n", greet);
}


int main()
{
    char greet[] = "Good Morning";

    displayGreeting(greet+3);

    return 0;
}