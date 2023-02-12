#include <stdio.h>

int Hash(int x);
int Hash2(int x);
int Hash3(char name[]);

int main()
{
    int x = Hash(13851946);
    int y = Hash2(4398);
    int z = Hash3("Nene");

    printf("%d\n", x);
    printf("%d\n", y);
    printf("%d\n", z);

    return 0;
}

int Hash(int x)
{
    return x/10%10;
}

int Hash2(int x)
{
    int sum;

    for (sum = 0; x != 0; x/=10){
        sum += x%10;
    }

    return sum%19;
}

int Hash3(char name[])
{
    int idx, sum;

    for (idx = sum = 0; name[idx] != '\0'; idx++){
        sum += name[idx];
    }

    return sum%49;
}