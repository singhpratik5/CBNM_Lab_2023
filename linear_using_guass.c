#include <stdio.h>
#include <stdlib.h>

int main() {
    int n, i, j, k;
    printf("Enter the number of data points: ");
    scanf("%d", &n);
    float x[n], y[n], a[2][3], m, c;
    printf("Enter the data points:\n");
    for (i = 0; i < n; i++) {
        scanf("%f %f", &x[i], &y[i]);
    }
    a[0][0] = n;
    for (i = 0; i < n; i++) {
        a[0][1] += x[i];
        a[0][2] += y[i];
        a[1][0] += x[i];
        a[1][1] += x[i] * x[i];
        a[1][2] += x[i] * y[i];
    }
    for (i = 0; i < 2; i++) {
        for (j = 0; j < 3; j++) {
            printf("%f ", a[i][j]);
        }
        printf("\n");
    }
    for (i = 0; i < 2; i++) {
        for (j = i + 1; j < 2; j++) {
            m = a[j][i] / a[i][i];
            for (k = i; k < 3; k++) {
                a[j][k] -= m * a[i][k];
            }
        }
    }
    c = a[1][2] / a[1][1];
    m = (a[0][2] - a[0][1] * c) / a[0][0];
    printf("The equation of the line is y = %fx + %f\n", m, c);
    return 0;
}
