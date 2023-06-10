#include <stdio.h>

int main() {
    int store[100];
    int *pointer;
    pointer = store;
    int i = 1;

    while (pointer < &store[100]) {
        *pointer = -1;
        printf("%d: %d\n", i, *pointer);
        pointer++;
        i++;
    }

}
