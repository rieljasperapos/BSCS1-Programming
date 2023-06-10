#include <stdio.h>
#include <stdlib.h>

int main() {
    int n, i, j, count;
    int *numbers, num;

    printf("Number of elements: ");
    scanf("%d", &n);

    
    numbers = (int*)calloc(n, sizeof(int));
    //int array[1000] = {0};
    
    if (n >= 1 && n <= 1000) {
        for (i = 0; i < n; i++)
        {
            scanf("%d", numbers + i);
            //array[*(numbers + i)]++;
        }
    }
    //printf("\n\n%d\n\n", numbers[11]);

    //int array[100] = {0};

    //for (int i = 0; i < 1000; i++) {
      //  if (array[i] != 0)
    //    printf("%d ", array[i]);
   // }


    for(int i = 0; i < n; i++) {
        printf("array[%d]: %d", i, numbers[i]);
    }
    for (i = 0; i < n; i++) {
        num = numbers[i];
        count = 1;
        for (j = i+1; j < n; j++) {
            if (numbers[j] == num)
            {
                //array[numbers[j]]++;
                count++;
        
            }
        }
        printf("Number %d repeats %d times\n", numbers[i], count); 
    }
    return 0;

}