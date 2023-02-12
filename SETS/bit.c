#include <stdio.h>

short findBit (int num);

int main() {
    printf("%d\n", findBit(105));

    return 0;
}

short findBit (int num)
{
	int bit, result = 0;

	for (bit = 128; num != 0; bit/=2){
		if (bit <= num){
			num -= bit;
			result = (result << 1) + 1;
		} else {
			result = result << 1;
		}
	}
	
	return result;
}

#define max 10

typedef struct node {
	int elem;
	struct node *link;
} *Children;

typedef Children Header[max];

typedef struct {
	Header H;
	int Root;
} Tree;