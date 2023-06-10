//intro to typedef and struct keywords
#include <stdio.h>
#define MAX 50
typedef struct
{
    int id;
    char name[MAX];
    char class[MAX];
}student;

int main() {
    student stud[5];

    for (int i = 0; i < 3; i++) {
        printf("Student %d name: ", i+1);
        scanf("%s", &stud[i].name);
        printf("student %d id: ", i+1);
        scanf("%d", &stud[i].id);
        printf("Student %d class: ", i+1);
        scanf("%s\n", &stud[i].class);
    }

    for (int i = 0; i < 3; i++) {
        printf("\nStudent #%d name: %s, id: %d, class: %s", i+1, stud[i].name, stud[i].id, stud[i].class);
    }

    return 0;

}