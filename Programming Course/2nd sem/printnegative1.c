#include <stdio.h>

int main() {
    int store[100];
    int *pointer;
    pointer = store;

    while (pointer < &store[100]) {
        *pointer = -1;
        printf("%d\n", *pointer);
        pointer++;
    }

}
