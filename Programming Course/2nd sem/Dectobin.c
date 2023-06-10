#include <stdio.h>
#include <stdlib.h>

long long convertBinary(int decimal);

int main() {
    int decimal, n;
    long long *bin;

    scanf("%d", &n);

    bin = (long long*)calloc(n, sizeof(long long));

    for (int i = 0; i < n; i++) {
        scanf("%d", &decimal);
        *bin = convertBinary(decimal);
    }
    for (int i = 0; i < n; i++) {
        printf("%lld", bin[i]);
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
    // size = count - 1;
    // while (size >= 0) {
    //     printf("%lld", *(bin+size));
    //     size--;
    // }
    return *bin;
}