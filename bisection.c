#include<stdio.h>
#include<stdlib.h>
//x1 , x2 -> initial values , n -> max iterations.

float function(float x)
{
    float y = 4*x*x*x*x*x - 3*x*x + 14*x -26;
    return y;
}

void bisection(float x1,float x2)
{
    
    printf("root is between %f & %f\n",x1,x2);
    int i = 1;
    int n;
    printf("Enter the max iteration\n");
    scanf("%d",&n);
    while(i<=n)
    {
        float x3;
        x3 = (x1 + x2)/2;
        if(function(x3)*function(x1)<0)
        {
            x2 = x3;
        }
        else if(function(x3)*function(x2)<0)
        {
            x1 = x3;
        }
        printf("iteration = %d and root = %f\n",i,x3);
        i++;
    }
}
/*int main()
{
     // ask for x1,x2 -> [until f(x1).f(x2)!<0]
    float x1=-1,x2=-1;

    while(function(x1)*function(x2)>=0)
    {
        printf(" Enter x1 & x2\n");
        scanf("%f" "%f" ,&x1, &x2);
    }
    bisection(x1,x2);
   
    exit(0);
}
*/

