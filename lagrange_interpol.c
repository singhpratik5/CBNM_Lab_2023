#include <stdio.h>

// Function for calculating Lagrange polynomial
double lagrangeInterpolation(double x[], double y[], int n, double x_query) 
{
    double result = 0.0;

    for (int i = 0; i < n; i++) {
        double term = y[i];

        for (int j = 0; j < n; j++) {
            if (j != i) {
                term = term * (x_query - x[j]) / (x[i] - x[j]);
            }
        }

        result += term;
    }

    return result;
}

int main() {
    double x[] = {0.5, 1.0, 1.5,2.0,2.5, 3.0}; // x values
    double y[] = {2.8, 3.9, 2.1, 6.0,6.6,7.0}; // corresponding y values
    int N = sizeof(x) / sizeof(x[0]); // number of data points

    double x_query = 2.6; // The x value for which we want to find the corresponding y value

    double y_query = lagrangeInterpolation(x, y, N, x_query);
    printf("The interpolated value at x = %.2f is y = %.2f\n", x_query, y_query);

    return 0;
}