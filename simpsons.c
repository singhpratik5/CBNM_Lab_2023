#include<stdio.h>
#include<math.h>

double simpsons_even(double *x,double *y,double h,int n)
{
    double odd = 0;
    double even = 0;
    for(int i =1;i<n;i++)
    {
        if(i%2 == 1)
        odd = odd + y[i];
    }
    odd = 4*odd;
    for(int i =1;i<n;i++)
    {
        if(i%2 == 0)
        even = even + y[i];
    }
    even = even*2;

    return (h*(y[0]+y[n]) + odd + even)/3;
}

double simpsons_odd(double *x,double *y,double h)
{
    double multpl_3 = 0;
    double non_multpl_3 = 0;

    
}

int main()
{
    int n;
    int a,b;
    double h;
    double x[] = {};
    double y[] = {};

    h = (b - a)/n;

}