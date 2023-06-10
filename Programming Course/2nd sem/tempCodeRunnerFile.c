#include <stdio.h>

long long convertBin(int decimal);

int main () {
    int dec;
    long long bin;

    printf("Enter decimal number: ");
    scanf("%d", &dec);
    convertBin(dec);

    return 0;
}
long long convertBin(int decimal) {
    long long binary[50];
    int size = 0;
    int i = 0;

    while (decimal) {
        binary[i] = decimal % 2;
        decimal /= 2;
        size++;
        i++;
    }

    printf("Binary: ");
    for (int i = 0; i < size; i++) {
        printf("%lld", binary[i]);
    }
}