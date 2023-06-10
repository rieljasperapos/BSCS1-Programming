#include <stdio.h>
#include <string.h>

int main() {
    int n;

    scanf("%d", &n);

    char string[n][50];
    char temp[50];

    for (int i = 0; i < n; i++) {
        scanf("%s\n", string[i]);
    }
     //bubble sort
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (strcmp(string[j], string[j+1]) > 0)
            {
                strcpy(temp, string[j+1]);
                strcpy(string[j+1], string[j]);
                strcpy(string[j], temp);
            }
        }
    }

    for (int i = 0; i < n; i++) {
        printf("%s\n", string[i]);
    }

    return 0;
}