/*
#include <stdio.h>

typedef struct{
		char firstName[24];
		char middleInitial;
		char lastName[16];
		int age;
		char gender;
} info;

info getValues();
void display(info details);
void output(info *detalye);

int main(){

	info personA = getValues();

	display(personA);
	output(&personA);

	info *ptx = &personA;

	printf("%s\n", ptx->firstName);
	printf("%c\n", ptx->middleInitial);
	printf("%s\n", ptx->lastName);
	printf("%d\n", ptx->age);
	printf("%c\n", ptx->gender);

return 0;

}

info getValues(){

	info values;

	printf("Enter first name: \n");
	scanf("%s", values.firstName);

	printf("Enter middle initial: \n");
	scanf(" %c", &(values.middleInitial));

	printf("Enter last name: \n");
	scanf("%s", values.lastName);

	printf("Enter age: \n");
	scanf("%d", &(values.age));

	printf("Enter gender: \n");
	scanf(" %c", &(values.gender));

	return values;
}

void display(info details)
{
	printf("%s\n", details.firstName);
	printf("%c\n", details.middleInitial);
	printf("%s\n", details.lastName);
	printf("%d\n", details.age);
	printf("%c\n", details.gender);
}

void output(info *detalye)
{
	printf("%s\n", (*detalye).firstName);
	printf("%c\n", (*detalye).middleInitial);
	printf("%s\n", (*detalye).lastName);
	printf("%d\n", (*detalye).age);
	printf("%c\n", (*detalye).gender);
}
*/


#include <stdio.h>

typedef struct{
		char name[20];
		char sex;
		char gender;
		char SO[20];
		int age;
	} details;


	
	typedef struct{
		details personAA;  //cannot be accessed without using a variable for datatype section. you cannot do function(&personAA); it has to be function(&yaskween.personAA)
		details personB;
		details personC;
		int N;
	} section;
	
	section yaskween;

	details personA = {"Nene", 'M', 'M', "homosexual", 19};
	// yaskween.personB = {"Manny", 'M', 'M', 'heterosexual', 67}; NOT ALLOWED APPARENTLY
	

void display(details *person);
void output(details person);
int anotherFunction(int number);
void secondFunction(details *ads, details adss, details adsss);

int main()
{

	display(&personA);
	// display(&yaskween.personB);
	output(personA);
	printf("%d\n", anotherFunction(yaskween.N));
	secondFunction(&yaskween.personAA, yaskween.personAA, yaskween.personC);

	return 0;
}

void display(details *person)
{
	printf("%s\n", person->name);
}

void output(details person)
{
	printf("%s\n", person.SO);
}

int anotherFunction(int number)
{
	number = 5;
	return number;
}

void secondFunction(details *ads, details adss, details adsss)
{
	// *ads = {"Mary", 'F', 'W', "bisexual", 20}; NOT ALLOWED APPARENTLY
	(*ads).age = 20;
	printf("%d\n", ads->age);
	printf("Enter gender: \n");
	scanf(" %c", &ads->gender);
	printf("%c\n", ads->gender);
	printf("Enter sex: \n");
	scanf(" %c", &adss.sex);  // no need for parentheses &(adss.sex)
	printf("%c\n", adss.sex);
	
	adsss = {"Mary", 'F', 'W', "bisexual", 20}; //NOT ALLOWED APPARENTLY AS WELL. it keeps saying expected expression
	printf("%s\n", adsss.SO);

}

