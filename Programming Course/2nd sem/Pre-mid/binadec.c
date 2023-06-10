#include <stdio.h>
#include <string.h>
#include <math.h>

unsigned long long binaryToDecimal(char binary[]);

int main() {
    char binary[100];
    unsigned long long decimal;
    int i, num;
    
    printf("Enter how many numbers to convert: ");
    scanf("%d", &num);

    if (num >= 1 && num <= 1000) {
        for (i = 0; i < num; i++) {
            scanf("%s", binary);
            decimal = binaryToDecimal(binary);
            printf("%llu\n", decimal);
        }
    }

    return 0;
}

unsigned long long binaryToDecimal(char binary[]) {
    unsigned long long decimal = 0;
    int len = strlen(binary);
    int i;

    for (i = 0; i < len; i++) {
        if (binary[i] == '1') {
            decimal += pow(2, len - 1 - i);
        }
    }

    return decimal;
}