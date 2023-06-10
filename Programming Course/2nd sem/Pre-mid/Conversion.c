// #include <stdio.h>
// #include <math.h>

// int convertDec(long long n);

// int main() {
//     long long n;

//     printf("Enter a binary number: ");
//     scanf("%lld", &n);
//     printf("Binary: %lld\nDecimal: %d", n, convertDec(n));

//     return 0;
// }
// int convertDec(long long n) {
//     int decimal = 0, rem, i = 0;

//     while(n) {
//         rem = n % 10;
//         n /= 10;
//         decimal += rem * pow(2,i);
//         i++;
//     }

//     return decimal;
// }

// #include <stdio.h>

// long long convertBin(int decimal);

// int main () {
//     int dec;
//     long long bin;

//     printf("Enter decimal number: ");
//     scanf("%d", &dec);
//     convertBin(dec);

//     return 0;
// }
// long long convertBin(int decimal) {
//     long long binary[50];
//     int size = 0;
//     int i = 0;

//     while (decimal) {
//         binary[i] = decimal % 2;
//         decimal /= 2;
//         size++;
//         i++;
//     }

//     printf("Binary: ");
//     for (int i = 0; i < size; i++) {
//         printf("%lld", binary[i]);
//     }
// }

// decimal to binary

// #include <stdio.h>

// long long convertBin (int decimal);

// int main() {
//     int decimal;

//     printf("Enter a decimal number: ");
//     scanf("%d", &decimal);

//     convertBin(decimal);

//     return 0;
// }
// long long convertBin (int decimal) {
//     long long binary[50];
//     long long *pointer;
//     int size = 0, i = 0;

//     pointer = binary;

//     while (decimal) {
//         *(pointer + i) = decimal % 2;
//         decimal /= 2;
//         i++;
//         size++;
//     }

//     printf("Binary: ");
//     for (int i = 0; i < size; i++) {
//         printf("%lld", *(pointer + i));
//     }
// }

#include <stdio.h>
#include <stdlib.h>

long long convertBinary(int decimal);
void displayBin(long long *binary, int count);

int main() {
    int decimal, n;
    // long long *bin;

    scanf("%d", &n);

    for (int i = 0; i < n; i++) {
        scanf("%d", &decimal);
        convertBinary(decimal);
    }
    
    return 0;
}
long long convertBinary(int decimal) {
    long long *bin;
    int count = 0, size = 0;

    bin = (long long*)malloc(100*sizeof(long long));

    for (int i = 0; decimal != 0; i++) {
        *(bin+i) = decimal % 2;
        decimal /= 2;
        count++;
    }
    size = count - 1;
    while (size >= 0) {
        printf("%lld", *(bin+size));
        size--;
    }
    //return bin;
}
