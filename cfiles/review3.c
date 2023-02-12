#include <stdio.h>
#include <stdlib.h>

// Exercise 3a
typedef int MyMatrix[4][3]; 

int **addMat(int firstMat[][3], int secondMat[][3]);
// or int **addMat(MyMatrix firstMat, MyMatrix secondMat);

void Exercise4();

int main()
{
    MyMatrix A = {2, 5, 8, 2, 1, 6, 9, 5, 3, 1, 4, 0};
    MyMatrix B = {1, 2, 7, 9, 2, 6, 8, 2, 5, 9, 0, 1};
    int x, y;

    printf("Matrix A:\n");
    for(x = 0; x < 4; x++){
        for(y = 0; y < 3; y++){
            printf("%d ", A[x][y]);
        }
        printf("\n");
    }
    printf("\n\n");

    printf("Matrix B:\n");
    for(x = 0; x < 4; x++){
        for(y = 0; y < 3; y++){
            printf("%d ", B[x][y]);
        }
        printf("\n");
    }
    printf("\n\n");

    int **C = addMat(A, B);

    printf("Sum of Matrices A and B:\n");
    for(x = 0; x < 4; x++){
        for(y = 0; y < 3; y++){
            printf("%d ", C[x][y]);
        }
        printf("\n");
    }
    printf("\n\n");

    Exercise4();

    return 0;
}

int **addMat(int firstMat[][3], int secondMat[][3]){
// or int **addMat(MyMatrix firstMat, MyMatrix secondMat), but NOT int **addMat(int **firstMat, int **secondMat) or MyMatrix addMat(int **firstMat, int **secondMat). Only use int ** for returning/passing/accessing ONE pointer only. You can use MyMatrix in the function header because you have to define the number of rows and/or columns in the function header, but not in the return type.
// use MyMatrix when you are defining the rows and columns. Use int ** if you are defining only ONE pointer.
    int **sumMat = (int **)malloc(4 * sizeof(int *));
    int x, y; 

    for(x = 0; x < 4; x++){
        sumMat[x] = (int *)malloc(3 * sizeof(int));
    }

    for(x = 0; x < 4; x++){
        for(y = 0; y < 3; y++){
            sumMat[x][y] = firstMat[x][y] + secondMat[x][y];
        }
    }

    return sumMat;
}

// Exercise 4
void Exercise4()
{
    // 1.)
    int A[2][3][4];

    // 2a.)
    A[1][0][0] = 5;
    // 2b.)
    A[1][1][2] = 6;
    // 2c.)
    A[0][0][3] = 7;
}