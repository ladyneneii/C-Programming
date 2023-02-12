// Online C compiler to run C program online
#include <stdio.h>
#include<stdlib.h>
#ifndef MYHEADER_H
#define MYHEADER_H

#define MAX 0x14
#define END -0x1

typedef int *List;

/*Create an integer array (List) by the specified 
  size and make it empty by setting the first index 
  with the terminating sequence (END). 
  Returns the newly created List. */
List createList(int size);

/*Inserts the element at the end. Take into 
  consideration that the terminating sequence will
  take one space in the array. If empty, the end is
  the first index.*/
void addElement(List list, int item);

/*Display the content of the integer array (List). */
void display(List list);

List getOdd(List list);

//Please take note that the end of the list is 
//terminating sequence (END)
#endif
int main() {
   int size, val;
    List myList, evenNumbers;

    printf("Enter the size: ");
    scanf("%d", &size);

    myList = createList(size);
    
    printf("Enter the values: ");
    for(int i = 0; i < size-1; ++i) { // it has to be size-1 because END takes one space, so an array of size 5 will hold 4 elements + END (i think)
        scanf("%d", &val);
        addElement(myList, val); 
    }

    printf("\n");
    display(myList);

    evenNumbers = getOdd(myList);
    printf("\n");
    printf("\nOddnumbers: ");
    display(evenNumbers);

    printf("\n");

    return 0;
}





/*Create an integer array (List) by the specified 
  size and make it empty by setting the first index 
  with the terminating sequence (END). 
  Returns the newly created List. */
List createList(int size) {
    List list = malloc(sizeof(int) * size);

    if(list != NULL) {
        list[0] = END;
    }

    return list; // added line of code
}

/*Inserts the element at the end. Take into 
  consideration that the terminating sequence will
  take one space in the array. If empty, the end is
  the first index.*/
void addElement(List list, int item) {
    /*
    int count = 0;

    while(list[count++] != END) {}
    
    if(count < MAX) {
        list[count-1] = item;
        list[count] = END;
    }
    */ 

    // code above modified
    int count;

    for (count = 0; list[count] != END; count++){}
    list[count] = item;
    list[count+1] = END;
}

/*Display the content of the integer array (List). */
void display(List list) {
    int i = 0;

    printf("{");
    while(list[i] != END) {
        
        printf("%d ", list[i++]);
    }
    printf("}");
}

List getOdd(List list){
    /*
	int x=0, count=0,j;
	while(list[count++]!=END){}

	printf("\ncount: %d", count);
	List yes = malloc(sizeof(int) * (count));
	printf("\nsize: %d", sizeof(yes));
	 
	for( j=0; j < count; j++){
		if(list[j]%2!=0){
		    
			yes[j] = list[j];
			 printf("\nyes: %d",yes[j])  ; 
			 printf("\nlist: %d",list[j])  ; 
		}    
	}
		  if(yes[j] == 0){
		      yes[j-1];
		  }
		  return yes;
    */


    // code above modified
    int idx, idx2;
    List yes;

    for (idx = 0; list[idx] != END; idx++){}
    yes = (int *)malloc(idx*sizeof(int));
    for (idx = idx2 = 0; list[idx] != END; idx++){
        if (list[idx] % 2 != 0){
            yes[idx2] = list[idx];
            idx2++;
        }
    }
    yes[idx2] = END;

    return yes;
}

        
	

//Please take note that the end of the list is 
//terminating sequence (END)