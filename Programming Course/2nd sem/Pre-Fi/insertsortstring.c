#include <stdio.h>
#include <string.h>

void insertSort(char store[], int size);

int main() {
    int n;
    char pos[50];
    scanf("%d", &n);

    char string[n][50];

    for (int i = 0; i < n; i++) {
        scanf("%s", string[i]);
    }

    for (int i = 1; i < n; i++) {
        strcpy(pos, string[i]);
        int j = i - 1;
        while (j >= 0 && strcmp(string[j], pos) > 0) {
            strcpy(string[j+1], string[j]);
            j--;
        }
        strcpy(string[j+1], pos);
    }

    for(int i = 0; i < n; i++) {
        printf("%s\n", string[i]);
    }

    return 0;
}