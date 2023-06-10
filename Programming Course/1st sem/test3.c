#include<stdio.h>
#include <stdlib.h>
/*
int *get_factors(int list[], int count, int value, int* ret_count);
void display(int list[], int count);

int main(void) {
    // Hey there, start typing your C code here...
    int numbers, n, value, total_factors, *factors;

    printf("How many numbers? ");
    scanf("%d", &numbers);

    n = numbers;

    int arr[n];
    for (int i = 0; i < n; i++) {
        printf("Enter the number %d: ", i+1);
        scanf("%d", &arr[i]);
    }

    printf("Enter the value: ");
    scanf("%d", &value);

    printf("The collection: ");
    display(arr, n);

    factors = get_factors(arr, n, value, &total_factors);
    display(factors, total_factors);

    return 0;
}

int *get_factors(int list[], int count, int value, int* ret_count) {
    // Hey there, start typing your C code here...
    int temp[count], ctr = 0, *factor_list;

    for (int i = 0; i < count; i++) {
        if (value % list[i] == 0) {
            temp[ctr++] = list[i]; 
        }
    }

    factor_list = malloc(ctr*sizeof(int));

    for (int i = 0; i < ctr; i++) {
        factor_list[i] = temp[i];
    }

    *ret_count = ctr;
    return factor_list;
}
void display(int list[], int count) {
    printf("{");
    for(int i = 0; i < count; ++i) {
        printf("%d", list[i]);
        if(i < count - 1) {
            printf(", ");
        }
    }
    printf("}\n");
}
*/

#define max 50
void main() {
    char *name, *nPtr;

    printf("Enter a string: ");
    scanf("%s", name);

    nPtr = name;

    for (int i = 0; nPtr != '\0'; i++) {
        if (*nPtr + i >= 'a' && *nPtr + i <= 'z') {
            printf("%c is lowercase\n", *nPtr);
        } else if (*nPtr + i >= 'A' && *nPtr + i <= 'Z') {
            printf("%c is uppercase\n", *nPtr);
        } else {
            printf("%c is not a letter");
        }
    }
    

    
}
