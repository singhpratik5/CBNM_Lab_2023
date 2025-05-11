//#include"cbnm_22mcce24.h"
#include<stdio.h>

void createAugmentedMatrix(float [][], float [N], float [N][N+1]);
void printMatrix(float [N][N+1]);
void gaussianElimination(float [N][N+1]);
void backSubstitution(float [N][N+1], float [N]);

double f(double );
double g(double ); 
double length_of_curve(double , double , double (*)(double), double );
double area_under_curve(double , double , double (*)(double), double );
double area_between_curves(double , double , double (*)(double), double (*)(double), double );
double simpsons_rule(double , double , double (*)(double), int );

float func(float );
void regula_falsi(float x1,float x2,int n);

float function(float );
void bisection(float ,float );

void jacobi(float [N][N], float [N], float [N], int );

double f(double );
double df(double );
void newtonRaphson(double ); 

float func(float );
float findX(float ,float );
void secent(int ,int ,int );

double piecewise_linear(double , double , double , double , double , double , double );
double vandermonde(double , double *, int );
double lagrange(double , double *, double *, int );



void luDecomposition(double [][], double [][], double [][]);
void forwardSubstitution(double [][], double [], double []);
void backwardSubstitution(double [][], double [], double []); 
void printMatrix(double [][]);

void vandermonde(double x[], double y[], int );
double polynomial(double [], double , int );