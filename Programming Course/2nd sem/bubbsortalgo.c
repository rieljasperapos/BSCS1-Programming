#include <stdio.h>

void bubbSort(int arr[], int size);

int main() {
    int n;

    scanf("%d", &n);

    int arrayNum[n];

    if (n >= 1 && n <= 500) {
        for (int i = 0; i < n; i++) {
            scanf("%d", &arrayNum[i]);
        }
    }
    //sort ascending order
    bubbSort(arrayNum, n);

    printf("\n");
    for (int i = 0; i < n; i++) {
        printf("%d\n", arrayNum[i]);
    }

    return 0;
}
// optimized version of sorting but still not an efficient sorting algo
void bubbSort(int arrayNum[], int size) {
    int temp, swapped;

    for (int i = 0; i < size; i++) {
        swapped = 0; /* tracker if any swaps were made */
        for(int j = i+1; j < size; j++) {
            if (arrayNum[i] > arrayNum[j])
            {
                temp = arrayNum[i];
                arrayNum[i] = arrayNum[j];
                arrayNum[j] = temp;
                swapped = 1;
            }
        }
        if (swapped == 0) { /*process terminates if no changes found*/
            return;
        }
    }

}