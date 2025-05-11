#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

int main() 
{
    float num = 1000000064.0;
    uint32_t *ptr = (uint32_t *)&num;
    uint32_t bits = *ptr;
    int sign = (bits >> 31) & 1;
    int exponent = (bits >> 23) & 0xff;
    int mantissa = bits & 0x7fffff;
    printf("Sign bit: %d\n", sign);
    printf("Exponent: ");
    for (int i = 7; i >= 0; i--) {
        printf("%d", (exponent >> i) & 1);
    }
    printf("\n");
    printf("Mantissa: 1.");
    for (int i = 22; i >= 0; i--) {
        printf("%d", (mantissa >> i) & 1);
    }
    printf("\n");
    return 0;
}
