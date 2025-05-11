#include<stdio.h>
#include<stdlib.h>
#define N 5

/*
void createAugmentedMatrix(float A[N][N], float B[N], float C[N][N+1]) {
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            C[i][j] = A[i][j];
        }
        C[i][N] = B[i];
    }
}

void printMatrix(float C[N][N+1]) {
    for (int i = 0; i < N; i++) {
        for (int j = 0; j <= N; j++) {
            printf("%.2f ", C[i][j]);
        }
        printf("\n");
    }
}

void gaussianElimination(float a[N][N+1]) {
    for (int i=0; i<N-1; i++) {
        for (int j=i+1; j<N; j++) {
            float factor = a[j][i]/a[i][i];
            for (int k=0; k<=N; k++)
                a[j][k] -= factor * a[i][k];
        }
    }
}

void backSubstitution(float a[N][N+1], float x[N]) {
    for (int i=N-1; i>=0; i--) {
        x[i] = a[i][N];
        for (int j=i+1; j<N; j++) {
            x[i] -= a[i][j]*x[j];
        }
        x[i] = x[i]/a[i][i];
    }
}
*/
/*
int main()
{

    float A[N][N] = {{-2,-1,6,-4,4}, {-4,-4,-2,1,-5}, {5,-3,5,1,-3},{1,6,4,6,-4},{6,2,-1,-2,6}}; // coefficient matrix
    float B[N] = { 12,-61,-23,29,55}; // RHS matrix
    float C[N][N+1]; // augmented matrix
    float x[N]; // solutions

    createAugmentedMatrix(A, B, C);

    printf("Original Augmented Matrix:\n");
    printMatrix(C);

    gaussianElimination(C);

    printf("\nAugmented Matrix after Gaussian Elimination:\n");
    printMatrix(C);

    backSubstitution(C, x);

    printf("\nSolution:\n");
    for (int i=0; i<N; i++)
        printf("x%d = %.2f\n", i+1, x[i]);

    return 0;
}
*/