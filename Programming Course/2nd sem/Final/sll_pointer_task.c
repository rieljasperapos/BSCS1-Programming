#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

typedef struct node{
	int value;
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

void InsertLast(LIST *list,int value)
{
	LIST new_node, *temp;
	new_node = NewNode();
	
	new_node->value = value;
	new_node->next = NULL;
	
//	for(temp=list;*temp!=NULL;temp=&(*temp)->next){}

	temp = list;
	while(*temp != NULL) {
		temp = &(*temp)->next;
	}
	
	*temp = new_node;	
}

void InsertFirst(LIST *list, int value)
{
	LIST new_node, *temp;
	new_node = NewNode();
	temp = list;
	
	new_node->value = value;
	new_node->next = *temp;
	
	*temp = new_node;
	
}

void InsertList(LIST *list, int value, int position)
{
	// position == 0 - insert first
	// position == -1 - insert last
	// position == n - nth position
	// DO NOT USE FUNCTIONS InsertFirst, InsertLast
	LIST new_node, *temp;
	int i = 0;
	
	new_node = NewNode();
	temp = list;
	
	if (position < 0) {
		position = INT_MAX;
	}
	
//	i = 0;
	for (temp = list; *temp != NULL && i < position; temp = &(*temp)->next) {
		i++;
	}
	
	new_node->value = value;
	new_node->next = *temp;
	
	*temp = new_node;

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


void PrintList(LIST list)
{
	LIST temp;
	for(temp = list; temp != NULL; temp = temp->next){
		printf("%d ",temp->value);
	}
	printf("\n");
}


int main(void)
{
	LIST myList = NULL;

	InsertLast(&myList,7);
	InsertLast(&myList,10);
	InsertLast(&myList,5);
	InsertLast(&myList,76);
	InsertFirst(&myList, 69);
	InsertList(&myList, 70, 5);

	DeleteFirst(&myList);
	DeleteLast(&myList);

	PrintList(myList);
	
	return 0;
}
