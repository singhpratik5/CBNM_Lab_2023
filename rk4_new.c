#include<stdio.h>

double fxn(double x , double y)
{
    return 4*x + 3*y;
}

double range_kutta_4(double x0,double y0,double x_n,double h)
{
    double k1 = 0,k2 = 0,k3 = 0,k4 = 0,k = 0,y_n;
    y_n = 0;
    do
    {
        k1 = h*fxn(x0,y0);
        k2 = h*fxn((x0+(h/2)),((k1/2)+y0));
        k3 = h*fxn((x0+(h/2)),(y0+(k2/2)));
        k4 = h*fxn(x0+h,y0+k3);
        k = (k1 + 2*k2 + 2*k3 + k4)/6;
        x0 = x0 + h;
        printf(" value of the k2 is :");
        printf("%lf %lf %lf %lf \n",k1,k2,k3,k4);
        y_n = y0 + k;
        printf("%lf\n",y_n);
        y0 = y_n;
    } while(x0 < x_n);
    
    return y_n;
}

int main()
{
    double h = 0.1;
    double x_n;
    double x0; 
    double y0;
    printf("Enter the x0 and y0\n");
    scanf("%lf %lf",&x0 ,&y0);

    printf("Enter the place where we have to find x_n\n");
    scanf("%lf",&x_n);

    printf("%lf",range_kutta_4(x0,y0,x_n,h));
}