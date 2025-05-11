#include <stdio.h>
#include <math.h>

// using trapezoidal rule for numerical integration. Simpsons rule is downwards : 

// Defining my functions here
double fxn(double x) {
    return x * x; 
}

double g(double x) {
    return x; 
}

double length_of_curve(double a, double b, double (*func)(double), double n) {
    double h = (b - a) / n;
    double sum = 0.0;
    for (int i = 0; i <= n; i++) {
        double x = a + i * h;
        double dx = h;
        double dy = func(x + h) - func(x);
        sum += sqrt(dx * dx + dy * dy);
    }
    return sum;
}

double area_under_curve(double a, double b, double (*func)(double), double n) {
    double h = (b - a) / n;
    double sum = 0.5 * (func(a) + func(b));
    for (int i = 1; i < n; i++) {
        sum += func(a + i * h);
    }
    return sum * h;
}

double area_between_curves(double a, double b, double (*func1)(double), double (*func2)(double), double n) {
    return fabs(area_under_curve(a, b, func1, n) - area_under_curve(a, b, func2, n));
}

// AREA USING SIMPSONS RULE :

double simpsons_rule(double a, double b, double (*func)(double), int n) {
    double h = (b - a) / n;
    double sum = func(a) + func(b);
    for (int i = 1; i < n; i++) {
        double x = a + i * h;
        if (i % 2 == 0) {
            sum += 2 * func(x);
        } else {
            sum += 4 * func(x);
        }
    }
    return sum * h / 3;
}
/*
int main() 
{

    printf("Length of curve: %f\n", length_of_curve(0.0, 1.0, fxn, 1000));
    printf("Area under curve (trapezoidal rule): %f\n", area_under_curve(0.0, 1.0, fxn, 1000));
    printf("Area under curve (Simpson's rule): %f\n", simpsons_rule(0.0, 1.0, fxn, 1000));
    printf("Area between curves: %f\n", area_between_curves(0.0, 1.0, fxn, g, 1000));
}
*/