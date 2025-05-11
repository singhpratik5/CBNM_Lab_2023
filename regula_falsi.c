#include<stdio.h>
#include<stdlib.h>

float func(float x)
{
    float y = x*x*x - 2*x*x + 10;
    return y;
}

void regula_falsi(float x1,float x2,int n)
{
    int i = 1;
    
    while(i<=n)
    {
    float x3 = (x1*func(x2) - x2*func(x1))/(func(x2)-func(x1));
    if(func(x3)<0)
    {
        x2 = x3;
    }
    else
    {
        x1 = x3;
    }
    i++;
    printf("iteration = %d and root = %f\n",i,x3);
    }
}
/*
int main()
{
    float x1,x2;
    printf("Enter the x1,x2\n");
    scanf("%f""%f",&x1,&x2);
    int n;
    while(func(x1)*func(x2)>0)
    {
    printf("Enter the x1,x2\n");
    scanf("%f""%f",&x1,&x2);
    }
    printf("Enter the max iterations\n");
    scanf("%d",&n);
    regula_falsi(x1,x2,n);
    exit(0);
}
*/