#include <stdio.h>
#include <stdlib.h> //library for memory allocations
#include <strings.h> //will be using string functions

/* struct declarations */
struct gps {
    float longitude;
    float latitude;
};

struct mapElement {
    char name[100];
    char type[50];
    int size;
    struct gps location;
};
//function to set the map element
void setMapElement (char name[], char type[], int size, float longitude, float latitude);
//function to print all
void printAll();

//global declaration to be accessed anywhere
struct mapElement *elem;
int num_of_elem = 0;

int main() {
    elem = (struct mapElement*)malloc(sizeof(struct mapElement) * 100);
    

    return 0;
}
void setMapElement(char name[], char type[], int size, float longitude, float latitude) {
    strcpy(elem[num_of_elem].name, "USC");
    strcpy(elem[num_of_elem].type, "school");
    elem[num_of_elem].size = 800000;
    elem[num_of_elem].location.longitude = 10.12345;
    elem[num_of_elem].location.latitude = 123.45678;
    num_of_elem++;
}
void printAll() {
    for (int i = 0; i < num_of_elem; i++) {
        printf("%s\n", elem[num_of_elem].name);
        printf("%s\n", elem[num_of_elem].type);
        printf("%d\n", elem[num_of_elem].size);
        printf("%.2f\n", elem[num_of_elem].location.longitude);
        printf("%,2f", elem[num_of_elem].location.latitude);
    }
}

