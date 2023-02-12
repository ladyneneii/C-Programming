/*
#include <stdio.h>
int getNumber();
int main()
{
	int n;
	n = getNumber();
	switch (n){
		case 1 : printf("I HATE U\n"); break;
		case 2 : printf("NAUURRRR"); break;
		default : printf("ew");
	}
	return 0;
}
int getNumber()
{
	int n;
	printf("Enter a number: \n");
	scanf("%d", &n);
	return n;
}
*/

/*
#include <stdio.h>
int main()
{
	int n, div, divisible;
	scanf("%d", &n);
	while (n > 0){
		for (div = 1; div <= n; div++){
			if (n % div == 0){
				divisible++;
			}
			
		}	
		if (divisible < 3){
			printf("%d\n", n);
		}
		n--;
		divisible = 0;
	}
	return 0;
}
*/
/*
#include <stdio.h>
int main()
{
	int n, i = 2, diff = 1;
	printf("Enter a number: \n");
	scanf("%d", &n);
	do {
		diff = diff - i;
		i++;
	} while (i <= n);
	printf("%9d", diff);
	return 0;
}
*/

/*
#include <stdio.h>
int main()
{
	int n, i = 1, div, divisible = 0;
	printf("Enter a number: \n");
	scanf("%d", &n);
	while (i <= n){
		for (div = 1; div <= i; div++){
			if (i % div == 0){
				divisible++;
			}
		}
		if (divisible > 2){
			printf("%d\n", i);
		}
		i++;
		divisible = 0;
	}
	return 0;
}
*/

/*
#include <stdio.h>
int main()
{
	int n, lowest, highest;
	lowest = highest = 0;
	while (1){
		printf("Enter a number: \n");
		scanf("%d", &n);
		if (n == 0){
			break;
		}
		if (n > highest){
			highest = n;
		}
		if (n < lowest){
			lowest = n;
		}
	}
	printf("highest: %d; lowest: %d", highest, lowest);
	return 0;
}
*/

/*
#include <stdio.h>
int getNumber();
int getHigh(int x, int y, int z);
int getSmall(int x, int y, int z);
int main()
{
	int x, y, z;
	x = getNumber();
	y = getNumber();
	z = getNumber();
	printf("The highest and smallest number is %d and %d respectively.\n", getHigh(x, y, z), getSmall(x, y, z));
	return 0;
}
int getNumber()
{
	int n;
	scanf("%d", &n);
	return n;
}
int getSmall(int x, int y, int z)
{
	int smallest;
	smallest = x;
	if (smallest > y){
		if (y > z){
			smallest = z;
		} else {
			smallest = y;
		}
	} else if (smallest > z){
		smallest = z;
	} 
	return smallest;
}
int getHigh(int x, int y, int z)
{
	int highest;
	highest = x;
	if (highest < y){
		if (y < z){
			highest = z;
		} else {
			highest = y;
		}
	} else if (highest < z){
		highest = z;
	} 
	return highest;
}
*/

/*
#include <stdio.h>
int main()
{
	int rows, i = 1, stars;
	scanf("%d", &rows);
	while (i <= rows){
		for (stars = 1; stars <= i; stars++){
			printf("*");
		}
		printf("\n");
		i++;
	}
	while (i - 1 > 0){
		for (stars = 1; stars <= i; stars++){
			printf("*");
		}
		printf("\n");
		i--;
	}
	return 0;
}
*/

/*
#include <stdio.h>
int main()
{
	int rows, i = 1, highest, spaces, spacelim, stars2 = 1, stars;
	scanf("%d", &rows);
	highest = rows / 2 + 1;
	spacelim = rows / 2;
	while (i <= highest){
		for(spaces = 1; spaces <= spacelim; spaces++){
			printf(" ");
		}
		for(stars = 1; stars <= stars2; stars++){
			printf("*");
		}
		printf("\n");
		spacelim--;
		stars2 = stars2 + 2;
		i++;
	}
	return 0;
}
*/

/*
#include <stdio.h>
int getSmallest (int x, int y, int z);
int main()
{
	int n1, n2, n3;
	scanf("%d", &n1);
	scanf("%d", &n2);
	scanf("%d", &n3);
	printf("The smallest number is %d", getSmallest(n1, n2, n3));
	return 0;
}
int getSmallest(int x, int y, int z)
{
	int smallest;
	smallest = x;
	if (smallest > y){
		if (y > z){
			smallest = z;
		} else {
			smallest = y;
		}
	} else if (smallest > z){
		smallest = z;
	}
	return smallest;
}
*/

/*
#include <stdio.h>
void cartesian (int x, int y);
int main()
{
	int n1, n2;
	scanf("%d", &n1);
	scanf("%d", &n2);
	cartesian (n1, n2);
	return 0;
}
void cartesian(int x, int y)
{
	if (x > 0 && y > 0){
		printf("quadrant 1");
	} else if (x > 0 && y < 0){
		printf("quadrant 2");
	} else if (x < 0 && y < 0){
		printf("quadrant 3");
	} else if (x > 0 && y > 0){
		printf("quadrant 4");
	} else if (x == 0 && y == 0){
		printf("origin");
	} else if (x == 0){
		printf("y-axis");
	} else {
		printf("x-axis");
	}
	
}
*/

/*
#include <stdio.h>
int main()
{
	int N, sum = 0, i = 0;
	float average;
	scanf("%d", &N);
	if (N % 2 == 0){
		while (N >= 2){
			sum = sum + N;
			N = N - 2;
			i++;
		}
	} else {
		while (N >= 1){
			sum = sum + N;
			N = N - 2;
			i++;
		}
	}
	average = (float)sum / (float)i;
	printf("The average is %f", average);
	return 0;
}
*/

/*
#include <stdio.h>
int main()
{
	int n, ii, i = 1;
	while(i <= 10){
		for(n = 0, ii = 1; ii <= 10; ii++){
			n = n + i;
			
			printf("%d ", n);
		}
		i++;
		printf("\n");
	}
	return 0;
}
*/

/*
#include <stdio.h>
int main()
{
	int n, digit, product = 1;
	printf("Enter a number: \n");
	scanf("%d", &n);
	while (n != 0){
		digit = n % 10;
		product = product * digit;
		n = n / 10;
	}
	printf("%d", product);
	return 0;
}
*/

/*
#include <stdio.h>
int main()
{
	int n, digit, sum = 0;
	scanf("%d", &n);
	while (n != 0){
		digit = n % 10;
		sum = sum + digit;
		n = n / 10;
		if (n > 9){
			while (n > 9){
				n = n / 10;
			}
		}
	}
	printf("%d", sum);
	return 0;
}
*/

/*
#include <stdio.h>
int main()
{
	int n, div, divisible = 0;
	scanf("%d", &n);
	while (n > 0){
		for (div = 1; div <= n; div++){
			if (n % div == 0){
				divisible++;
			}
		}
		if (divisible <= 2){
			printf("%d\n", n);
		}
		divisible = 0; 
		n--;
	}
	return 0;
}
*/

/*
// binary to decimal conversion without decimals
#include <stdio.h>
int main()
{
	int n, digit, decimal, exp = 0, expp, operand;
	printf("Enter a binary number: \n");
	scanf("%d", &n);
	while (n != 0){
		digit = n % 10;
		if (exp == 0){
			decimal = digit * 1;
			exp++;
			n = n / 10;
			continue;
		}
		for (expp = exp, operand = 1; expp > 0; expp--){
			operand = operand * 2;
		}
		decimal = decimal + digit * operand;
		exp++;
		n = n / 10;
	}
	printf("the decimal number is %d", decimal);
	return 0;
}
*/

/*
// octal to decimal conversion without decimals
#include <stdio.h>
int main()
{
	int n, digit, exp, decimal, factorial, expp = 0;
	printf("Enter an octal number: \n");
	scanf("%d", &n);
	while (n != 0){
		digit = n % 10;
		if (expp == 0){
			decimal = digit;
			n = n / 10;
			expp++;
			continue;
		}
		for (exp = expp, factorial = 1; exp > 0; exp--){
			factorial = factorial * 8;
		}
		decimal = decimal + digit * factorial;
		expp++;
		n = n / 10;
	}
	printf("The decimal number is %d", decimal);
	return 0;
}
*/

/*
#include <stdio.h>
int getNumber();
int getProduct(int n1, int n2);
int getQuotient(int n1, int n2);
int getSum(int n1, int n2);
int getGCF(int n1, int n2);
int main()
{
	int Anum, Aden, Bnum, Bden, Cnum, Cnum1, Cnum2, Cden, gcf;
	printf("Enter numerator of first fraction: \n");
	Anum = getNumber();
	printf("Enter denominator of first fraction: \n");
	Aden = getNumber();
	printf("Enter numerator of second fraction: \n");
	Bnum = getNumber();
	printf("Enter denominator of second fraction: \n");
	Bden = getNumber();
	Cden = getProduct(Aden, Bden);
	Cnum1 = getQuotient(Cden, Aden) * Anum;
	Cnum2 = getQuotient(Cden, Bden) * Bnum;
	Cnum = getSum(Cnum1, Cnum2);
	gcf = getGCF(Cnum, Cden);
	if (gcf > 1){
		Cnum = getQuotient(Cnum, gcf);
		Cden = getQuotient(Cden, gcf);
	}
	printf("The sum of the fractions %d/%d and %d/%d is %d/%d in its lowest form.\n", Anum, Aden, Bnum, Bden, Cnum, Cden);
	return 0;
}
int getNumber()
{
	int n;
	scanf("%d", &n);
	return n;
}
int getProduct(int n1, int n2)
{
	int product;
	product = n1 * n2;
	return product;
}
int getQuotient(int n1, int n2)
{
	int quotient;
	quotient = n1 / n2;
	return quotient;
}
int getSum(int n1, int n2)
{
	int sum;
	sum = n1 + n2;
	return sum;
}
int getGCF(int n1, int n2)
{
	int n3;
	do {
		n3 = n1 % n2;
		n1 = n2;
		n2 = n3;
	} while (n3 != 0);
	return n1;
}
*/

/*
#include <stdio.h>
int main()
{
	int n, terms, ave, sum = 0, i, N;
	scanf("%d", &n);
	scanf("%d", &terms);
	N = n;
	i = terms;
	while (terms > 0){
		sum = sum + n;
		printf("%d\n", N);
		N = N + n;
		terms--;
	}
	ave = sum / i;
	printf("%d", ave);
	return 0;
}
*/

/*
#include <stdio.h>
int main()
{
	float n;
	n = 6;
	printf("%6.2fn", n);
}
*/

/*
#include <stdio.h>
#define PI 3
#define nauur printf
int main()
{
	int r = 2;
	r *= PI;
	nauur("%d", r);
	return 0;
}
*/

/*
#include <stdio.h>
int main()
{
	char letter;
	for (letter = 65; letter <= 122; letter++){
		if (letter > 90 && letter < 97){
			continue;
		}
		printf("%c \n", letter);
	}
	
	return 0;
}
*/

/*
#include <stdio.h>
int main()
{
	const float PI = 3.14159;
	PI /= 5;
	printf("%09.0f", 2 + PI);
	return 0;
}
*/

/*
#include <stdio.h>
int main()
{
	int n1, n2, div, divisible = 0;
	scanf("%d", &n1);
	scanf("%d", &n2);
	while (n1 <= n2){
		for (div = 1; div <= n1; div++){
			if (n1 % div == 0){
				divisible++;
			}
		}
		if (divisible > 2){
			printf("%d\n", n1);
		}
		divisible = 0;
		n1++;
	}
	return 0;
}
*/

/*
#include <stdio.h>
void getEquivalent(int *nptr);
int main()
{
	int n;
	printf("Enter a number: \n");
	scanf("%d", &n);
	printf("Your number is %d.\n", n);
	getEquivalent(&n);
	printf("The equivalent number is %d.\n", n);
	return 0;
}
void getEquivalent(int *nptr)
{
	int digit, temp = 0;
	while (*nptr != 0){
		digit = *nptr % 10;
		if (digit % 2 == 0){
			digit = 1;
		} else {
			digit = 2;
		}
		temp = temp * 10 + digit;
		*nptr /= 10;
	}
	*nptr = 0;
	while (temp != 0){
		digit = temp % 10;
		*nptr = *nptr * 10 + digit;
		temp /= 10;
	}
}
*/

/*
#include <stdio.h>
void swapNumbers(int *a, int *b);
int main()
{
	int n1, n2;
	scanf("%d", &n1);
	scanf("%d", &n2);
	printf("n1 = %d; n2 = %d\n", n1, n2);
	swapNumbers(&n1, &n2);
	printf("n1 = %d; n2 = %d\n", n1, n2);
	return 0;
}
void swapNumbers (int *a, int *b)
{
	int c;
	c = *a;
	*a = *b;
	*b = c;
}
*/

/*
#include <stdio.h>
int getNumber();
void getEquivalent(int *n);
int main()
{
	int n;
	n = getNumber();
	printf("Your number is %d.\n", n);
	getEquivalent(&n);
	printf("Your equivalent number is %d.\n", n);
	return 0;
}
int getNumber()
{
	int n;
	printf("Enter a number: \n");
	scanf("%d", &n);
	return n;
}
void getEquivalent (int *n)
{
	int temp = 0, digit;
	while (*n != 0){
		digit = *n % 10;
		if (digit % 2 == 0){
			digit = 1;
		} else {
			digit = 2;
		}
		temp = temp * 10 + digit;
		*n = *n / 10;
	}
	*n = 0;
	while (temp != 0){
		digit = temp % 10;
		*n = *n * 10 + digit;
		temp /= 10;
	}
}
*/

/*
#include <stdio.h>
int main()
{
	int x = 5, *xptr;
	xptr = &x;
	++*xptr;
	printf("%d", *xptr);
	return 0;
}
*/

/*
#include <stdio.h>
int main()
{
	int Anum, Aden
	return 0;
}
*/

/*
#include <stdio.h>
int getEquivalent(int n);

int main()
{
	// Function Call with declaration and initialization
	int x;

	scanf("%d", &x);
	printf("The equivalent number is %d.\n", getEquivalent(x));
}

// Function Definition
int getEquivalent(int n)
{
	int temp = 0, digit, equivalent = 0;
	while (n != 0){
		digit = n % 10;
		if (digit % 2 == 0){
			temp = temp * 10 + 1;
		} else {
			temp = temp * 10 + 2;
		}
		n /= 10;
	}
	while (temp != 0){
		digit = temp % 10;
		equivalent = equivalent * 10 + digit;
		temp /= 10;
	}
	return equivalent;
}
*/








/*Luke is determining the people who belong in the minority or majority group in their school on the basis of their SOGIE (Sexual Orientation, Gender Identity, and Expression). To do so, he gathered data from 1,000 volunteers on their respective SOGIE. People in the majority group either have cisgender male, heterosexual, and masculine or cisgender female, heterosexual, and feminine as their sexual orientation, gender identity, and expression respectively; otherwise, they belong in the majority group.

Create a function for Luke that accepts 4 inputs. The options of the first input are characters 'M' and 'F' and 'I' (male and female and intersex respectively). The options of the second input are 'T' and 'M' and 'O' (heterosexual and homosexual and others respectively). The options of the third input are 'C' and 'T' and 'O' (cisgender and transgender and others respectively). The options of the fourth input are 'F' and 'M' and 'A' (feminine and masculine and androgynous respectively). Based on the inputs, the function will determine whether the data match the given criteria of people belonging in the majority group or not, and return 1 or 0, which means majority and minority respectively.*/

/*
#include <stdio.h>
int SOGIE(char S, char SO, char GI, char E);

int main()
{
	char sex, orientation, identity, expression;

	// Put a space before %c
	scanf(" %c", &sex);
	scanf(" %c", &orientation);
	scanf(" %c", &identity);
	scanf(" %c", &expression);
	if (SOGIE(sex, orientation, identity, expression) == 0){
		printf("MINORITY");
	} else {
		printf("MAJORITY");
	}
}

int SOGIE(char S, char SO, char GI, char E)
{
	if ((S == 'M' && SO == 'T' && GI == 'C' && E == 'M') || (S == 'F' && SO == 'T' && GI == 'C' && E == 'F')){
		return 1;
	} else {
		return 0;
	}
}
*/


/*
#include <stdio.h>
int sampleFunction(int sampleArray[]);
int main()
{
	char A = 'A', Z = 'Z', a = 'a', z = 'z';
	
	printf("%-5d", A);
	printf("%-5d", Z);
	printf("%-5d", a);
	printf("%-5d\n", z);

	


	int sampleArray[5], x, factorial, count;

	for (x = 0; x < 5; x++){
		for (factorial = 1, count = x + 1; count > 0; count--){
			factorial = factorial * count;
		}
		sampleArray[x] = factorial;
		printf("%-5d", sampleArray[x]);
	}
	
	printf("%d\n", sampleFunction(sampleArray));
	
}

int sampleFunction(int sampleArray[])
{
	int x, y, z;
	printf("\ninput access array number: \n");
	scanf("%d", &x);
	z = sampleArray[x] % sampleArray[x + 1];
	return z;
}
*/

/*
#include <stdio.h>

void toBinary(int *b);

int main()
{
	int n;
	printf("Enter a decimal value: \n");
	scanf("%d", &n);
	toBinary(&n);
	printf("Binary value is: %d.\n", n);
	return 0;
}

void toBinary(int *b)
{
	int binary = 0, digit;
	while (*b != 0){
		digit = *b % 2;
		binary = binary * 10 + digit;
		*b /= 2;
	}
	*b = 0;
	while (binary != 0){
		digit = binary % 10;
		*b = *b * 10 + digit;
		binary /= 10;
	}
}
*/

/*
#include <stdio.h>

void summ(int *a, int *b);
void averagee(int *s);

int main()
{
	int x, y;
	printf("Enter a number: \n");
	scanf("%d", &x);
	printf("Enter a number: \n");
	scanf("%d", &y);
	summ(&x, &y);
	return 0;
}

void summ(int *a, int *b)
{
	int c;
	c = *a + *b;
	averagee(&c);
}

void averagee(int *s)
{
	float a = *s / 0.2;
}
*/

/*
#include <stdio.h>
void equivalent(int *n);
int main()
{
	int n;
	printf("Enter a number: \n");
	scanf("%d", &n);
	printf("The number is %d.\n", n);
	equivalent(&n);
	printf("The equivalent number is: %d.\n", n);
	return 0;
}
void equivalent(int *n)
{
	int digit, equivalent = 0;
	while (*n != 0){
		digit = *n % 10;
		equivalent = equivalent * 10 + ((digit % 2 == 0) ? 1 : 2);
		*n /= 10;
	}
	while (equivalent != 0){
		*n = *n * 10 + (equivalent % 10);
		equivalent /= 10;
	}
}
*/

/*
#include <stdio.h>
void getGCF(int *n, int o);
int main()
{
	int n, o;
	printf("Enter a number: \n");
	scanf("%d", &n);
	printf("Enter another number: \n");
	scanf("%d", &o);
	getGCF(&n, o);
	printf("The GCF is %d.\n", n);
	return 0;
}
void getGCF (int *n, int o)
{
	int p;
	do {
		p = *n % o;
		*n = o;
		o = p;
	} while (p != 0);
}
*/

/*
#include <stdio.h>
void getPrime(int p);

int main()
{
	int n;
	printf("Enter a number: \n");
	scanf("%d", &n);
	getPrime(n);
	
	return 0;
}

void getPrime(int p)
{
	int divisible, divisor;
	while (p > 0){
		for (divisible = 0, divisor = --p; divisible < 2 || divisor != 0; divisor--){
			divisible += (p % divisor == 0) ? 1 : 0;
		}
		if (divisible < 2){
			printf("%5d", p);
		}
		p--;
	} 
}
*/

/*
#include <stdio.h>
void transaction(int age, float *money, int meal);
float getPrice(int meal);
int main()
{
	int age, meal;
	float money;
	printf("Enter age: \n");
	scanf("%d", &age);
	printf("Enter amount of money: \n");
	scanf("%f", &money);
	printf("Enter meal number: \n");
	scanf("%d", &meal);
	transaction(age, &money, meal);
	printf("Money left: %.2f", money);
	return 0;
}
void transaction(int age, float *money, int meal)
{
	float price = getPrice(meal);
	if (age >= 60)
		price = price - price * 0.15;
	if (*money >= price){
		*money -= price;
	} else {
		printf("Not enough money to purchase.");
	}

}
float getPrice(int meal)
{
	return meal * 10.0;
}
*/

/*
#include <stdio.h>
void getPrime (int prime);
// void getComposite (int composite);
int main()
{
	int p, c;
	printf("Enter a number: \n");
	scanf("%d", &p);
	getPrime(p);
	printf("\n\n");
	// getComposite(c);
}
void getPrime (int prime)
{
	int divisible, divisor;
	for (divisible = 0; prime > 0; prime--){
		for (divisor = prime; divisor > 0; divisor--){
			if (prime % divisor == 0){
				divisible++;
			}
			
		}
		if (divisible < 3){
			printf("%5d", prime);
		}
		divisible = 0;
	}
}
*/

/*
#include <stdio.h>
void testStatic()
{
   int x;
   
   for(x = 1; x <= 5; x++) {
      int A = 10;  //initializes/resets
      static int B = 10;   //initialize ONCE

      A++;
      B++;
  
      printf("\n\nIteration No. %d", x);
      printf("\n\t auto A = %d", A);
      printf("\n\t static B = %d", B);
   } 
}
int main()
{

   teststatic();
return 0;
}
*/

/*
#include <stdio.h>
void getValues(int a[], int size);
int main()
{
	int N = 5;
	int aRRAY[N];
	getValues(aRRAY, N);
	return 0;
}
void getValues(int a[], int size)
{
	int count;
	for (count = 0; count <= size; count++){
		scanf("%d", a + count);
		printf("%d\n", *(a + count));
	}
}
*/

/*
#include <stdio.h>
int getSize();
void getValues(int a[], int s);
int main()
{
	int size = getSize(), count = 0;
	int A[size];
	getValues(A, size);
	while (count < size){
		printf("%d\n", *(A + count)); 
		printf("%d\n", A[count]);
		count++;
	}
	return 0;
}
int getSize()
{
	int n;
	printf("Enter size: \n");
	scanf("%d", &n);
	return n;
}
void getValues(int a[], int s)
{
	int count;
	for (count = 0; count < s; count++){
		scanf("%d", a + count);
	}
}
*/

/*
#include <stdio.h>
#include <stdlib.h>

int getNumber();
int *getProduct(int N1[], int N2[]);
int getGCF(int F, int G);
int main()
{
	int A[2], B[2], *D, E, F, G, I;
	printf("Enter a numerator for fraction A: \n");
	A[0] = getNumber();
	printf("Enter a denominator for fraction A: \n");
	A[1] = getNumber();
	printf("Enter a numerator for fraction B: \n");
	B[0] = getNumber();
	printf("Enter a denominator for fraction B: \n");
	B[1] = getNumber();
	D = getProduct(A, B);
	F = *D;
	G = *(D + 1);
	I = getGCF(F, G);
	if (I > 1){
		*D /= I;
		*(D + 1) /= I;
	}
	printf("The product of the two fractions are %d/%d.", D[0], D[1]);
	free(D);
	return 0;
}
int getNumber()
{
	int n;
	scanf("%d", &n);
	return n;
}
int *getProduct(int N1[], int N2[])
{
	int *C = (int *)malloc(sizeof(int)*2);
	C[0] = N1[0] * N2[0];
	C[1] = N1[1] * N2[1];
	return C;
}
int getGCF(int F, int G)
{
	int H;
	do {
		H = F % G;
		F = G;
		G = H;
	} while (H != 0);
	return F;
}
*/

/*
#include <stdio.h>
int FindFact (int N);
int main()
{
	int N = 7;
	printf("%d", FindFact(N));
}
int FindFact(int N)
{
	int factorial = 1;
	while (N > 0){
		factorial = factorial * N;
		N--;
	}
	return factorial;
}
*/

/*
#include <stdio.h>
#include <stdlib.h>
int *getProduct(int n1[], int n2[]);
int main()
{
	int A[2], B[2], *C;
	printf("Enter numerator of fraction A: \n");
	scanf("%d", A);
	printf("Enter denominator of fraction A: \n");
	scanf("%d", A+1);
	printf("Enter numerator of fraction B: \n");
	scanf("%d", B);
	printf("Enter denominator of fraction B: \n");
	scanf("%d", B+1);
	C = getProduct(A, B);
	printf("The product is %d/%d.", *C, *(C+1));
	free(C);
	return 0;
}
int *getProduct(int n1[], int n2[])
{
	int *n3;
	n3 = (int *)malloc(sizeof(int)*2);
	n3[0] = n1[0] * n2[0];
	n3[1] = n1[1] * n2[1];
	return n3;
}
*/

/*
#include <stdio.h>
int main()
{
	int N[50], count = 0, power = 1, elements;
	while (1){
		printf("Enter a number. Enter a zero to stop: \n");
		scanf("%d", N + count);
		if (N[count] == 0){
			break;
		}
		count++;
	}
	elements = count;
	for(; count > 0; count--){
		power *= 2;
	}
	printf("The number of elements are %d\n", factorial);
	
	while (count >= 0){
		printf("%d\n", *(N + count));
		count--;
	}
	return 0;
}
*/

/*
#include <stdio.h>
#include <stdlib.h>
int *getNumber();
int getProduct(int n1, int n2);
int getQuotient(int n1, int n2);
int getGCF(int arr[]);
int main()
{
	int A[2], B[2], *c, *d, num1, num2, C[2], gcf;
	c = getNumber();
	d = getNumber();
	C[1] = getProduct(c[1], d[1]);
	num1 = c[0] * getQuotient(C[1], c[1]);
	num2 = d[0] * getQuotient(C[1], d[1]);
	free(c);
	free(d);
	C[0] = num1 + num2;
	gcf = getGCF(C);
	C[0] /= gcf;
	C[1] /= gcf;
	printf("The sum of the two fractions in its lowest term is %d/%d.\n", *C, *(C+1));
	return 0;
}
int *getNumber()
{
	int *N = (int *)malloc(sizeof(int) * 2);
	printf("Enter a numerator for this fraction: \n");
	scanf("%d", N);
	printf("Enter a denominator for this fraction: \n");
	scanf("%d", N+1);
	return N;
}
int getProduct(int n1, int n2)
{
	return n1 * n2;
}
int getQuotient(int n1, int n2)
{
	return n1 / n2;
}
int getGCF(int arr[])
{
	int n1 = arr[0], n2 = arr[1], n3;
	do {
		n3 = n1 % n2;
		n1 = n2;
		n2 = n3;
	} while (n3 != 0);
	return n1;
}
*/

/*
#include <stdio.h>

float findSmallest(float n[], int size)
{
	float smallest = n[0];
	int index = 1;

	while (index < size){
		smallest = (smallest > n[index]) ? n[index] : smallest;
		index++;
	}
	return smallest;
}

int main()
{
	float A[5] = {8.2, 9.0, 5.1, 4.7, 2.6};
	printf("the smallest number is %f", findSmallest(A, 5));
	return 0;
}
*/

/*
void perform(char a[])
{
	int index, b[10], count = 0, size;
	while(count < size){
		switch(a[count]){
			case '<' : 
		}
		count++;
	}
}
*/

/*
#include <stdio.h>
void getValues(int arr[], int N);
int main()
{
	int n[8];
	getValues(n, 8);
	return 0;
}
void getValues(int arr[], int N)
{
	int count;
	for(count = 0; count < N; count++){
		printf("Enter a number: \n");
		scanf("%d", arr + count);
	}
	printf("\n");
	for(count = 0; count < N; count++){
		printf("%d\n", *(arr + count));
	}
}
*/

/*
#include <stdio.h>
float findSum(float arr[], int count);
int main()
{
	float N[50];
	int count = 0;
	while (1){
		scanf("%f", N + count);
		if (N[count] == 0){
			break;
		}
		count++;
	}
	printf("The average is %.2f.", findSum(N, count) / (float)count);
	return 0;
}
float findSum(float arr[], int count)
{
	float sum = 0;
	count--;
	while (count >= 0){
		sum += *(arr + count);
		count--;
	}
	return sum;
}
*/

/*
#include <stdio.h>
int main()
{
	float value = 5.45; //4 and below do not get incremented 
	float value2 = 5.55;
	printf("%.1f\n", value); // 5.4
	printf("%.1f\n", value2); // 5.6
	return 0;
}
*/

/*
#include <stdio.h>
int main()
{
	static int a = 5;
	printf("%d", ++a);
	a = 7;
	return 0;
}
*/

/*
#include <stdio.h>
int main()
{
	int n[] = {8, 6, 7, 13, 23}, count = 0;
	for (count = 0; count < 5; count++){
		switch(n[count]){
			case 1 ... 10 : printf("naur"); break;
			case 11 ... 15 : printf("naurr"); break;
			default: printf("naurrr"); break;
		}
	}
	return 0;
}
*/

/*
#include <stdio.h>
int main()
{
	int factorial = 1;
	int n;
	scanf("%d", &n);
	for (; n > 0; n--){
		factorial *= n;
	}
	printf("%d", factorial);
}
*/

/*
#include <stdio.h>
void getNumber(int arr[]);
int main()
{
	int C[2];
	getNumber(C);
	printf("%d and %d", C[0], C[1]);
	return 0;
}
void getNumber(int arr[])
{
	scanf("%d", arr);
	scanf("%d", arr+1);
}
*/

/*
#include <stdio.h>
int getFactorial(int a);
int main()
{
	int factorial, n = 5;
	printf("%d", getFactorial(n));
}
int getFactorial(int a)
{
	return 
}
*/

/*
#include <stdio.h>
int main()
{
	int x, y;
	for(y = 1; y <= 5; y++){
		for(x = y; x > 0; x--){
			printf("*");
		}
		printf("\n");
	}
	return 0;
}
*/

/*
#include <stdio.h>
int main()
{
	int n[10] = {}
	return 0;
}
*/

/*
#include <stdio.h>
#include <stdlib.h>
int *getValues();

int main()
{
	int *f1, *f2;
	printf("Enter numerator and denominator of the first fraction.\n");
	f1 = getValues();
	printf("%5d%5d", f1[0], f1[1]);
	free(f1);
	return 0;
}

int *getValues()
{
	int *n1 = (int *)malloc(sizeof(int)*2);
	printf("Enter numerator: \n");
	scanf("%d", n1);
	printf("Enter denominator: \n");
	scanf("%d", n1+1);
	return n1;
}
*/

/*
#include <stdio.h>
#include <stdlib.h>

int *common(int A[], int B[]);

int main()
{
	int A[10] = {0, 1, 3, 4, 5, 2, -1};
	int B[12] = {5, 6, 3, 4, 0, -1};
	int *C = common(A, B);
	printf("{%d, %d, %d, %d, %d, %d}", C[0], C[1], C[2], C[3], C[4], C[5]);
	free(C);
	return 0;
}

int *common(int A[], int B[])
{
	int a, b, *C, c = 0, Csize = 0;
	C = (int *)malloc(sizeof(int) * 100);
	for(a = 0; A[a] != -1; a++){
		for(b = 0; B[b] != -1; b++){
			if (B[b] == A[a]){
				Csize++;
			}
		}
	}
	C = (int *)malloc(sizeof(int)*Csize);
	for(a = 0; A[a] != -1; a++){
		for(b = 0; B[b] != -1; b++){
			if (B[b] == A[a]){
				C[c] = B[b];
				c++;
			}
		}
	}
	return C;
}
*/

/*
#include <stdio.h>

int activity(int arr[], int size, int N);
int main()
{
	int size = 4;
	int A[4] = {5, 6, 2, 4};
	int result = activity(A, size, 2);
	printf("%d", result);
	return 0;
}

int activity(int arr[], int size, int N)
{
	int i;

	for(i = 0; arr[i] < size && arr[i] != N; i++){}
	return (i < size) ? 1 : 0;
}
*/

/*
#include <stdio.h>
#include <stdlib.h>

int *activity(int arrA[], int arrB[]);

int main()
{
	int A[] = {1, 3, 4, 0, 5, 6, -1};
	int B[] = {2, 0, -1};
	int *C; 
	int idx;

	C = activity(A, B);
	printf("{");
	for (idx = 0; C[idx] != -1; idx++){
		printf("%d, ", C[idx]);
	}
	printf("-1}");
	free(C);

	return 0;
}

int *activity(int arrA[], int arrB[])
{
	int x, y, *arrC, z = 0, size;
	
	for(x = 0; arrA[x] != -1 && arrB[x] != -1; x++){}
	size = x++;
	arrC = (int *)malloc(sizeof(int) * size);
	for(x = 0; arrA[x] != -1; x++){
		for(y = 0; arrB[y] != -1 && arrB[y] != arrA[x]; y++){}
		if(arrB[y] != -1){
			arrC[z] = arrB[y];
			z++;
		}
	}
	arrC[size - 1] = -1;

	return arrC;
}
*/

/*
#include <stdio.h>
#include <stdlib.h>

int getSize(int arr1[], int arr2[]);
int *activity(int arrX[], int arrY[], int size);

int main()
{
	int A[] = {77, 3, 4, 5, 0, -1}, B[] = {7, 3, 77, 5, -1};
	int *C, size, index;

	size = getSize(A, B);
	C = activity(A, B, size);
	for(index = 0; C[index] != -1; index++){
		printf("%d ", C[index]);
	}
	printf("-1");

	return 0;
}

int getSize(int arr1[], int arr2[])
{
	int idx;

	for(idx = 0; arr1[idx] != -1 && arr2[idx] != -1; idx++){}
	return idx++;
}

int *activity(int arrX[], int arrY[], int size)
{
	int a, b, c = 0, *arrZ, idx, idx2, temp;

	arrZ = (int *)malloc(sizeof(int) * size);
	for(a = 0; arrX[a] != -1; a++){
		for(b = 0; arrY[b] != -1 && arrY[b] != arrX[a]; b++){}
		if (arrY[b] != -1){
			arrZ[c] = arrY[b];
			c++;
		}
	}
	arrZ[c] = -1;

	
	for(idx = 0; arrZ[idx] != -1; idx++){
		for(idx2 = idx + 1; arrZ[idx2] != -1; idx2++){
			if (arrZ[idx] > arrZ[idx2]){
				temp = arrZ[idx];
				arrZ[idx] = arrZ[idx2];
				arrZ[idx2] = temp;
			}
		}
	}
	

	return arrZ;
}
*/


/*
#include <stdio.h>

int main()
{
	int arr[], size, idx, idx2;

	printf("Enter number of elements: \n");
	scanf("%d", &size);
	for(idx = 0; idx < size; idx++){
		printf("Enter a number: \n");
		scanf("%d", arr + idx);
	}
	for(idx = 0; idx < size; idx++){
		for(idx2 = idx + 1; idx2 < size; idx2++){
			if(arr[idx] > arr[idx2]){
				a = arr[idx];
				arr[idx] = arr[idx2];
				arr[idx2] = a;
			}
		}
	}
	return 0;
}
*/

/*
#include <stdio.h>

struct{
	int arr[10];
} yass;

void ascend(int a[]);

int main()
{
	int idx; 
	
	yass.arr = {3, 5, 3, 8, 4, 8, 2, 0, 3};
	ascend(yass.arr);
	for(idx = 0; idx < 9; idx++){
		printf("%d ", yass.arr[idx]);
	}

	return 0;
}

void ascend(int a[])
{
	int x, y, temp;

	for(x = 0; x < 8; x++){
		for(y = x+1; x > -1 && a[x] > a[y]; x--, y--){
			temp = a[x];
			a[x] = a[y];
			a[y] = temp;
		}
	}
}
*/

/*
#include <stdio.h>

void descend(int a[]);

int main()
{
	int idx, naur[] = {2, 5, 8, 2, 0, 3, 7};

	descend(naur);
	for(idx = 0; idx < 7; idx++){
		printf("%d ", naur[idx]);
	}

	return 0;
}

void descend(int a[])
{
	int x, y, smallPos, temp;

	for(x = 0; x < 6; x++){
		smallPos = x;
		for(y = x+1; y < 7; y++){
			if(a[smallPos] < a[y]){
				smallPos = y;
			}
		}
		if(a[x] < a[smallPos]){
			temp = a[x];
			a[x] = a[smallPos];
			a[smallPos] = temp;
		}
	} 
}
*/

/*
#include <stdio.h>

struct Cartesian{
    int x, y;
};

struct Name{
    char fname[24];
    char MI;
    char lname[26];
};

struct productCode{
    char prodDesc[30];
    float prodPrice;
};

int main()
{
	struct Cartesian point = {0, 0};
	struct Name student = {"Juan", 'T', "dela Cruz"};
	struct productCode product = {"Hershey's Chocolate 100 gms.", 149.50};

	printf("%d %d\n", point.x, point.y);
	printf("%s %c %s\n", student.fname, student.MI, student.lname);
	printf("%s %f", product.prodDesc, product.prodPrice);

	return 0;
}
*/

/*
#include <stdio.h>

struct x{
	int a;
	float b;
	int d;
	int c;
};

int main()
{
	struct x sample;

	printf("%lu", sizeof(sample.b));

	return 0;
}
*/

/*
#include <stdio.h>
#include <stdlib.h>

int *findCommon(int n1[], int n2[]);
void descend(int arr[]);

int main()
{
	int A[] = {3, 4, 7, 1, 8, 2, -1};
	int B[] = {2, 4, 5, 1, 9, 0, -1};
	int idx;
	int *C = findCommon(A, B);

	for(idx = 0; C[idx] != -1; idx++){
		printf("%d ", C[idx]);
	}
	descend(C);
	printf("\n");
	for(idx = 0; C[idx] != -1; idx++){
		printf("%d ", C[idx]);
	}
	free(C);

	return 0;
}

int *findCommon(int n1[], int n2[])
{
	int x, y, z = 0, *common;

	for(x = 0; n1[x] != -1 && n2[x] != -1; x++){}
	common = (int *)malloc(sizeof(int)*(x-1));
	for(x = 0; n1[x] != -1; x++){
		for(y = 0; n2[y] != -1 && n1[x] != n2[y]; y++){}
		if(n1[x] == n2[y]){
			common[z] = n1[x];
			z++;
		}
	}
	common[z] = -1;

	return common;
}

void descend(int arr[])
{
	int x;

	for(x = 0; ø)
}
*/

/*
#include <stdio.h>
#include <string.h>

int main()
{
	float greet[3];
	printf("%lu", sizeof(greet));
	return 0;
}
*/


#include <stdio.h>
#include <string.h>


/*
typedef struct{

} Nametype;  // Nametype IS THE DATATYPE.

Nametype p;



struct {

} Nametype;  // Nametype IS A VARIABLE. THERE'S NO DATATYPE SPECIFIED.


*/





struct Nametype{
		char firstName[20];
		char secondName[20];
		int studID;
		float price;
};

struct Nametype student1, student2, student3;

struct Nametype getInfo();

int main()
{
	student3 = getInfo();

	printf("%s", student3.secondName);

	return 0;
}

struct Nametype getInfo()
{
	struct Nametype info;

	scanf("%s", info.firstName);
	scanf("%s", info.secondName);
	scanf("%d", &(info.studID));
	scanf("%f", &(info.price));

	return info;
}
















