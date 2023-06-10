#include <stdio.h>
#include <stdlib.h>

int main() {
    int n, i, j, count;
    int *numbers, num, *frequency;

    scanf("%d", &n);

    numbers = (int*)malloc(n*sizeof(int));

    if (n >= 1 && n <= 1000) {
        for (i = 0; i < n; i++)
        {
            scanf("%d", numbers + i);
        }
    }

    frequency = (int*)calloc(n, sizeof(int));
    int isVisited = -1;

    for ( i = 0; i < n; i++) {
        count = 1;
        for ( j = i+1; j < n; j++) {
            if (numbers[i] == numbers[j])
            {
                count++;
                frequency[j] = isVisited;
            }
        }
        if (frequency[i] != isVisited)
        {
            frequency[i] = count;
        }
    }

    for (i = 0; i < n; i++) {
        if (frequency[i] != isVisited)
        {
            printf("Number %d repeats %d times\n", numbers[i], frequency[i]);
        }
    }
    return 0;

}