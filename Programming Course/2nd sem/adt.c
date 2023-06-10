#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#define MAX 10

typedef struct {
	float value[MAX];
	int count;
} LIST;

void inicialize_list(LIST *list)
{
	list->count = 0;	
}

print_list(LIST *list)
{
	int i;
	
	for(i=0;i<list->count;i++){
		printf("%f ",list->value[i]);
	}
	printf("\n");
}

list_insert(LIST *list,int position,float value)
{
	//check if list is not full
	//position == 0 - insert first
	//position == -1 - insert last
	//position == n - n-th position
	//position == count - insert last
	//position > count - do not insert 	

    if (position == MAX) { //checks if the list is full
        printf("The list is full.\n");
		return;
    }

    if (position > list->count) {
        printf("Position cannot be found.\n");
		return;
    } 

    if (position == - 1 || position == list->count) { //if pos == -1 and pos == count insert in last
        list->value[list->count] = value;
        list->count++;
		return;
    }

	if (position == 0) {
		memmove(&list->value[1], &list->value[0], sizeof(float) * list->count);
		list->value[0] = value;
		list->count++; 
	}


	// if (position >= 0 && position < list->count) { //insert in nth position
	// 	memmove(list->value + position + 1, list->value + position, (list->count - position) * sizeof(float));
	// 	list->value[position] = value;
	// 	list->count++;
	// 	return;
	// }
    
}

list_delete(LIST *list,int position)
{
	//check if list is not empty
	//position == 0 - delete first
	//position == -1 - delete last
	//position == n - n-th position
	//position > count-1 - do not delete anything 	
    if (position == MAX) {
        printf("List is full.\n");
    }
    
    if (position > list->count -1) { 
        printf("Postion is invalid.\n");
    }

    if (position == -1) { //delete last
        list->count--;
        return;
    }

	if (position == 0) { //delete first
		memmove(list->value, list->value + 1, (list->count - 1) * sizeof(float));
		list->count--;
		return;
	}

	// if (position > 0 && position < list->count - 1) { //delete at nth position
	// 	memmove(list->value + position, list->value + position + 1, (list->count - position - 1) * sizeof(float));
	// 	list->count--;
	// 	return;
	// }


}

float list_average(LIST *list)
{
	//count average of values in the list
	//return it as return value
	float sum = 0;
	int i;

	if (list->count == 0) {
		printf("No list found");
		return;
	}

	for (i = 0; i < list->count; i++) {
		sum += list->value[i];
	}

	return sum / list->count;

	
}

LIST list_round(LIST list,int decimal_places)
{
	//round each element of list to num of decimal_places
	//e.g. decimal_places == 2 -> 123.45678 -> 123.46
	//e.g. decimal_places == 0 -> 123.45678 -> 123
	//return as another list
	LIST rounded_list;
	inicialize_list(&rounded_list);
	int i;

	for (i = 0; i < list.count; i++) {
		float value = list.value[i];
		float rounded_value = roundf(value * powf(10, decimal_places)) / powf(10, decimal_places);
		rounded_list.value[i] = rounded_value;
		rounded_list.count++;
	}

	return rounded_list;
	
}

int main(void)
{
	LIST list1;
	inicialize_list(&list1);
	float average;		

	list_insert(&list1, 0, 2.5);
	list_insert(&list1, 1, 1);
	list_insert(&list1, 2, 11);
	list_insert(&list1, 3, 12);
	list_insert(&list1, 4, 15);

	print_list(&list1); //before deleting

	average = list_average(&list1); // average
	printf("Average of the values inside the list: %f\n", average);

	// print_list(&list1); //original list
	LIST rounded_list = list_round(list1, 2);

	print_list(&rounded_list); //rounded list


	list_delete(&list1, 0);
	print_list(&list1); // after deleting
}
	