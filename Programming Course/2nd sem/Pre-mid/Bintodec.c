#include <stdio.h>
#include <string.h>
#include <math.h>

unsigned long long convertToDec(unsigned long long bin);

int main() {
    int numInput;
    unsigned long long bin;

    scanf("%d", &numInput);

    if (numInput >= 1 && numInput <= 1000) {
        for (int i = 0; i < numInput; i++) {
            scanf("%llu", &bin);
            printf("%llu\n", convertToDec(bin));
        }
    }

    return 0;
}
unsigned long long convertToDec(unsigned long long bin) { 
    unsigned long long rem;
    unsigned long long decimal = 0;
    int i = 0;

    while (bin > 0) {
        rem = bin % 10;
        bin /= 10;
        decimal += rem * pow(2,i);
        i++;
    }

    return decimal;
}