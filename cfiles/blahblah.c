/* 
#include <stdio.h>
int main()
{
    int num, sum, i, ave;
    sum = 0;
    i = 0;
    while (1)
    {
        scanf("%d", &num);
        if (num == 0)
           break;
        sum = sum + num;
        i++;
    }
    ave = sum / i;
    printf("The average of all the  numbers inputted is %d", ave);
}
*/


/*
#include <stdio.h>
int main(){
	int Anum, Aden, Bnum, Bden, Cnum, Cden, orig_Cnum, orig_Cden, D;
	printf("Enter numerator of first fraction:\n");
	scanf("%d", &Anum);
	printf("Enter denominator of first fraction:\n");
	scanf("%d", &Aden);
	printf("Enter numerator of second fraction:\n");
	scanf("%d", &Bnum);
	printf("Enter denominator of second fraction:\n");
	scanf("%d", &Bden);
	Cnum = Anum * Bnum;
	Cden = Aden * Bden;
	orig_Cnum = Cnum;
	orig_Cden = Cden;
	D = Cnum % Cden;
	while (D != 0){
		Cnum = Cden;
		Cden = D;
		D = Cnum % Cden;}
	
	if (Cden > 1){
		orig_Cnum = orig_Cnum / Cden;
		orig_Cden = orig_Cden / Cden;}
	
	printf("The product of the two fractions is %d/%d in its lowest form.", orig_Cnum, orig_Cden);
	return 0;}
*/


/*
#include <stdio.h>
int main()
{
	int n, orig, factorial;
	scanf("%d", &n);
	orig = n;
	factorial = 1;
	while (n >= 1){
		factorial = factorial * n;
		n--;
	}
	printf("%d factorial is %d.", orig, factorial);


	return 0;
}
*/

/*
#include <stdio.h>
int main()
{
	int n, temp, digit, sum;
	sum = 0;
	scanf("%d", &n);
	temp = n;
	while(n > 0){
		digit = n % 10;
		sum = sum * 10 + digit; 
		n = n / 10;
	}
	if(temp == sum){
		printf("The inputted number %d is a palindrome.", temp);
	} else {
		printf("The inputted number %d is not a palindrome.", temp);
	}
	return 0;
}
*/

/*
#include <stdio.h>
int main(){
	int n, sum, temp, digit;
	sum = 0;
	scanf("%d", &n);
	temp = n;
	while(n > 0){
		digit = n % 10;
		sum = sum + digit;
		n = n / 10;
	}
	printf("The sum of all the digits of the inputted number %d is %d", temp, sum);
	return 0;
}
*/

/*
#include <stdio.h>
int main()
{
	int n, ctr, i, sum;
	i = 1;
	sum = 0;
	printf("Enter a number: \n");
	scanf("%d", &n);
	printf("Enter a counter number: \n");
	scanf("%d", &ctr);
	while (i <= ctr){
		sum = sum + n;
		n++;
		i++;
	}
	printf("%d", sum);
	return 0;
}
*/

/*
#include <stdio.h>
int main()
{
	int Anum, Aden, Bnum, Bden, Cnum, Cden, orig_Aden, orig_Bden, orig_Cnum, orig_Cden, d;
	printf("Enter the numerator of the first fraction: \n");
	scanf("%d", &Anum);
	printf("Enter the denominator of the first fraction: \n");
	scanf("%d", &Aden);
	printf("Enter the numerator of the second fraction: \n");
	scanf("%d", &Bnum);
	printf("Enter the denominator of the second fraction: \n");
	scanf("%d", &Bden);
	orig_Aden = Aden;
	orig_Bden = Bden;
	d = Aden % Bden;
	while (d != 0){
		Aden = Bden;
		Bden = d;
		d = Aden % Bden;
	}
	Cden = orig_Aden * orig_Bden / Bden;
	Anum = Cden / orig_Aden * Anum;
	Bnum = Cden / orig_Bden * Bnum;
	Cnum = Anum + Bnum;
	Cnum = orig_Cnum;
	Cden = orig_Cden;
	d = Cnum % Cden;
	while (d != 0){
		Cnum = Cden;
		Cden = d;
		d = Cnum % Cden;
	}
	if (Cnum > 1){
		orig_Cnum = orig_Cnum / Cnum;
		orig_Cden = orig_Cden / Cnum;
	} 
	printf("The sum of the two fractions in its lowest form is %d/%d.", orig_Cnum, orig_Cden);
	return 0;
}
*/

/*
#include <stdio.h>
int main()
{
	int N, i, n, total, sum;
	float ave;
	i = 0;
	sum = 0;
	total = 0;
	scanf("%d", &N);
	while (i < N){
		scanf("%d", &n);
		if (n >= 5 && n <= 25){
			sum = sum + n;
			total++;
		}
		i++;
	}
	ave = (float)sum / total;
	printf("%f", ave);
	return 0;
}
*/

/*
#include <stdio.h>
int main()
{
	int n, product, i;
	i = 1;
	product = 1;
	scanf("%d", &n);
	while (i <= n){
		product = product * n;
		i++;
	}
	printf("%d", product);
	return 0;
}
*/

/*
#include <stdio.h>
int main()
{
	int classPopulation, grade, i, sum;
	float ave;
	sum = 0;
	i = 1;
	printf("Enter class population: \n");
	scanf("%d", &classPopulation);
	while (i <= classPopulation){
		printf("Enter grade:");
		scanf("%d", &grade);
		sum = sum + grade;
		i++;
	} 
	ave = (float)sum / classPopulation;
	printf("The average grade of the class population is %f.", ave);
	return 0;
}
*/

/*
#include <stdio.h>
int main()
{
	int n, inputs, highest, lowest;
	printf("Input the number of inputs to be inputted: \n");
	scanf("%d", &inputs);
	printf("Enter a number; \n");
	scanf("%d", &n);
	highest = n;
	lowest = n;
	while (inputs > 1){
		printf("Enter a number; \n");
		scanf("%d", &n);
		
		if (n >= highest){
			highest = n;
		}
		
		if (n <= lowest){
			lowest = n;
		}
		inputs--;
	}
	printf("The highest and lowest number of all the inputted numbers is %d and %d respectively", highest, lowest);
	return 0;
}
*/

/*
#include <stdio.h>
int main()
{
	int classPopulation, grade, failed, passed, temp;
	classPopulation = temp;
	passed = failed = 0;
	printf("Input number of students: \n");
	scanf("%d", &classPopulation);
	while (classPopulation > 0){
		printf("Input student grade: \n");
		scanf("%d", &grade);
		if(grade >= 75){
			passed++;
		} else {
			failed++;
		}
		classPopulation--;
	}
	printf("In a class of %d students, %d passed and %d failed.", temp, passed, failed);
	return 0;
}
*/

/*
#include <stdio.h>
int main()
{
	int n, divisor, divisible, output;
	divisible = 0;
	divisor = 1;
	printf("Enter a number: \n");
	scanf("%d", &n);
	while (divisor <= n && divisible < 3){
		output = n % divisor;
		if (output == 0){
			divisible++;
		}
		divisor++;
	}
	if (divisible == 3){
		printf("Tne inputted number %d is a composite number.\n", n);
	} else {
		printf("Tne inputted number %d is a prime number.\n", n);
	}
	
	return 0;
}
*/

/*
#include <stdio.h>
int main()
{
	int n, highest, lowest, count;
	printf("Input number of inputs to be inputted: \n");
	scanf("%d", &count);
	printf("Enter a number: \n");
	scanf("%d", &n);
	lowest = highest = n;
	count--;
	while (count > 0){
		scanf("%d", &n);
		if (n > highest){
			highest = n;
		} 
		if (n < lowest){
			lowest = n;
		} 
		count--;
	}
	printf("The highest and lowest number among all the inputted numbers is %d and %d respectively.", highest, lowest);

	return 0;
}
*/

/*
#include <stdio.h>
int main()
{
	int rows, x, y;
	x = 1;
	printf("Enter the number of rows: \n");
	scanf("%d", &rows);
	while (x <= rows){
		for (y = 1; y <= x; y++){
			printf("*");
		}
		printf("\n");
		x++;
	}
	return 0;
}
*/

/*
#include <stdio.h>
int main()
{
	int n, divisor = 1, divisible = 0, output;
	printf("Enter a number: \n");
	scanf("%d", &n);
	while (divisor <= n && divisible < 3){
		output = n % divisor;
		if (output == 0){
			divisible++;
		}
		divisor++;
	}
	if (divisible == 3){
		printf("The inputted number %d is composite.", n);
	} else {
		printf("The inputted number %d is prime.", n);
	}
	
	return 0;
}
*/

/*
#include <stdio.h>
int main()
{
	int n, highest, lowest, digit;
	printf("Enter the number of inputs you can enter: \n");
	scanf("%d", &n);
	printf("Enter a number: \n");
	scanf("%d", &digit);
	highest = lowest = digit;
	while (n > 1){
		printf("Enter a number: \n");
		scanf("%d", &digit);
		if (n > highest){
			highest = n;
		}
		if (n < lowest){
			lowest = n;
		}
		n--;
	}
	printf("The highest and lowest number of all the inputted numbers is %d and %d respectively. \n", highest, lowest);
	return 0;
}
*/

/*
#include <stdio.h>
int main()
{
	int n, nn, x, temp = 2;
	printf("Enter number of stars: \n");
	scanf("%d", &n);
	nn = n;
	while (n > 0){
		for (x = n; x > 0; x--){
			printf("*");
		}
		printf("\n");
		n--;
	}
	
	while (temp <= nn){
		for (x = temp; x > 0; x--){
			printf("*");
		}
		printf("\n");
		temp++;
	}
	
	return 0;
}
*/

/*
#include <stdio.h>
int main()
{
	int n, stars, stars2 = 2, space, space2, temp;
	space = space2 = 0;
	printf("Enter number of stars: \n");
	scanf("%d", &n);
	temp = n;
	while (n > 0){
		for (space = space2; space > 0; space--){
			printf(" ");
		}
		for (stars = n; stars > 0; stars--){
			printf("*");
		}
		printf("\n");
		n--;
		space2++;
	}
	
	space = temp - 2;
	n = space2 = space;
	while (space2 >= 0){
		for (space = space2; space > 0; space--){
			printf(" ");
		}
		for (stars = stars2; stars > 0; stars--){
			printf("*");
		}
		printf("\n");
		space2--;
		stars2++;
	}
	
	return 0;
}
*/

/*
#include <stdio.h>
int main()
{
	int a, b, c, d;
	d = 5;
	a = 2;
	d = b = c = a;
	printf("%d, %d, %d, %d", a, b, c, d);
	return 0;
}
*/

/*
#include <stdio.h>
int main()
{
	int n, sum = 0, i = 0;
	float ave;
	while (1){
		printf("Enter a number: \n");
		scanf("%d", &n);
		if (n == 0)
			break;
		sum = sum + n;
		i++;
	}
	ave = sum / (float)i;
	printf("The average of all the numbers inputted is %f.", ave);
	return 0;
}
*/

/*
#include <stdio.h>
int main()
{
	int a = 2, b = 7;
	float c;
	c = (float) b / a;
	printf("%f", c);
	return 0;
}
*/

/*
#include <stdio.h>
int main()
{
	int n, temp, digit, inv, sum, i;
	float ave;
	inv = sum = i = 0;
	printf("Enter a number: \n");
	scanf("%d", &n);
	temp = n;
	while (n > 0){
		digit = n % 10;
		inv = inv * 10 + digit;
		n = n / 10;
	}
	if (inv == temp){
		printf("The inputted number %d is a palindrome.\n", temp);
	} else {
		printf("The inputted number %d is not a palindrome.\n", temp);
	}

	n = temp;

	while (n > 0){
		digit = n % 10;
		sum = sum + digit;
		n = n / 10;
		i++;
	}
	ave = (float)sum / i;
	printf("The average of all the digits of the inputted number %d is %f.", temp, ave);
	return 0;
}
*/

/*
#include <stdio.h>
int main()
{
	int lim, start, start2, stars, stars2, temp;
	stars = stars2 = 1;
	printf("Enter the highest number of stars: \n");
	scanf("%d", &lim);
	temp = lim;
	start = start2 = lim / 2;
	while (lim > 0){
		for(start = start2; start > 0; start--){
			printf(" ");
		}
		for(stars = stars2; stars > 0; stars--){
			printf("*");
		}
		if (stars2 > lim)
			break;
		printf("\n");
		lim--;
		start2--;
		stars2 = stars2 + 2;
	}
	printf("\n");
	stars2 = stars2 - 2;
	start = start2 = 1;
	while (stars2 >= 1){
		for(start = start2; start > 0; start--){
			printf(" ");
		}
		for(stars = stars2; stars > 0; stars--){
			printf("*");
		}
		printf("\n");
		stars2 = stars2 - 2;
		start2++;
	}
	return 0;
}
*/

/*
#include <stdio.h>
int main()
{
	int max, space, stars, starsadd, spaceminus;
	stars = starsadd = 1;
	printf("Enter maximum number of stars: \n");
	scanf("%d", &max);
	space = spaceminus = max / 2;
	while(max >= starsadd){
		for(space = spaceminus; space >= 1; space--){
			printf(" ");
		}
		for(stars = starsadd; stars > 0; stars--){
			printf("*");
		}
		printf("\n");
		starsadd = starsadd + 2;
		spaceminus--;
	}
	space = spaceminus = 1;
	stars = starsadd = max - 2;
	while(starsadd > 0){
		for(space = spaceminus; space > 0; space--){
			printf(" ");
		}
		for(stars = starsadd; stars > 0; stars--){
			printf("*");
		}
		printf("\n");
		starsadd = starsadd - 2;
		spaceminus = spaceminus + 1;
	}

	return 0;
}
*/

/*
#include <stdio.h>
int main ()
{
	int n, nn;
	printf("Enter a number: \n");
	scanf("%d", &n);
	nn = n;
	while (n > 0){
		while (n % 3 == 0){
			printf("%d, ", n);
			n = n - 3;
			if (n == 3){
				printf("%d", n);
				n = n - 3;
				break;
			}
			
		}
		n--;
	}
	printf("\n");
	while (nn > 0){
		while (nn % 5 == 0){
			printf("%d, ", nn);
			nn = nn - 5;
			if (nn == 5){
				printf("%d", nn);
				nn = nn - 5;
				break;
			}	

		}
		nn--;
	}
	return 0;
}
*/

/*
#include <stdio.h>
int main()
{
	float salary, total5, total10;
	int months, months5, months10;
	printf("Enter your salary: \n");
	scanf("%f", &salary);
	printf("Enter the number of months you receive your salary in: ");
	scanf("%d", &months);
	months5 = 60 / months;
	total5 = salary * months5;
	months10 = 120 / months;
	total10 = salary * months10;
	printf("I earn %.2f pesos every %d months. Therefore, I will have earned a total of %.2f pesos by 5 years.\n", salary, months, total5);
	if (total10 >= 1000000){
		printf("Fortunately, in 10 years, I will become a millionaire because I will have earned %.2f pesos.", total10);
	} else {
		printf("Unfortunately, in 10 years, I will not become a millionaire because I will have only earned %.2f pesos.", total10);
	}
	return 0;
}
*/

/*
#include <stdio.h>
int main()
{
	int N, highest, lowest, i;
	printf("Enter a number: ");
	scanf("%d", &N);
	highest = lowest = i = N;
	while (i > 0){
		scanf("%d", &N);
		if (highest < N){
			highest = N;
		}
		if (lowest > N){
			lowest = N;
		}
		i--;
	}
	printf("The highest and lowest number is %d and %d respectively.", highest, lowest);
	return 9;
}
*/

/*
#include <stdio.h>
int main()
{
	int highest, spaces, spacess, stars, starss;
	printf("Enter the highest number of stars: ");
	scanf("%d", &highest);
	spaces = spacess = highest / 2;
	stars = starss = 1;
	while (highest >= starss){
		for(spaces = spacess; spaces > 0; spaces--){
			printf(" ");
		}
		for(stars = starss; stars > 0; stars--){
			printf("*");
		}
		printf("\n");
		spacess--;
		starss = starss + 2;
	}
	spaces = spacess = 1;
	stars = starss = highest - 2;
	while (starss > 0){
		for(spaces = spacess; spaces > 0; spaces--){
			printf(" ");
		}
		for(stars = starss; stars > 0; stars--){
			printf("*");
		}
		printf("\n");
		spacess++;
		starss = starss - 2;
	}
	return 0;
}
*/

/*
#include <stdio.h>
int main()
{
	int X, Y, S;
	float Ave;
	printf("Enter first number: \n");
	scanf("%d", &X);
	printf("Enter second number: \n");
	scanf("%d", &Y);
	S = X + Y;
	Ave = (float)S/2.0;
	printf("Average is ");
	if ((int)Ave % 2 == 0){
		printf("even");
	} else {
		printf("odd");
	}
	return 0;
}
*/

/*
#include <stdio.h>

void compAndDispAve(int N)
{
	
	if(N % 2 == 0){
		int ctr, sum;
		float Ave;
		sum = 0;
		ctr = 0;
		X = 2;
		while (X <= N){
			sum = sum + N;
			X = X + 2;
			ctr++;
		}
		Ave = (float)sum / ctr;
		printf("Average is %.2f", sum);
	} else {
		while (X <= N){
		    sum = sum + N;
			X = X + 2;
			ctr++;

	}
}
*/

/*
#include <stdio.h>
int getNumber()
{
	int inputted;
	printf("Enter a number: \n");
	scanf("%d", &inputted);
	return inputted;
}
int AVERAGE(int l, int w)
{
	float Ave;
	Ave = (float)(l + w) / 2;
	return Ave;
}
int main()
{
	int l, w;
	float ave;
	l = getNumber();
	w = getNumber();
	ave = AVERAGE(l, w);
	printf("The average of the two numbers are %.2f.", ave);
	return 0;
}
*/

/*
#include <stdio.h>
int palin(int N)
{
	int digit, sum = 0;
	while (N > 0){
		digit = N % 10;
		sum = sum * 10 + digit;
		N = N / 10;
		
	}
	return sum;
}
int main()
{
	int N, temp, sum;
	printf("Enter a number: \n");
	scanf("%d", &N);
	temp = N;
	sum = palin(N);
	if (temp == sum){
		printf("The inputted number is a palindrome.\n");
	} else {
		printf("The inputted number is not a palindrome.\n");
	}
	
	return 0;
}
*/

/*
#include <stdio.h>
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
int getGCF(int a, int b)
{
	int c;
	c = a % b;
	while (c != 0){
		a = b;
		b = c;
		c = a % b;
	}
	return b;
}
int getQuotient(int n1, int n2)
{
	int quotient;
	quotient = n1 / n2;
	return quotient;
}
int main()
{
	int Anum, Aden, Bnum, Bden, Cnum, Cden, lowest;
	printf("Enter numerator of fraction A: \n");
	Anum = getNumber();
	printf("Enter denominator of fraction A: \n");
	Aden = getNumber();
	printf("Enter numerator of fraction B: \n");
	Bnum = getNumber();
	printf("Enter denominator of fraction B: \n");
	Bden = getNumber();
	Cnum = getProduct(Anum, Bnum);
	Cden = getProduct(Aden, Bden);
	lowest = getGCF(Cnum, Cden);
	if (lowest > 1){
		Cnum = getQuotient(Cnum, lowest);
		Cden = getQuotient(Cden, lowest);
	} 
	printf("\nThe product of the fractions %d/%d and %d/%d is %d/%d in its lowest form.", Anum, Aden, Bnum, Bden, Cnum, Cden);
	return 0;
}
*/

/*
#include <stdio.h>
int getNumber()
{
	int n;
	scanf("%d", &n);
	return n;
}
int getProduct(int n1, int n2)
{
	int prod;
	prod = n1 * n2;
	return prod;
}
int getQuotient(int n1, int n2)
{
	int quo;
	quo = n1 / n2;
	return quo;
}
int getSum(int n1, int n2)
{
	int sum;
	sum = n1 + n2;
	return sum;
}
int getGCF(int a, int b)
{
	int c;
	c = a % b;
	while (c != 0){
		a = b;
		b = c;
		c = a % b;
	}
	return b;
}
int main()
{
	int Anum, Aden, Bnum, Bden, Cnum, Cden, Cnum1, Cnum2, lowest;
	printf("Enter numerator of fraction A: \n");
	Anum = getNumber();
	printf("Enter denominator of fraction A: \n");
	Aden = getNumber();
	printf("Enter numerator of fraction B: \n");
	Bnum = getNumber();
	printf("Enter denominator of fraction B: \n");
	Bden = getNumber();
	Cden = getProduct(Aden, Bden);
	Cnum1 = getQuotient(Cden, Aden) * Anum;
	Cnum2 = getQuotient(Cden, Bden) * Bnum;
	Cnum = getSum(Cnum1, Cnum2);
	lowest = getGCF(Cnum, Cden);
	if (lowest > 1){
		Cnum = getQuotient(Cnum, lowest);
		Cden = getQuotient(Cden, lowest);
	}
	printf("\nThe sum of the two fractions %d/%d and %d/%d is %d/%d in its lowest form.", Anum, Aden, Bnum, Bden, Cnum, Cden);
	return 0;
}
*/

/*
#include <stdio.h>
int main()
{
	int a, b;
	a = 2; b = 3;
	printf("%d", a > b ? a : b);
	return 0;
}
*/

/*
#include <stdio.h>

void identifyN(int N)
{
	if (N == 0){
		printf("Zero");
	} else {
		(N > 0) ? printf("Positive") : printf("Negative");
	}
}

int main()
{
	int N = 0;
	identifyN(N);
	return 0;

}
*/

/*
#include <stdio.h>
int getNumber()
{
	int n;
	scanf("%d", &n);
	return n;
}
int main()
{
	int X, Y, div1, div2, div3, div4, div5;
	printf("Enter value of X: \n");
	X = getNumber();
	printf("Enter value of Y: \n");
	Y = getNumber();
	printf("Enter first divisor: \n");
	div1 = getNumber();
	printf("Enter second divisor: \n");
	div2 = getNumber();
	printf("Enter third divisor: \n");
	div3 = getNumber();
	printf("Enter fourth divisor: \n");
	div4 = getNumber();
	printf("Enter fifth divisor: \n");
	div5 = getNumber();
	printf("The number/s divisible by the inputted divisors is/are: \n");
	while (X <= Y){
		if (X % div1 == 0 && X % div2 == 0 && X % div3 == 0 && X % div4 == 0 && X % div5 == 0){
			printf("%d\n", X);
		}
		X++;
	}
	return 0;
}
*/

/*
#include <stdio.h>
void word(N)
{
	switch(N){
		case 1 : printf("ONE"); break;
		case 2 : printf("TWO"); break;
		case 3 : printf("THREE"); break;
		case 4 : printf("FOUR"); break;
		case 5 : printf("FIVE"); break;
		default : printf("INVALID INPUT");
	}
}
int main()
{
	word(1);
	return 0;
}
*/

/*
#include <stdio.h>
int getNumber()
{
	int n;
	scanf("%d", &n);
	return n;
}
int smol(int a, int b, int c)
{
	int Small;
	if (a < b){
		if (a < c){
			Small = a;
		} else {
			Small = c;
		}
	} else {
		if (b < c){
			Small = b;
		} else {
			Small = c;
		}
	}
	return Small;
}
int main()
{
	int a, b, c;
	printf("Enter a number: \n");
	a = getNumber();
	printf("Enter a number: \n");
	b = getNumber();
	printf("Enter a number: \n");
	c = getNumber();
	printf("The smallest number of all inputted numbers is %d.", smol(a, b, c));
	return 0;
}
*/

/*
#include <stdio.h>
int getNumber()
{
	int n;
	scanf("%d", &n);
	return n;
}
void ascending(int a, int b, int c)
{
	int first, second, third;
	first = a;
	if (a < b){
		first = a;
		if (b < c){
			first = a;
			second = b;
			third = c;
		} else {
			first = a;
			second = c;
			third = b;
		}
	} else {
		first = b;
		second = a;
		if (b < c){
			first = b;
			if (a < c){
				second = a;
			} else {
				second = c;
			}
		} else {
			second = c;
			third = a;
		}
	}
	printf("%d, %d, %d", first, second, third);
}
int main()
{
	int a, b, c;
	printf("Enter a number: \n");
	a = getNumber();
	printf("Enter a number: \n");
	b = getNumber();
	printf("Enter a number: \n");
	c = getNumber();
	ascending(a, b, c);
	return 0;
}
*/

/*
#include <stdio.h>
void descending()
{
	int a, b, c, first, second, third;
	printf("Enter a number: \n");
	scanf("%d", &a);
	printf("Enter a number: \n");
	scanf("%d", &b);
	printf("Enter a number: \n");
	scanf("%d", &c);
	
	if (a > b && b > c){
		first = a;
		if (b > c){
			second = b;
			third = c;
		} else {
			second = c;
			third = b;
		}
	} else if (b > a && a > c){
		first = b;
		if (a > c){
			second = a;
			third = c;
		} else {
			second = c;
			third = a;
		}
	} else {
		first = c;
		if (a > b){
			second = a;
			third = b;
		} else {
			second = b;
			third = a;
		}
	}
	printf("%d, %d, %d", first, second, third);
}
int main()
{
	descending();
	return 0;
}
*/

/*
#include <stdio.h>
float discount(float n)
{
	float discount, newPrice;
	if (n >= 1000){
		discount = n * 0.50;
	} else if (n < 1000 && n >= 500){
		discount = n * 0.35;
	} else {
		discount = n * 0.25;
	}
	newPrice = (float)n - discount;
	return newPrice;
}
int main()
{
	float price;
	printf("The discounted price is %.2f.", discount(800.00));

	return 0;
}
*/

/*
#include <stdio.h>
int main()
{
	int N;
	printf("Enter a number: \n");
	scanf("%d", &N);
	switch (N){
		case 1 : printf("Addition"); break;
		case 2 : printf("Subraction"); break;
		case 3 : printf("Multiplication"); break;
		case 4 : printf("Divisioon"); break;
		case 5 : printf("Undecided"); break;
		default : printf("IDK");
	}
	return 0;
}
*/

/*
#include <stdio.h>
int getResult()
{
	int x, y, N;
	printf("Enter x: \n");
	scanf("%d", &x);
	printf("Enter y: \n");
	scanf("%d", &y);
	printf("Enter N: \n");
	scanf("%d", &N);
	switch (N){
		case 1 : x += y; break;
		case 2 : x -= y; break;
		case 3 : x *= y; break;
		case 4 : x /= y; break;
		default : while (N > 0){
						x = x + y;
						N--;
				  }
	}
	return x;
}
int main()
{
	printf("%d", getResult());
	return 0;
}
*/

/*
#include <stdio.h>
int main()
{
	int limit, difference = 0, x = 1;
	printf("Enter a number: \n");
	scanf("%d", &limit);
	do {
		difference = difference - x;
		x++;
	} while (x <= limit);
	printf("result: %d", difference);
}
*/

/*
#include <stdio.h>
int factorial(int N)
{
	int factorial = 1;
	while (N > 0){
		factorial = N * factorial;
		N--;
	}
	return factorial;
}
int main()
{
	int N;
	printf("Enter a number: \n");
	scanf("%d", &N);
	printf("The factorial of the inputted number is %d.", factorial(N));
	return 0;
}
*/

/*
#include <stdio.h>
void consecutive(int N)
{
	int x;
	if (N > 0){
		for (x = 0; x <= N; x++){
			printf("%d, ", x);
		}
	} else {
		for (x = N; x <= 0; x++){
			printf("%d, ", x);
			}
	 }
}
int main()
{
	int N;
	printf("Enter a number: \n");
	scanf("%d", &N);
	consecutive(N);
	return 0;
}
*/

/*
#include <stdio.h>
int getPrime(int P)
{
	int divisor = 1, quotient, divisible = 0;
	while (divisor <= P){
		quotient = P % divisor;
		if (quotient == 0){
			divisible++;
		}
		divisor++;
	}
	if (divisible < 3) { 
		quotient = 1;
	} else {
		quotient = 0;
	}
	return quotient;
}
int main()
{
	int P;
	printf("Enter a number: \n");
	scanf("%d", &P);
	printf("%d", getPrime(P));
	return 0;
}
*/

/*
#include <stdio.h>
int main()
{
	int N;
	while (1){
		scanf("%d", &N);
		
		if (N == 0){
			break;
		}
		printf("You entered %d\n", N);
	}
	return 0;
}
*/

/*
#include <stdio.h>
int getNumber()
{
	int N;
	printf("Enter a number: \n");
	scanf("%d", &N);
	return N;
}
int main()
{
	int highest, spaces, spaces2, stars = 1, stars2 = 1;
	highest = getNumber();
	spaces = spaces2 = highest / 2;
	while (stars2 <= highest){
		for (spaces = spaces2; spaces > 0; spaces--){
			printf(" ");
		}
		for (stars = stars2; stars > 0; stars--){
			printf("*");
		}
		printf("\n");
		spaces2--;
		stars2 = stars2 + 2;
	}
	stars2 = stars2 - 4;
	spaces = spaces2 = 1;
	while (stars2 > 0){
		for (spaces = spaces2; spaces > 0; spaces--){
			printf(" ");
		}
		for (stars = stars2; stars > 0; stars--){
			printf("*");
		}
		printf("\n");
		spaces2++;
		stars2 = stars2 - 2;
	}
	return 0;
}
*/

/*
#include <stdio.h>
int getNumber()
{
	int n;
	scanf("%d", &n);
	return n;
}
int main()
{
	int x, y;
	printf("Enter value of x: \n");
	x = getNumber();
	printf("Enter value of y: \n");
	y = getNumber();
	if (x > 0 && y > 0){
		printf("Quadrant 1");
	} else if (x > 0 && y < 0){
		printf("Quadrant 2");
	} else if (x < 0 && y < 0){
		printf("Quadrant 3");
	} else if (x < 0 && y > 0){
		printf("Quadrant 4");
	} else if (x == 0 && y != 0){
		printf("Y-axis");
	} else if (y == 0 && x != 0){
		printf("X-axis");
	} else {
		printf("Origin");
	}
	return 0;
}
*/

/*
#include <stdio.h>
int getNumber()
{
	int n;
	scanf("%d", &n);
	return n;
}
int getProduct(int a, int b)
{
	int product;
	product = a * b;
	return product;
}
int GCF (int a, int b)
{
	int c;
	do {
		c = a % b;
		a = b;
		b = c;
	} while (c != 0);
	return a;
}
int main()
{
	int Anum, Aden, Bnum, Bden, Cnum, Cden, orig_Bnum;
	printf("Enter nominator of first fraction: \n");
	Anum = getNumber();
	printf("Enter denominator of first fraction: \n");
	Aden = getNumber();
	printf("Enter nominator of second fraction: \n");
	Bnum = orig_Bnum = getNumber();
	printf("Enter denominator of second fraction: \n");
	Bden = getNumber();
	Bnum = Bden;
	Bden = orig_Bnum;
	Cnum = getProduct(Anum, Bnum);
	Cden = getProduct(Aden, Bden);
	Cnum = Cnum / GCF(Cnum, Cden);
	Cden = Cden / GCF(Cnum, Cden);
	
	printf("The quotient of the two fractions are %d/%d.", Cnum, Cden);

	return 0;
}
*/

/*
#include <stdio.h>
int getNumber()
{
	int n;
	scanf("%d", &n);
	return n;
}
int main()
{
	int n, temp, digit, reversed = 0;
	printf("Enter a number: \n");
	n = temp = getNumber();
	while (n > 0){
		digit = n % 10;
		reversed = reversed * 10 + digit;
		n = n / 10;
	}
	if (reversed == temp){
		printf("PALINDROME");
	} else {
		printf("NOT A PALINDROME");
	}
	return 0;
}
*/

/*
#include <stdio.h>
int getNumber()
{
	int n;
	scanf("%d", &n);
	return n;
}
int main()
{
	int start, end, divisor = 1, mod, divisible;
	printf("Enter a number: \n");
	start = getNumber();
	printf("Enter a number: \n");
	end = getNumber();
	while (start <= end){
		for (divisor = 1; divisor <= start; divisor++){
			mod = start % divisor;
			if (mod == 0){
				divisible++;
			}

			
		}
		if (divisible > 2){
				printf("%d\n", start);
		}
		
		start++;
		divisible = 0;
	}
	return 0;
}
*/

/*
#include <stdio.h>
int getNumber()
{
	int n;
	scanf("%d", &n);
	return n;
}
int main()
{
	int X, Y, div1, div2, div3, div4, div5;
	printf("Enter value of X: \n");
	X = getNumber();
	printf("Enter value of Y: \n");
	Y = getNumber();
	printf("Enter first divisor: \n");
	div1 = getNumber();
	printf("Enter second divisor: \n");
	div2 = getNumber();
	printf("Enter third divisor: \n");
	div3 = getNumber();
	printf("Enter fourth divisor: \n");
	div4 = getNumber();
	printf("Enter fifth divisor: \n");
	div5 = getNumber();
	printf("The number/s divisible by the inputted divisors is/are: \n");
	while (X <= Y){
		if (X % div1 == 0 && X % div2 == 0 && X % div3 == 0 && X % div4 == 0 && X % div5 == 0){
			printf("%d\n", X);
		}
		X++;
	}
	return 0;
}
*/

/*
#include <stdio.h>
void Performance()
{
	int totalScore, passingScore, totalWords, essayPerformance, plagiarism;
	float score;
	printf("What is the total score of the essay?\n");
	scanf("%d", &totalScore);
	printf("What is the passing score of the essay?\n");
	scanf("%d", &passingScore);
	printf("How many words does this student's essay have?\n");
	scanf("%d", &totalWords);
	printf("How was the essay? Enter 1 for poor, 2 for moderate, 3 for excellent.\n");
	scanf("%d", &essayPerformance);
	printf("Is the essay plagiarized? Enter 1 for yes and 0 for no.\n");
	scanf("%d", &plagiarism);
	if (plagiarism == 0){
		if (totalWords >= 1000){
			score = (float)totalScore * 0.50;
		} else {
			score = (float)totalScore * 0.25;
		}
		if (essayPerformance == 1){
			score = score + (float)totalScore * 0.15;
		} else if (essayPerformance == 2){
			score = score + (float)totalScore * 0.25;
		} else {
			score = score + (float)totalScore * 0.50;
		}
		if (score >= passingScore){
			printf("status: PASSED; score: %.2f", score);
		} else {
			printf("status: FAILED; score: %.2f", score);
		}
	} else {
		printf("status: FAILED; score: 0.00");
	}
}
int main()
{
	Performance();
	return 0;
}
*/

/*
#include <stdio.h>
int main()
{
	int x = 5;
	int *xptr;
	xptr = &x;
	printf("\nThe value of x is %d", x);
	printf("\nThe value of x is %d", *xptr);
	printf("\nThe value of x is %p", &x);
	printf("\nThe address of x is %p", xptr);
	return 0;
}

temp = &
*/

/*
#include <stdio.h>
int main()
{
	int *a, *b;
	scanf("%d", &a);
	scanf("%d", &b);
	printf("%d", a);
	return 0;
}
*/

/*
#include <stdio.h>
int main()
{
	int a = 5;
	printf("a = %d", a);
	int *aptr;
	aptr = &a;
	*aptr = 6;
	printf("a = %d", a);
	return 0;
}
*/

/*
#include <stdio.h>
void swapNumbers(int *aptr, int *bptr);
int main()
{
	int a, b;
	scanf("%d", &a);
	scanf("%d", &b);
	printf("a = %d; b = %d", a, b);
	swapNumbers(&a, &b);
	printf("a = %d; b = %d", a, b);
	return 0;
}
void swapNumbers(int *aptr, int *bptr)
{
	int temp;
	temp = *aptr;
	*aptr = *bptr;
	*bptr = temp;
}
*/

/*
#include <stdio.h>
void getFactorial(int *n)
{
	int number = *n;
	*n = 1;
	while (number > 0){
		*n *= number;
		number--;
	}
}
int main()
{
	int n;
	scanf("%d", &n);
	printf("Your number is: %d\n", n);
	getFactorial(&n);
	printf("The factorial of that number is: %d\n", n);
	return 0;
}
*/

/*
#include <stdio.h>
int main()
{
	int highest, spaces, spaces2, stars, stars2;
	stars = stars2 = 1;
	printf("Enter the highest number of stars: \n");
	scanf("%d", &highest);
	spaces = spaces2 = highest / 2;
	while (stars2 <= highest){
		for(spaces = spaces2; spaces > 0; spaces--){
			printf(" ");
		}
		for(stars = stars2; stars > 0; stars--){
			printf("*");
		}
		printf("\n");
		spaces2--;
		stars2 = stars2 + 2;
	}
	spaces = spaces2 = 1;
	stars = stars2 = stars2 - 2;
	while(stars2 >= 1){
		for(spaces = spaces2; spaces > 0; spaces--){
			printf(" ");
		}
		for(stars = stars2; stars > 0; stars--){
			printf("*");
		}
		printf("\n");
		spaces2++;
		stars2 = stars2 - 2;
	}
	return 0;

}
*/

/*
#include <stdio.h>

void swapNumbers(int *xptr, int *yptr);
int getNumbers();
int main()
{
	int x, y;
	printf("Enter first number: \n");
	x = getNumbers();
	printf("Enter second number: \n");
	y = getNumbers();
	printf("x is %d; y is %d\n", x, y);
	swapNumbers(&x, &y);
	printf("x is %d; y is %d\n", x, y);
	return 0;
}
int getNumbers()
{
	int n;
	scanf("%d", &n);
	return n;
}
void swapNumbers(int *xptr, int *yptr)
{
	int temp;
	temp = *xptr;
	*xptr = *yptr;
	*yptr = temp;
	printf("%d\n", *xptr);
	printf("%p\n", &xptr);
}
*/
/* &xptr refers to the address of pointer variable xptr, while xptr refers to the address of the variable the pointer variable xptr is pointing to */

/*
#include <stdio.h>
void findSumOrProd(int *x, int y);
int main()
{
	int a, b;
	scanf("%d", &a);
	scanf("%d", &b);
	findSumOrProd(&a, b);
	printf("a = %d", a);
	return 0;
}
void findSumOrProd(int *x, int y)
{
	if (*x < y){
		*x += y;
	} else {
		*x *= y;
	}
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
	int Anum, Aden, Bnum, Bden, Cden, Cnum1, Cnum2, Cnum, gcf;
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
	gcf = getGCF(Cden, Cnum);
	if (gcf > 1){
		Cnum /= gcf;
		Cden /= gcf;
	}
	printf("The sum of the fractions %d/%d and %d/%d is %d/%d", Anum, Aden, Bnum, Bden, Cnum, Cden);
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
	int prod;
	prod = n1 * n2;
	return prod;
}
int getQuotient(int n1, int n2)
{
	int quo;
	quo = n1 / n2;
	return quo;
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
	float n = 6;
	printf("%-.2f\n %.2f", n, n);
	return 0;
}
*/

/*
#include <stdio.h>
int main()
{
	int n, div, divisible = 0;
	scanf("%d", &n);
	printf("Your number is %d.\n", n);
	while (n > 0){
		for (div = 1; div <= n; div++){
			if (n % div == 0){
				divisible++;
			}
		}
		if (divisible > 2){
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
	int highest, space, spaces, star, stars;
	scanf("%d", &highest);
	for(space = spaces = highest / 2, stars = 1; stars <= highest; stars = stars + 2, spaces--){
		for(space = spaces; space > 0; space--){
			printf(" ");
		}
		for(star = stars; star > 0; star--){
			printf("*");
		}
		printf("\n");
	}
	return 0;
}
*/
















