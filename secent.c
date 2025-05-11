#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#define EPSILON 0.001

float function(float x)
{
    float y = x*x*x - x*x + 5*x -10;
    return y;
}

float findX(float x1,float x2)
{
     return(x1*function(x2) - x2*function(x1))/(function(x2)-function(x1));
}

void secent(int x1,int x2,int n)
{
    float x3;
    int i = 1;
    x3 = findX(x1,x2);
    do
    {
        x1 = x2;
        x2 = x3;
        printf("iteration = %d and root = %f\n",i,x3);
        x3 = findX(x1,x2);
        if(func(x3-x2)<EPSILON)
        {
            printf("root is %f and iterations are : %d",x3,i+1);
            return;
        }
        i++;
    }
    while(i<=n);
}
/*
int main()
{
    float x1,x2;
    printf("Enter the x1,x2\n");
    scanf("%f""%f",&x1,&x2);
    int n;
    while(function(x1)*function(x2)>0)
    {
    printf("Enter the x1,x2\n");
    scanf("%f""%f",&x1,&x2);
    }
    printf("Enter the max iterations\n");
    scanf("%d",&n);
    secent(x1,x2,n);
    exit(0);
}
*/