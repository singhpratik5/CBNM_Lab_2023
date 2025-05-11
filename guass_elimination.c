#include<stdio.h>
#include<conio.h>

#define N 5

void createAugmentedMatrix(double A[N][N], double B[N], double C[N][N+1]) {
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            C[i][j] = A[i][j];
        }
        C[i][N] = B[i];
    }
}

void printMatrix(double C[N][N+1]) {
    for (int i = 0; i < N; i++) {
        for (int j = 0; j <= N; j++) {
            printf("%.3f ", C[i][j]);
        }
        printf("\n");
    }
}

void gaussianElimination(double a[N][N+1]) {
    for (int i=0; i<N-1; i++) {
        for (int j=i+1; j<N; j++) {
            double factor = a[j][i]/a[i][i];
            for (int k=0; k<=N; k++)
                a[j][k] -= factor * a[i][k];
        }
    }
}

void backSubstitution(double a[N][N+1], double x[N]) {
    for (int i=N-1; i>=0; i--) {
        x[i] = a[i][N];
        for (int j=i+1; j<N; j++) {
            x[i] -= a[i][j]*x[j];
        }
        x[i] = x[i]/a[i][i];
    }
} 

int main() {
    double A[N][N] = 
{
/*{12, -1, -1, -1, -1, -1, -1, -3, -1, -1},
{-1, 10, -1, -1, -1, -3, -1, -1, -1, -1},
{-1, -1, 7, 0, 0, 0, -2, 1, 1, 1},
{-2, 1, -1, 15, -5, -1, 0, -2, 3, -1},
{1, 1, 1, 1, -22, 1, 1, 1, -4, 1},
{-3, -3, 0, -1, 0, 9, 0, 0, 0, 0},
{5, -3, -2, -2, 0, 3, 15, -1, -3, -1},
{1, -2, 1, -2, 1, -2, 1, 25, -1, 1},
{1, 1, 1, 1, 1, -1, -1, -1, 18, -1},
{-1, -1, -1, -1, 1, 1, 1, 1, 1, 10}*/
{15.38,5.79,1.83,2.06,2.53}, {6.44,14.87,3.22,2.68,7.33}, {5.17,1.80,12.08,5.9,0.59},{1.01,0.58,5.16,15.85,2.42},{1.84,4.2,1.18,4.46,15.63}
}; // coefficient matrix // ENTER THE MATRIX HERE
    double B[N] = {61.34,105.35,82.31,107.15,126.23}; // RHS matrix
    double C[N][N+1]; // augmented matrix
    double x[N]; // solutions

    createAugmentedMatrix(A, B, C);

    printf("Original Augmented Matrix:\n");
    printMatrix(C);

    gaussianElimination(C);

    printf("\nAugmented Matrix after Gaussian Elimination:\n");
    printMatrix(C);

    backSubstitution(C, x);

    printf("\nSolution:\n");
    for (int i=0; i<N; i++)
        printf("x%d = %.3f\n", i+1, x[i]);

    return 0;
}

