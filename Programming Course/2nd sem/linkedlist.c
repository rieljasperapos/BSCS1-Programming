#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    char name[30];
    int age;
    int idNum;
}Student, *StudPTR;

typedef struct node{
	Student student;
	struct node *next;
} *LIST;

LIST NewNode()
{
	LIST new_node;
	
	new_node = (LIST) malloc(sizeof(LIST));
	if (new_node == NULL){
		printf("Can not allocate the memory!\n");
		exit(1);
	}
	
	return new_node;
}

void DeleteFirst(LIST *list) {
	LIST temp;
	if (*list == NULL) {
		printf("list is empty");
	}

	temp = *list;
	*list = (*list)->next;
	free(temp);

}

void DeleteLast(LIST *list) {
	LIST temp, temp2;
	if (*list == NULL) {
		printf("list is empty");
	}

	temp = *list;
	temp2 = NULL;

	while (temp->next != NULL) {
		temp2 = temp;
		temp = temp->next;
	}

	if (temp2 == NULL) {
		*list = NULL;
	} else {
		temp2->next = NULL;
	}

	free(temp);
}


void insertStruct(LIST *list, Student student) {
    LIST new_node, *temp;
    new_node = NewNode();

	new_node->student = student;
    new_node->next = NULL;

    temp = list;
    while(*temp != NULL) {
        temp = &(*temp)->next;
    }

    *temp = new_node;
}

void PrintList(LIST list)
{
    LIST temp;
    for(temp = list; temp != NULL; temp = temp->next) {
        printf("Name: %s, Age: %d, ID: %d\n", temp->student.name, temp->student.age, temp->student.idNum);
    }
    printf("\n");
}


int main(void)
{
	LIST myList = NULL;

    Student student1;
	strcpy(student1.name, "Alice");
	student1.age = 19;
	student1.idNum = 123;
    insertStruct(&myList, student1);

	Student student2;
	strcpy(student2.name, "Bob");
	student2.age = 20;
	student2.idNum = 321;
    insertStruct(&myList, student2);


    // Student student2 = {"Bob", 21, 456};
    // insertStruct(&myList, student2);

    // printf("Before Deletion\n");
    // PrintList(myList); // Before Deletion

	// DeleteFirst(&myList);
	// DeleteLast(&myList);

    // printf("After Deletion\n");
	PrintList(myList);
	
	return 0;
}