#include <stdio.h>
#include <math.h>

#define N 20 

double f(double t) {
    // define your function here : 
    return t*t;
}

void gauss_eliminate(double a[N][N], double b[N]) {
    int i, j, k;
    for(i = 0; i < N; i++) {
        for(j = i+1; j < N; j++) {
            double factor = a[j][i] / a[i][i];
            for(k = i; k < N; k++) {
                a[j][k] -= factor * a[i][k];
            }
            b[j] -= factor * b[i];
        }
    }
}

void back_substitute(double a[N][N], double b[N], double x[N]) {
    int i, j;
    for(i = N-1; i >= 0; i--) {
        x[i] = b[i];
        for(j = i+1; j < N; j++) {
            x[i] -= a[i][j] * x[j];
        }
        if(a[i][i] == 0) {
            printf("Error: Division by zero\n");
            return;
        }
        x[i] /= a[i][i];
    }
}


double* ode_bvalue(double (*func)(double), double x1, double x2, double t1, double t2, double h) {
    double *x = (double*) malloc((N+2) * sizeof(double)); // dynamically allocate memory for x
    double a[N][N], b[N]; // arrays for tridiagonal matrix and RHS
    int i;

    // initialize the tridiagonal matrix and RHS
    for(i = 0; i < N; i++) {
        a[i][i] = -2 / (h * h);
        if(i > 0) {
            a[i][i-1] = 1 / (h * h);
        }
        if(i < N-1) {
            a[i][i+1] = 1 / (h * h);
        }
        b[i] = f(t1 + (i+1) * h);
    }
    b[0] -= x1 / (h * h);
    b[N-1] -= x2 / (h * h);

    // Gauss elimination
    gauss_eliminate(a, b);

    // Back substitution
    back_substitute(a, b, x);

    return x;
}


int main() {
    double t1 = 0, t2 = 1; // boundary times
    double x1 = 0, x2 = 1; // boundary values
    double h = 0.2; // step size
    double* xvals = ode_bvalue(f, x1, x2, t1, t2, h);

    // print the solution
    for(int i = 0; i < N+2; i++) {
        printf("x[%d] = %f\n", i, xvals[i]);
    }

    free(xvals); // free the memory allocated for xvals

    return 0;
}
