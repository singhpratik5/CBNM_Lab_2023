#include<stdio.h>
#include<math.h>

#define EPSILON 0.001

double f(double x) {
    // Write your function equation here
    return x*x - x - 1;
}

double df(double x) {
    // Write the derivative of your function here
    return 2*x - 1;
}

void newtonRaphson(double x) {
    double h = f(x) / df(x);
    while (fabs(h) >= EPSILON) {
        h = f(x)/df(x);
        x = x - h;
    }
 
    printf("The root is: %lf\n", x);
}
/*
int main() {
    double x0 = 2; // Initial values assumed
    newtonRaphson(x0);
    return 0;
}
*/