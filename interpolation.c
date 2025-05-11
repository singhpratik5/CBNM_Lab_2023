#include <stdio.h>
#include <stdlib.h>
#include <math.h>

// Function to calculate the value of a piecewise linear function at a given point
double piecewise_linear(double x, double x0, double y0, double x1, double y1, double x2, double y2) {
    if (x < x0) {
        return y0;
    } else if (x < x1) {
        return y0 + (y1 - y0) * (x - x0) / (x1 - x0);
    } else if (x < x2) {
        return y1 + (y2 - y1) * (x - x1) / (x2 - x1);
    } else {
        return y2;
    }
}

// Function to calculate the value of a Vandermonde polynomial at a given point
double vandermonde(double x, double *c, int n) {
    double y = 0;
    for (int i = 0; i < n; i++) {
        y += c[i] * pow(x, i);
    }
    return y;
}

// Function to calculate the value of a Lagrange polynomial at a given point
double lagrange(double x, double *x_data, double *y_data, int n) {
    double L = 0;
    for (int i = 0; i < n; i++) {
        double L_i = 1;
        for (int j = 0; j < n; j++) {
            if (i!= j) {
                L_i *= (x - x_data[j]) / (x_data[i] - x_data[j]);
            }
        }
        L += y_data[i] * L_i;
    }
    return L;
}
/*
int main() {
    // Example for piecewise linear
    double x = 2.5;
    double x0 = 0;
    double y0 = 0;
    double x1 = 1;
    double y1 = 1;
    double x2 = 2;
    double y2 = 0;
    double y = piecewise_linear(x, x0, y0, x1, y1, x2, y2);
    printf("Piecewise linear function: %f\n", y);

    // Example usage of the Vandermonde polynomial function
    double c[] = {1, 2, 3};
    int n = sizeof(c) / sizeof(c[0]);
    double x_vandermonde = 2.5;
    double y_vandermonde = vandermonde(x_vandermonde, c, n);
    printf("Vandermonde polynomial function: %f\n", y_vandermonde);

    // Example usage of the Lagrange polynomial function
    double x_data[] = {0, 1, 2};
    double y_data[] = {0, 1, 0};
    int n_lagrange = sizeof(x_data) / sizeof(x_data[0]);
    double x_lagrange = 1.5;
    double y_lagrange = lagrange(x_lagrange, x_data, y_data, n_lagrange);
    printf("Lagrange polynomial function: %f\n", y_lagrange);

    return 0;
}
*/
