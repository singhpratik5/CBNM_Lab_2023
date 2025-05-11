#include<stdio.h>

// Considered differential equation "dy/dx = y"
float dydx(float x, float y)
{
    return (3*y + 4*x);
}

// Function for Euler formula
void euler(float x0, float y, float h, float x)
{
    float temp = -0;

    // Iterating till the point at which we
    // need approximation
    while (x0 < x)
    {
        temp = y;
        y = y + h * dydx(x0, y);
        x0 = x0 + h;
    }

    // Printing approximation
    printf("\nApproximate solution at x = %f is  %f\n", x, y);
}

// Driver function
int main()
{
    // Initial Values
    float x0 = 0;
    float y0 = 2/3;
    float h = 0.01;

    // Value of x at which we need approximation
    float x = 1.8;

    euler(x0, y0, h, x);
    return 0;
}
