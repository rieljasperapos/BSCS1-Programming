#include<stdio.h>

int *get_factors(int list[], int count, int value, int* ret_count);
void display(int list[], int count);

int main(void) {
    int numbers, n, value, totalFactors;
    int *factors;

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

    factors = get_factors(arr, n, value, &totalFactors);
    printf("The factors of %d present in the collection: ", );
    display();

    return 0;
}

int *get_factors(int list[], int count, int value, int* ret_count) {
    // Hey there, start typing your C code here...

    for (int i = 0; i < count; i++) {
        if (value % list[i] == 0) {
            printf("%d", list[i]);
        }
    }
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