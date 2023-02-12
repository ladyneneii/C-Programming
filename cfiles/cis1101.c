ds#include <stdio.h>
int main()
{
	int n, digit, diff;
	scanf("%d", &n);
	digit = n % 10;
	diff = digit;
	n = (n - digit) / 10;
	while(n != 0){
		digit = n % 10;
		diff = diff - digit;
		n = (n - digit) / 10;
	}
	printf("The difference of all the digits of the inputted number is %d", diff);
}
