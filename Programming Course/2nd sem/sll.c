#include <stdio.h>
#include <stdlib.h>

struct node{
	int value;
	struct node *next;	
};

struct node *start=NULL;

struct node *sll_new_node()
{
	struct node *new_node;
	
	new_node = (struct node *)malloc(sizeof(struct node));
	if (new_node == NULL){
		printf("Out of Memory\n");
		exit(1);
	}
	
	return new_node;
}

void sll_insert_first(int value)
{
	struct node *new_node;	
	new_node = sll_new_node();
	
	new_node->value = value;
	new_node->next = start;
	start = new_node;
}

void sll_insert_last(int value)
{
	struct node *new_node, *temp;	
	new_node = sll_new_node();
	
	new_node->value = value;
	new_node->next = NULL;
	
	if (start == NULL){
		start = new_node;
		return;	
	}
	
	temp = start;
	while (temp->next != NULL){
		temp = temp->next;
	}
	temp->next = new_node;
}

void sll_insert_at(int position,int value)
{
	struct node *new_node, *temp;	
	int i=0;	
	
	if (position==0 || start==NULL){
		sll_insert_first(value);
		return;
	}
	
	new_node = sll_new_node();
	new_node->value = value;
	
	temp = start;
	while (temp->next != NULL){
		if (i==position-1){
			new_node->next = temp->next;
			temp->next = new_node;
			return;
		}
		temp = temp->next;
		i++;
	}
	
	temp->next = new_node;
	new_node->next = NULL;
}



void sll_delete_first()
{
	struct node *temp;	

	if (start == NULL){
		printf("List is empty\n");
		return;
	}

	temp = start;
	start = start->next;
	free(temp);
}


void sll_delete_last()
{
	struct node *temp, *temp2;	
	
	if (start == NULL){
		printf("List is empty\n");
		return;
	}
	
	temp = start;
	while (temp->next != NULL){
		temp2 = temp;
		temp = temp->next;
	}
	
	if (temp == start){
		start = NULL;
		free(temp);	
		return;
	}
	
	temp2->next = NULL;
	free(temp);
}

void sll_print_at(int position)
{
	struct node *temp;
	int i=0;	
	
	temp = start;
	while (temp != NULL){
		if (i==position){
			printf("%d\n",temp->value);
			return;
		}
		temp = temp->next;
		i++;
	}
}

void sll_delete_at(int position)
{
    struct node *temp, *prev;
    int i = 0;
    
    if (start == NULL) {
        printf("There is no list found");
    }

    temp = start;
    prev = NULL;

    while (temp != NULL) {
        if (i == position) {
            if (prev == NULL){
                start = temp->next;
            } else {
                prev->next = temp->next;
            }
            free(temp);
            return;
        }
        prev = temp;
        temp = temp->next;
        i++;
    }

    printf("Position is not in the list\n");
}

void sll_print_list()
{
	struct node *temp;	

	temp = start;
	while (temp != NULL){
		printf("%d ",temp->value);
		temp = temp->next;
	}
	printf("\n");
}


int main(void)
{
	sll_insert_first(10);
	sll_insert_first(20);
	sll_insert_first(30);
	sll_insert_first(40);
	
	sll_print_list();
	
	sll_insert_last(50);
	sll_insert_last(60);
	sll_insert_last(70);
	
	sll_print_list();
	
	sll_delete_first();
	sll_print_list();
	sll_delete_last();
	sll_print_list();
	
	sll_print_at(3);

    sll_delete_at(10);
	
	sll_insert_at(4,29);
	sll_insert_at(10,59);
	sll_print_list();
	
	return 0;	
}
