#include <stdio.h>

// Function for linear interpolation
double linearInterpolation(double x0, double y0, double x1, double y1, double x)
{
    if (x0 == x1) {
        printf("Error! x0 and x1 cannot be the same value.\n");
        return 0.0;
    }
    double y = y0 + ((y1 - y0) / (x1 - x0)) * (x - x0);
    return y;
}

int main() {
    //(0.5,2.8),(1.0,3.9),(1.5,2.1),(2.0,6.0),(2.5,6.6),(3.0,7.0)
    double x[] = {0.5, 1.0, 1.5, 2.0, 2.5,3.0}; // x values
    double y[] = {2.8, 3.9, 2.1, 6.0, 6.6,7.0}; // corresponding y values
    int N = sizeof(x) / sizeof(x[0]); // number of data points

    double x_query = 2.6; // The x value for which we want to find the corresponding y value

    // Find the interval that contains x_query
    int i;
    for (i = 0; i < N - 1; i++) {
        if (x[i] <= x_query && x_query <= x[i + 1]) {
            break;
        }
    }

    double y_query = linearInterpolation(x[i], y[i], x[i + 1], y[i + 1], x_query);
    printf("The interpolated value at x = %.2f is y = %.2f\n", x_query, y_query);

    return 0;
}
