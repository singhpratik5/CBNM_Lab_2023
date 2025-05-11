#include<stdio.h>

#define N 3

void luDecomposition(double A[N][N], double L[N][N], double U[N][N]) {
    int i = 0, j = 0, k = 0;
    for (i = 0; i < N; i++) {
        for (j = 0; j < N; j++) {
            if (j < i)
                L[j][i] = 0;
            else {
                L[j][i] = A[j][i];
                for (k = 0; k < i; k++) {
                    L[j][i] = L[j][i] - L[j][k] * U[k][i];
                }
            }
        }
        for (j = 0; j < N; j++) {
            if (j < i)
                U[i][j] = 0;
            else if (j == i)
                U[i][j] = 1;
            else {
                U[i][j] = A[i][j] / L[i][i];
                for (k = 0; k < i; k++) {
                    U[i][j] = U[i][j] - ((L[i][k] * U[k][j]) / L[i][i]);
                }
            }
        }
    }
}

void forwardSubstitution(double L[N][N], double b[N], double y[N]) {
    for(int i=0; i<N; i++) {
        y[i] = b[i];
        for(int j=0; j<i; j++) {
            y[i] -= L[i][j]*y[j];
        }
        y[i] /= L[i][i];
    }
}

void backwardSubstitution(double U[N][N], double y[N], double x[N]) {
    for(int i=N-1; i>=0; i--) {
        x[i] = y[i];
        for(int j=i+1; j<N; j++) {
            x[i] -= U[i][j]*x[j];
        }
        x[i] /= U[i][i];
    }
}

void printMatrix(double M[N][N]) {
    for(int i=0; i<N; i++) {
        for(int j=0; j<N; j++)
            printf("%lf ", M[i][j]);
        printf("\n");
    }
}
/*
int main() {
    double A[N][N] = {{4,1,1}, {2,2,1}, {1,1,1}};
    double b[N] = {7,6,5};
    double L[N][N], U[N][N], y[N], x[N];

    luDecomposition(A, L, U);
    
    printf("L matrix:\n");
    printMatrix(L);
    
    printf("U matrix:\n");
    printMatrix(U);

    forwardSubstitution(L, b, y);
    backwardSubstitution(U, y, x);

    printf("Solution: ");
    for(int i=0; i<N; i++)
        printf("%lf ", x[i]);
    printf("\n");

    return 0;
}
*/