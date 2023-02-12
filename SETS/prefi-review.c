#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int *buildHeap(int arr[]);

int main()
{
    int arr[] = {4, 5, 9, 3, 1, 0, 10, 4, -1};

    int *resArr = buildHeap(arr);

    int idx;

    for (idx = 0; resArr[idx] != -1; idx++){
        printf("%d ", resArr[idx]);
    }

    return 0;
}

int *buildHeap(int arr[])
{
	int *resArr, lastndx;

    for (lastndx = 0; arr[lastndx] != -1; lastndx++){}
    resArr = (int *)malloc(++lastndx * sizeof(int));

	if (resArr != NULL){
		int pi, oldpi, lci, rci, temp;

		memcpy(resArr, arr, lastndx * sizeof(int));
        lastndx -= 2;
		pi = (lastndx)/2;
		oldpi = pi;
		while (pi > -1){
			lci = pi*2+1;
			rci = lci+1;
			while (lci <= lastndx){
				if (resArr[pi] > resArr[lci] || (rci <= lastndx && resArr[pi] > resArr[rci])){
					if (resArr[pi] > resArr[lci]){
						if (rci <= lastndx && resArr[lci] > resArr[rci]){
							lci = rci;
						}
					} else if (rci <= lastndx && resArr[pi] > resArr[rci]){
						lci = rci;
					}
					temp = resArr[pi];
					resArr[pi] = resArr[lci];
					resArr[lci] = temp;
                }
                pi = lci;
                lci = pi*2+1;
                rci = lci+1;
			}
			pi = --oldpi;
		}
	}

	return resArr;
}