#include <stdio.h>

int Hash(char name[]);

int main()
{
    printf("%d", Hash("bitch"));

    return 0;
}

int Hash(char name[])
{
	int num, idx;

	for (num = idx = 0; name[idx] != '\0'; idx++){
		num += name[idx];
	}

	return num%19;
}