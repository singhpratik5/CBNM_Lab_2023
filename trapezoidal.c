#include <stdio.h>
#include <math.h>

#define PI 3.14159265358979323846

double trapezoidal_rule(double (*f)(double), double a, double b, int n) {
    double dx = (b - a) / n;
    double sum = 0.5 * (f(a) + f(b));
    for (int i = 1; i < n; i++) {
        double x = a + i * dx;
        sum += f(x);
    }
    return dx * sum;
}

int main() {
    double (*f)(double) = &sin;
    double a = 0.0, b = PI / 2.0;
    int n = 1000;
    double length = trapezoidal_rule(f, a, b, n);
    printf("Length of curve: %f\n", length);   
    return 0;
}
