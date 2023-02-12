#include<stdio.h>
#include<stdlib.h>
/*Using the concept that the arrays are delimited by -1.
  If the array is empty then the first index contains 
  the value -1.*/

int *get_numbers(int items[], int limit);

int main(void) {
    int n,b;
  	printf("Enter size: ");
  	scanf("%d", &n);
  
  	
  	/* int arr[n]; 
    printf("Enter data: ");
     	for(int i = 0; i<n; i++){
          scanf("%d", &arr[i]);
        }
    */
	// n++;  ------------ if ang size kay 5, then n = 5. n++ will make it 6.
  	// arr[n] = -1; ------------ so you are assigning -1 to arr[6], which is beyond the size that you assigned to the array arr. array arr has a size of 5, meaning arr[4] ang last index niya, pero naa kay 2 extra indices that are beyond the size, which are arr[5] (garbage value, 0 sa imoha i think) and arr[6] (which has -1)
    // meaning, if ang mga inputted values kay 61, 23, 50, 36, 69, then ang sud sa array kay arr[0] = 61, arr[1] = 23, arr[2] = 50, arr[3] = 36, arr[4] = 69, arr[5] = 0 (garbage value), arr[6] = -1.
    // dili recommended nga mag assign kag -1 sa arr[5] kay arr[5] is beyond the size nga imong giassign. basin muwork ra syas compiler pero basig wrongan ka ana. if 5 ang size, dapat 4 ra ang inputted values unya -1 sa last index, OR if 5 ang size, pwede ra nimo e increment ang 5 para mahimog 6 arun 5 gihapon ang inputted values unya -1 sa last.

    int arr[n+1]; 

    printf("Enter data: ");
    for(int i = 0; i<n; i++){
        scanf("%d", &arr[i]);
    }
    arr[n] = -1;
    
  	printf("Enter limit: ");
  	scanf("%d", &b);
	
  	printf("Result: ");
  	int counter =0; // para asa ni ?
  	int *result = get_numbers(arr,b);
  	for (int i = 0; result[i] != -1; i++){
      printf("%d ", result[i]);
      counter = counter + 1; // para asa ni ?
    }
    
     free(result);
    return 0;
}

int *get_numbers(int items[], int limit) {
  
      int idx,counts = 0;
  		for(int i = 0; items[i] != -1; i++){
          counts = counts + 1;
        } 

      // int *k = malloc(sizeof(int) * counts); ------ counts = 5. dapat 6 siya to accommodate -1. di rapud needed ang counts variable. just use i++ for the malloc size.
      int *k = malloc(sizeof(int) * counts++);
       k[0] = -1;
    int count = 0;
      for (count = idx = 0; items[count] != -1; count++){ // redundant ang pag initialise sa count sa for loop
            if(items[count] < limit){
                 k[idx] = items[count];
                 k[idx + 1] = -1;
                 idx++;
            }
                
      }
  			    
         
      return k;
}