#include <stdio.h>

#define N 5 // Number of equations

void jacobi(float a[N][N], float b[N], float x[N], int n)
{
    float x_new[N];
    for (int i = 0; i < n; i++)
    {
        x_new[i] = x[i];
    }

    for (int k = 0; k < 10; k++)
    { // Number of iterations
        for (int i = 0; i < n; i++)
        {
            float sum = 0;
            for (int j = 0; j < n; j++)
            {
                if (j != i)
                {
                    sum += a[i][j] * x[j];
                }
            }
            x_new[i] = (b[i] - sum) / a[i][i];
        }

        for (int i = 0; i < n; i++)
        {
            x[i] = x_new[i];
        }
    }
}

int main()
{
    float a[N][N] = {{15.38, 5.79, 1.83, 2.06, 2.53}, {6.44, 14.87, 3.22, 2.68, 7.33}, {5.17, 1.80, 12.08, 5.9, 0.59}, {1.01, 0.58, 5.16, 15.85, 2.42}, {1.84, 4.2, 1.18, 4.46, 15.63}}; // Coefficient matrix
    float b[N] = {61.34, 105.35, 82.31, 107.15, 126.23};                                                                                                                                 // Right-hand side vector
    float x[N] = {0, 0, 0, 0, 0};                                                                                                                                                        // Initial solution vector

    /*15.38x1+5.79x2+1.83x3+2.06x4+2.53x56.44x1+14.87x2+3.22x3+2.68x4+7.33x55.17x1+1.80x2+12.08x3+5.9x4+0.59x51.01x1+0.58x2+5.16x3+15.85x4+2.42x51.84x1+4.2x2+1.18x3+4.46x4+15.63x5=====61.34105.3582.31107.15126.23*/

    jacobi(a, b, x, N);

    printf("Solution:\n");
    for (int i = 0; i < N; i++)
    {
        printf("x[%d] = %0.3f\n", i, x[i]);
    }

    return 0;
}