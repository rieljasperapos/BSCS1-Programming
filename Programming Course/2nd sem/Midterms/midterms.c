#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//Arrays and Pointers

// int bubbSort(int num[], int size);

// int main() {
//     int size;

//     printf("Enter size of the array: ");
//     scanf("%d", &size);

//     int num[size];

//     for (int i = 0; i < size; i++) {
//         printf("Enter index %d: ", i);
//         scanf("%d", &num[i]);
//     }

//     bubbSort(num, size);

//     printf("Sorted Array of numbers:\n");
//     for(int i = 0; i < size; i++) {
//         printf("Index %d: %d\n", i, num[i]);
//     }

//     return 0;
// }
// int bubbSort(int num[], int size) {
//     for (int i = 0; i < size; i++) {
//         for (int j = 0; j < size - i - 1; j++) {
//             if (num[j] > num[j+1]) 
//             {
//                 int temp = num[j];
//                 num[j] = num[j+1];
//                 num[j+1] = temp;
//             }
//         }
//     }
//     return *num;
// }

//bubble sorting strings
#define MAX 50
void bubbSort(char string[], int size);

int main() {
    int size;
    
    printf("Enter how many strings: ");
    scanf("%d", &size);

    char string[size][MAX];

    for (int i = 0; i < size; i++) {
        printf("Print %d string: ", i+1);
        scanf("%s\n", &string[i]);
    }

    bubbSort(string, size);

    //sorted string
    for (int i = 0; i < size; i++) {
        printf("string[%d]: %s\n", i, string[i]);
    }

    return 0;
}
void bubbSort(char string[], int size) {
    char tmp[MAX];
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size - i - 1; j++) {
            if (strcmp(string[j], string[j+1]) > 0)
            {
                strcpy(tmp, string[j]);
                strcpy(string[j], string[j+1]);
                strcpy(string[j+1], tmp);
            }
        }
    }
}

