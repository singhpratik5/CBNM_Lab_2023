#include <stdio.h>
#include<math.h>

#define N 8

void vandermonde(double x[], double y[], int n) {
    double vanderMatrix[N][N], coefficients[N];

    // Create the Vandermonde matrix
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            vanderMatrix[i][j] = pow(x[i], j);
        }
    }

    // Solve the system of linear equations using Gaussian elimination
    for (int i = 0; i < n; i++) {
        for (int k = i + 1; k < n; k++) {
            double factor = vanderMatrix[k][i] / vanderMatrix[i][i];
            for (int j = 0; j < n; j++) {
                vanderMatrix[k][j] -= factor * vanderMatrix[i][j];
            }
            y[k] -= factor * y[i];
        }
    }

    // Back substitution
    for (int i = n - 1; i >= 0; i--) {
        coefficients[i] = y[i];
        for (int j = i + 1; j < n; j++) {
            coefficients[i] -= vanderMatrix[i][j] * coefficients[j];
        }
        coefficients[i] /= vanderMatrix[i][i];
    }

    // Print the coefficients
    printf("The coefficients of the polynomial are:\n");
    for (int i = 0; i < n; i++) {
        printf("%lf\n", coefficients[i]);
    }
}

double polynomial(double coefficients[], double x, int degree) {
    double y = 0;
    for (int i = 0; i <= degree; i++) {
        y += coefficients[i] * pow(x, i);
    }
    return y;
}

int main() {
    double x[N] = {0, 1, 2, 3, 4, 5, 6, 7};
    double y[N] = {1.5, 0.5, 0.3, 2, 2.5, 1.7, 2, 2.5};

    vandermonde(x, y, N);
    double coefficients[N] = {1.500000,3.082857,-8.845278,6.512917,-2.034028,0.303750,-0.020694, 
    .000476};

     double dx = 0.5;
    for(double x_val = dx; x_val <= N - dx/2; x_val += dx)
   {
        double y_val = polynomial(coefficients, x_val, N - 1);
       printf("At x = %.1lf cm, y = %.2lf\n", x_val, y_val);
   }
    
    double length = 0;
    
    for (int i = 0; i < N - 1; i++) {
        double x_i = i * dx;
        double y_i = polynomial(coefficients, x_i, 7);
        double y_next = polynomial(coefficients, x_i + dx, 7);
        length += sqrt(1 + pow((y_next - y_i) / dx, 2)) * dx;
    }

    printf("The length of the curve is %.2lf\n", length);
  return 0;
}

