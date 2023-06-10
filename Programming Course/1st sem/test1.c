#include <stdio.h>

int* input_values(int arr[], int size) {
    for (int i = 0; i < size; i++) {
        scanf("%d ", &arr[i]);
    }
    return arr;

}

void main() {
    int size = 10;
    int a[size];
    int *ptr;

    //*(a + 1) = 10;

    // get values input
    printf("Enter elements: ");
    ptr = input_values(a, size);
    
    for (int i = 0; i < size; i++) {
        printf("%d ", *(a + i));
    }

    
}